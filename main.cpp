#include "SerialPort.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int main(){
    SerialPort sp("/dev/ttyUSB0",9600);
    sp.initialize();
    
    time_t localTime;
    struct tm * timeinfo;

    while (true)
    {
        time(&localTime);
        timeinfo=localtime (&localTime);
        printf(asctime(timeinfo));
        sp.writeData(asctime(timeinfo));
        sleep(1);
    }

}