#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

#include "hidjoystickrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

//setbit pin
int bit1 = 7;
int bit2 = 6;
int bit3 = 5;
int bit4 = 4;
int bit5 = 3;

void setup() {
        //setpin OUT
        pinMode(bit1, OUTPUT);
        pinMode(bit2, OUTPUT);
        pinMode(bit3, OUTPUT);
        pinMode(bit4, OUTPUT);
        pinMode(bit5, OUTPUT);
          
          Serial.begin(115200);
#if !defined(__MIPSEL__)
        while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
        Serial.println("Start");

        if (Usb.Init() == -1)
                Serial.println("OSC did not start.");

        delay(200);

        if (!Hid.SetReportParser(0, &Joy))
                ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
}


void loop() {
        Usb.Task();
}
