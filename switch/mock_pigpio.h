#ifndef MOCK_PIGPIO_H
#define MOCK_PIGPIO_H

#include <iostream>

// GPIO Modes
#define PI_INPUT  0 // Pin is an input
#define PI_OUTPUT 1 // Pin is an output

// Pull-Up/Down States
#define PI_PUD_OFF  0 // No pull-up or pull-down
#define PI_PUD_DOWN 1 // Pull-down resistor enabled
#define PI_PUD_UP   2 // Pull-up resistor enabled

// Mock implementations of pigpio functions
inline int gpioInitialise() {
    std::cout << "Mock: Initializing pigpio." << std::endl;
    return 0; // Return 0 to indicate success
}

inline void gpioTerminate() {
    std::cout << "Mock: Terminating pigpio." << std::endl;
}

inline void gpioSetMode(int pin, int mode) {
    std::cout << "Mock: Setting pin " << pin << " mode to " << mode << "." << std::endl;
}

inline void gpioSetPullUpDown(int pin, int pud) {
    std::cout << "Mock: Setting pin " << pin << " pull state to " << pud << "." << std::endl;
}

inline void gpioWrite(int pin, int value) {
    std::cout << "Mock: Writing " << value << " to pin " << pin << "." << std::endl;
}

inline int gpioRead(int pin) {
    std::cout << "Mock: Reading from pin " << pin << "." << std::endl;
    return 0; // Mock return value (LOW)
}

inline void gpioDelay(unsigned int microseconds) {
    std::cout << "Mock: Delaying for " << microseconds << " microseconds." << std::endl;
}

#endif // MOCK_PIGPIO_H