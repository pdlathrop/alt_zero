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

ProcessInterface::ProcessInterface(std::vector<int> input_pins){
    input_pins_ = input_pins;
    wait_time_ = 0;
}

void ProcessInterface::Run(){
    bool continue_running = true;
    constexpr double wait_duration = 0.1;
    constexpr double wait_threshold = 10.0;
    bool pin_1_input = false;

    while(continue_running){
        //TODO
        pin_1_input = true;
        if(pin_1_input){

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

