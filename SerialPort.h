#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <iostream>

class SerialPort
{
    char* deviceName;
    int baudRate;
    struct termios tty;
    int serial_port;
public:
    SerialPort(char* devicename,int baudrate);
    ~SerialPort();
    void initialize();
    void writeData(char msg[]);
private:

};

#endif