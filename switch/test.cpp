#include <iostream>
#include <vector>

#include "switch/process_interface.h"

// cp bazel-bin/switch/test bin/test

int main() {
    constexpr int input_pin_1 = 7;
    constexpr int input_pin_2 = 8;
    constexpr int input_pin_3 = 9;

    ProcessInterface process1({input_pin_1, input_pin_2, input_pin_3});
    process1.DumpProfile();
    process1.Run();
    return 0; 
}