#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "switch/process_interface.h"

ProcessInterface::ProcessInterface(std::vector<int> input_pins){
    input_pins_ = input_pins;
    wait_time_ = 0;
}

void ProcessInterface::Run(){
    bool continue_running = true;
    constexpr double wait_duration = 0.5;
    constexpr double wait_threshold = 5.0;
    while(continue_running){
        std::this_thread::sleep_for(std::chrono::duration<double>(wait_duration));
        wait_time_ += wait_duration;
        std::cout << "wait time: " << wait_time_ << " \n";
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

