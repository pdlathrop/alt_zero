#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "switch/process_interface.h"

#ifdef __APPLE__
#include "mock_pigpio.h"
#else
#include <pigpio.h>
#endif

ProcessInterface::ProcessInterface(std::vector<int> input_pins): input_pins_(input_pins){
    wait_time_ = 0;
}

void ProcessInterface::Run(){
    // Initializations.
    bool continue_running = true;
    constexpr double wait_duration = 0.1;
    constexpr double wait_threshold = 100.0;
    if(gpioInitialise() < 0){
        std::cerr << "Gpio initialization failed. " << std::endl;
        return;
    }
    if(input_pins_.empty()){
        std::cerr << "Input pins empty. " << std::endl;
    }
    SetInputPins(input_pins_);

    // Main loop.
    while(continue_running){
        // Read pins.
        int main_pin_state = gpioRead(input_pins_[0]);
        if(main_pin_state == 0){
            std::cout << "main switch thrown" << std::endl;
            ProcessGPIO1(input_pins_[1]);
        }
        std::cout << "wait time: " << wait_time_ << " \n" << "main pin state = " << main_pin_state << std::endl;

        std::this_thread::sleep_for(std::chrono::duration<double>(wait_duration));
        wait_time_ += wait_duration;
        if(wait_time_ > wait_threshold){
            continue_running = false;
        }
    }
    return;
}

void ProcessInterface::SetInputPins(std::vector<int> pins) const{
    //for(auto pin: pins){
    int pin = pins[0];
        gpioSetMode(pin, PI_INPUT);
        gpioSetPullUpDown(pin, PI_PUD_UP);
    //}
    return;
}

void ProcessInterface::ProcessGPIO1(int input_pin){
    int pin_state = gpioRead(input_pin);
    if(pin_state == 0){
        if(wait_time_ - toggle_1_mem_ >= toggle_1_cooldown_){
            std::cout << "toggle switch 2 thrown and cooldown satisfied: wait_time_ = " << wait_time_ << "toggle_1_mem_ = " << toggle_1_mem_ << std::endl; 
        }
        toggle_1_mem_ = wait_time_;
    }
    return;
}

void ProcessInterface::DumpProfile() const{
    std::cout << "Start DumpProfile, wait_time: " << wait_time_ << "\n";
    PrintVector(input_pins_, "input_pins_");
}

void ProcessInterface::PrintVector(std::vector<int> input, std::string name) const{
    std::cout << name << ": ";
    for(int elem:input){
        std::cout << elem << ", ";
    }
    std::cout << "end " << "\n";
}

