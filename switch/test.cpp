#include <iostream>
#include <vector>

#include "switch/process_interface.h"

// cp bazel-bin/switch/test bin/test

int main() {
    constexpr int input_pin_1 = 4;
    constexpr int input_pin_2 = 5;
    constexpr int input_pin_3 = 6;

    ProcessInterface process1({input_pin_1, input_pin_2, input_pin_3});
    process1.DumpProfile();
    process1.Run();
    return 0; 
}