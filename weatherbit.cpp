/**
* Mary West @ SparkFun Electronics 
* Ryan Mortenson https://github.com/ryanjmortenson
* Harry Fairhead @ IoT-Programmer 
* June 13, 2017
* https://github.com/sparkfun/pxt-weather-bit
*
* Development environment specifics:
* Written in Microsoft PXT
* Tested with a SparkFun weather:bit for micro:bit
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions 
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/


#include "pxt.h"
#include <cstdint>
#include <math.h>

using namespace pxt;


namespace weatherbit {    
	MicroBitPin P12(MICROBIT_ID_IO_P12, MICROBIT_PIN_P12, PIN_CAPABILITY_DIGITAL); 
    MicroBitPin P13(MICROBIT_ID_IO_P13, MICROBIT_PIN_P13, PIN_CAPABILITY_DIGITAL); 

    uint8_t init() {
        P12.setDigitalValue(0);
        for (volatile uint16_t i = 0; i < 600; i++);
        P12.setDigitalValue(1);
        for (volatile uint8_t i = 0; i < 30; i++);
        int b = P13.getDigitalValue();
        for (volatile uint16_t i = 0; i < 600; i++);
        return b;
    }

    void sendZero() {
        P12.setDigitalValue(0);
        for (volatile uint8_t i = 1; i < 75; i++);
        P12.setDigitalValue(1);
        for (volatile uint8_t i = 1; i < 6; i++);
    }

    void sendOne() {
        P12.setDigitalValue(0);
        for (volatile uint8_t i = 1; i < 1; i++);
        P12.setDigitalValue(1);
        for (volatile uint8_t i = 1; i < 80; i++);
    }

    void writeBit(int b) {
        int delay1, delay2;
        if (b == 1) {
            delay1 = 1;
            delay2 = 80;
        } else {
            delay1 = 75;
            delay2 = 6;
        }
        P12.setDigitalValue(0);
        for (uint8_t i = 1; i < delay1; i++);
        P12.setDigitalValue(1);
        for (uint8_t i = 1; i < delay2; i++);
    }

    void sendskip() {
        writeBit(0);
        writeBit(0);
        writeBit(1);
        writeBit(1);
        writeBit(0);
        writeBit(0);
        writeBit(1);
        writeBit(1);
    }

    void writeByte(int byte) {
        int i;
        for (i = 0; i < 8; i++) {
            if (byte & 1) {
                writeBit(1);
            } else {
                writeBit(0);
            }
            byte = byte >> 1;
        }
    }

    int readBit() {
        volatile int i;
        P12.setDigitalValue(0);
        P12.setDigitalValue(1);
        for (i = 1; i < 20; i++);
        int b = P13.getDigitalValue();
        for (i = 1; i < 60; i++);
        return b;
    }

    int convert() {
        volatile int i;
        int j;
        writeByte(0x44);
        for (j = 1; j < 1000; j++) {
            for (i = 1; i < 900; i++) {
        };
        if (readBit() == 1)
            break;
        };
        return (j);
    }

    int readByte() {
        int byte = 0;
        int i;
        for (i = 0; i < 8; i++) {
            byte = byte | readBit() << i;
        };
        return byte;
    }

    //%
    int16_t soilTemp() {
        init();
        writeByte(0xCC);
        convert();
        init();
        writeByte(0xCC);
        writeByte(0xBE);
        int b1 = readByte();
        int b2 = readByte();

        int16_t temp = (b2 << 8 | b1);
        return temp * 100 / 16;
    }


 
}
