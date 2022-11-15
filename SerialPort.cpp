#include "SerialPort.h"

SerialPort::SerialPort(char* devicename,int baudrate)
{
    deviceName=devicename;
    baudRate=baudrate;
}

SerialPort::~SerialPort()
{

}
/**
 * This function sets serial port options.
*/
void SerialPort::initialize(){
    // Clear all the size bits
    tty.c_cflag&=~CSIZE;
    // Clear stop field only one stop bit is used
    tty.c_cflag&=~CSTOPB;
    // Number of bits per byte is 8
    tty.c_cflag&=~CS8;
    // Disable RTS/CTS hardware flow control 
    tty.c_cflag&=~CRTSCTS;
    // Disable canonical mode
    tty.c_lflag &= ~ICANON;
    // Disable Echo
    tty.c_lflag &= ~ECHO;
    // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    // Set baud rate
    cfsetispeed(&tty, baudRate);
    cfsetospeed(&tty, baudRate);
    // Open port
    serial_port = open(deviceName, O_RDWR);
}
/**
 * This function take message as a paramater and writes to port
*/
void SerialPort::writeData(char msg[]){
    write(serial_port, msg, sizeof(msg));
}
