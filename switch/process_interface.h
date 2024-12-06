#pragma once

#include <vector>

class ProcessInterface{
private:
    float wait_time_;
    std::vector<int> input_pins_;
    void PrintVector(std::vector<int> input);

public:
    ProcessInterface(std::vector<int> input_pins);
    void Run();
    void DumpProfile();
};