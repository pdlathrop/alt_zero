#ifndef MOCK_PIGPIO_H
#define MOCK_PIGPIO_H

inline int gpioInitialise() { return 0; }
inline void gpioTerminate() {}
inline void gpioSetMode(int, int) {}
inline void gpioWrite(int, int) {}
inline int gpioRead(int) { return 0; }

#endif