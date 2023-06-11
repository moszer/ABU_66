#include "hidjoystickrptparser.h"
extern int bit1;
extern int bit2;
extern int bit3;
extern int bit4;
extern int bit5;

JoystickReportParser::JoystickReportParser(JoystickEvents *evt) :
joyEvents(evt),
oldHat(0xDE),
oldButtons(0) {
        for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++)
                oldPad[i] = 0xD;
}

void JoystickReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
        bool match = true;

        // Checking if there are changes in report since the method was last called
        for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++)
                if (buf[i] != oldPad[i]) {
                        match = false;
                        break;
                }

        // Calling Game Pad event handler
        if (!match && joyEvents) {
                joyEvents->OnGamePadChanged((const GamePadEventData*)buf);

                for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++) oldPad[i] = buf[i];
        }

        uint8_t hat = (buf[5] & 0xF);

        // Calling Hat Switch event handler
        if (hat != oldHat && joyEvents) {
                joyEvents->OnHatSwitch(hat);
                oldHat = hat;
        }

        uint16_t buttons = (0x0000 | buf[6]);
        buttons <<= 4;
        buttons |= (buf[5] >> 4);
        uint16_t changes = (buttons ^ oldButtons);

        // Calling Button Event Handler for every button changed
        if (changes) {
                for (uint8_t i = 0; i < 0x0C; i++) {
                        uint16_t mask = (0x0001 << i);

                        if (((mask & changes) > 0) && joyEvents) {
                                if ((buttons & mask) > 0)
                                        joyEvents->OnButtonDn(i + 1);
                                else
                                        joyEvents->OnButtonUp(i + 1);
                        }
                }
                oldButtons = buttons;
        }
}

void JoystickEvents::OnGamePadChanged(const GamePadEventData *evt) {
        Serial.print("X1: ");
        PrintHex<uint8_t > (evt->X, 0x80);
        Serial.print("\tY1: ");
        PrintHex<uint8_t > (evt->Y, 0x80);
        Serial.print("\tX2: ");
        PrintHex<uint8_t > (evt->Z1, 0x80);
        Serial.print("\tY2: ");
        PrintHex<uint8_t > (evt->Z2, 0x80);
        Serial.print("\tRz: ");
        PrintHex<uint8_t > (evt->Rz, 0x80);
        Serial.println("");
}


//set bit
void setBIT(int state1, int state2, int state3, int state4, int state5) {
  digitalWrite(bit1, state1);
  digitalWrite(bit2, state2);
  digitalWrite(bit3, state3);
  digitalWrite(bit4, state4);
  digitalWrite(bit5, state5);

     // Concatenate the state values into a single string
  String stateString = String(state1) + String(state2) + String(state3) + String(state4) + String(state5);
  
  Serial.println(stateString);
}


void JoystickEvents::OnHatSwitch(uint8_t hat) {
        //Serial.print("Hat Switch: ");
        //PrintHex<uint8_t > (hat, 0x80);

        if(hat == 00){
          Serial.println("Forward"); //1
          setBIT(0,0,0,0,1);
         }
        if(hat == 02){
          Serial.println("Right");//3
          setBIT(0,0,0,1,1);
         }
        if(hat == 06){
          Serial.println("Left");//5
          setBIT(0,0,1,0,1);
         }
        if(hat == 04){
          Serial.println("Down");//7
          setBIT(0,0,1,1,1);
         }

         if(hat != 00 && hat != 02 && hat != 06 && hat != 04){
            setBIT(0,0,0,0,0);
          }
}

void JoystickEvents::OnButtonUp(uint8_t but_id) {
        //Serial.print("Up: ");
        //Serial.println(but_id, DEC);

        if(but_id == 1 or but_id == 2 or but_id == 3 or but_id == 4 or but_id == 5 or but_id == 6 or but_id == 7 or but_id == 8){
            setBIT(0,0,0,0,0);
          }
}

void JoystickEvents::OnButtonDn(uint8_t but_id) {
        //Serial.print("Dn: ");
        //Serial.println(but_id, DEC);
        if(but_id == 4){
          Serial.println("Y_on");//17
          setBIT(1,0,0,0,1);
        }
        if(but_id == 1){
          Serial.println("X_on");//18
          setBIT(1,0,0,1,0);
        }
        if(but_id == 3){
          Serial.println("B_on");//19
          setBIT(1,0,0,1,1);
        }
        if(but_id == 2){
          Serial.println("A_on");//20
          setBIT(1,0,1,0,0);
        }
        if(but_id == 6){
          Serial.println("RB_on");//21
          setBIT(1,0,1,0,1);
        }
        if(but_id == 8){
          Serial.println("RT_on");//22
          setBIT(1,0,1,1,0);
        }
        if(but_id == 5){
          Serial.println("LB_on");//23
          setBIT(1,0,1,1,1);
        }
        if(but_id == 7){
          Serial.println("LT_on");//24
          setBIT(1,1,0,0,0);
        }
        
}
