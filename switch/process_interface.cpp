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
    constexpr double wait_threshold = 5.0;
    if(gpioInitialise() < 0){
        std::cerr << "Gpio initialization failed. " << std::endl;
        return;
    }
    if(input_pins_.empty()){
        std::cerr << "Input pins empty. " << std::endl;
    }
    gpioSetMode(input_pins_[0], PI_INPUT);

    // Main loop.
    while(continue_running){
        // Read pins.
        int main_pin_state = gpioRead(input_pins_[0]);
        if(main_pin_state == 1){

        }
        std::cout << "wait time: " << wait_time_ << " \n";

        std::this_thread::sleep_for(std::chrono::duration<double>(wait_duration));
        wait_time_ += wait_duration;
        if(wait_time_ > wait_threshold){
            continue_running = false;
        }
    }
}

void ProcessInterface::DumpProfile(){
    std::cout << "Start DumpProfile, wait_time: " << wait_time_ << "\n";
    PrintVector(input_pins_, "input_pins_");
}

void ProcessInterface::PrintVector(std::vector<int> input, std::string name){
    std::cout << name << ": ";
    for(int elem:input){
        std::cout << elem << ", ";
    }
    std::cout << "end " << "\n";
}

