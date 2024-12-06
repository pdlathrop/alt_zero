#include <vector>
#include <iostream>

#include "switch/process_interface.h"

ProcessInterface::ProcessInterface(std::vector<int> input_pins){
    input_pins_ = input_pins;
    wait_time_ = 0;
}

void ProcessInterface::Run(){
    // cal some functions
}

void ProcessInterface::DumpProfile(){
    std::cout << "Start Dump Profile, wait_time: " << wait_time_ << "/n";
    std::cout << "input pins: " << PrintVector(input_pins_);
}

void ProcessInterface::PrintVector(std::vector<int> input){
    
}

