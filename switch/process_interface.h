#pragma once

#include <vector>

class ProcessInterface{
private:
    float wait_time_;
    const std::vector<int> input_pins_;
    void PrintVector(std::vector<int> input, std::string name);
    void SetInputPins(std::vector<int> pins) const;
    void ExecuteGPIO2(int input_pin);

public:
    ProcessInterface(std::vector<int> input_pins);
    void Run();
    void DumpProfile();
};