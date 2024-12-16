#pragma once

#include <vector>

class ProcessInterface{
private:
    float wait_time_;
    const std::vector<int> input_pins_;
    static constexpr float toggle_1_cooldown_ = 3.0;
    float toggle_1_mem_ = -5;
    void PrintVector(std::vector<int> input, std::string name);
    void SetInputPins(std::vector<int> pins) const;
    void ProcessGPIO1(int input_pin);

public:
    ProcessInterface(std::vector<int> input_pins);
    void Run();
    void DumpProfile();
};