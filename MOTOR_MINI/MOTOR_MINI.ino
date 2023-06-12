
//############MOTOR#############//
int pwm1 = 13; //M1  //มอเตอร์ขับเคลื่อน1
int pwm2 = 12;       //มอเตอร์ขับเคลื่อน1

int pwm3 = 10; //M2  //มอเตอร์ขับเคลื่อน2
int pwm4 = 9;        //มอเตอร์ขับเคลื่อน2

int pwm5 = 7; //M3   //มอเตอร์ขับเคลื่อน3
int pwm6 = 6;        //มอเตอร์ขับเคลื่อน3

int pwm7 = 22; //M4  //มอเตอร์ขับเคลื่อน4
int pwm8 = 24;       //มอเตอร์ขับเคลื่อน4

//############SHOOT#############//

int pwm9 = 29;   //มอเตอร์ชูดตัวที่1
int pwm10 = 30;  //มอเตอร์ชูดตัวที่1

int pwm11 = 34;  //มอเตอร์ชูดตัวที่2
int pwm12 = 35;  //มอเตอร์ชูดตัวที่2

//############CYLINDER#############//

//Cylinder of shoot
int in1 = 21; //กระบอกสูบชูด

//############ARM_up_down#############//

int pwm13 = 16; //แขนคล้องห่วง
int pwm14 = 17; //แขนคล้องห่วง

//#############STEPER_MOTOR#############//

int in2 = 1; //ตัวปล่อยห่วงลง
int in3 = 2; //ตัวปล่อยห่วงลง
int in4 = 3; //ตัวปล่อยห่วงลง
int in5 = 4; //ตัวปล่อยห่วงลง

//######################################//

//bit controller
int bit1 = 31;
int bit2 = 33;
int bit3 = 35;
int bit4 = 37;
int bit5 = 39;

void setup() {
  //SetpinMOde motor wheel
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);

  pinMode(pwm5, OUTPUT);
  pinMode(pwm6, OUTPUT);

  pinMode(pwm7, OUTPUT);
  pinMode(pwm8, OUTPUT);

  pinMode(pwm9, OUTPUT);
  pinMode(pwm10, OUTPUT);

  pinMode(pwm11, OUTPUT);
  pinMode(pwm12, OUTPUT);

  //endPin of wheel

  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);

  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  
  Serial.begin(9600);  // Set baud rate to 9600

  //set bit input
  pinMode(bit1, INPUT);
  pinMode(bit2, INPUT);
  pinMode(bit3, INPUT);
  pinMode(bit4, INPUT);
  pinMode(bit5, INPUT);
}

void loop() {

  int Bvalue1 = digitalRead(bit1);
  int Bvalue2 = digitalRead(bit2);
  int Bvalue3 = digitalRead(bit3);
  int Bvalue4 = digitalRead(bit4);
  int Bvalue5 = digitalRead(bit5);
  
  //Forward
  //exam func setMoter(pin1, pin2, pwm1, pwm2);
  if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 0 && Bvalue5 == 1){
      setMotor(pwm1, pwm2, 255, 0);
      setMotor(pwm3, pwm4, 255, 0);
      setMotor(pwm5, pwm6, 255, 0);
      setMotor(pwm7, pwm8, 255, 0);
      Serial.println("FORWARD");
      delay(100);
    } else {
      setMotor(pwm1, pwm2, 0, 0);
      setMotor(pwm3, pwm4, 0, 0);
      setMotor(pwm5, pwm6, 0, 0);
      setMotor(pwm7, pwm8, 0, 0);
    }
   //right
   if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 0 && Bvalue5 == 1){
      setMotor(pwm1, pwm2, 255, 0);
      setMotor(pwm3, pwm4, 255, 0);
      setMotor(pwm5, pwm6, 255, 0);
      setMotor(pwm7, pwm8, 255, 0);
      Serial.println("TUNRIGHT");
      delay(100);
    } else {
      setMotor(pwm1, pwm2, 0, 0);
      setMotor(pwm3, pwm4, 0, 0);
      setMotor(pwm5, pwm6, 0, 0);
      setMotor(pwm7, pwm8, 0, 0);
    }
    //left
    if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(pwm1, pwm2, 255, 0);
      setMotor(pwm3, pwm4, 255, 0);
      setMotor(pwm5, pwm6, 255, 0);
      setMotor(pwm7, pwm8, 255, 0);
      Serial.println("TURNLEFT");
      delay(100);
    } else {
      setMotor(pwm1, pwm2, 0, 0);
      setMotor(pwm3, pwm4, 0, 0);
      setMotor(pwm5, pwm6, 0, 0);
      setMotor(pwm7, pwm8, 0, 0);
    }

    //backward
    if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(pwm1, pwm2, 255, 0);
      setMotor(pwm3, pwm4, 255, 0);
      setMotor(pwm5, pwm6, 255, 0);
      setMotor(pwm7, pwm8, 255, 0);
      Serial.println("BACKWARD");
      delay(100);
    } else {
      setMotor(pwm1, pwm2, 0, 0);
      setMotor(pwm3, pwm4, 0, 0);
      setMotor(pwm5, pwm6, 0, 0);
      setMotor(pwm7, pwm8, 0, 0);
    }

    //shoot
   if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(pwm9, pwm10, 255, 0); //backward
      setMotor(pwm11, pwm12, 255, 0); //backward
      Serial.println("SHOOT");
      delay(1000);
      setCylinder(in1, HIGH);
      delay(100);
    } else {
       setMotor(pwm9, pwm10, 255, 0); //backward
       setMotor(pwm11, pwm12, 255, 0); //backward
       setCylinder(in1, LOW);
    }

    
    //updown_ARM
    if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 0 && Bvalue5 == 1){
      setMotor(pwm1, pwm2, 255, 0);
      Serial.println("DOWN");
      delay(100);
    } else {
            setMotor(pwm1, pwm2, 0, 0);
    }

    if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(pwm1, pwm2, 0, 255);
      Serial.println("UP");
      delay(100);
    } else {
       setMotor(pwm1, pwm2, 0, 0);
    }
    
    Serial.print("DATA: ");
    Serial.print(" ");
    Serial.print(Bvalue1);
    Serial.print(" ");
    Serial.print(Bvalue2);
    Serial.print(" ");
    Serial.print(Bvalue3);
    Serial.print(" ");
    Serial.print(Bvalue4);
    Serial.print(" ");
    Serial.println(Bvalue5);
}

//function set cylinder
void setCylinder(int pin, int signal_){
    digitalWrite(pin, signal_);
  }

//function for use relay
void setMotorRelay(int pin1, int pin2, int signal1, int signal2){
    digitalWrite(pin1, signal1);
    digitalWrite(pin2, signal2);
  }

//function set motor for use driver and set speed
void setMotor(int pwm1, int pwm2, int signal1, int signal2) {
  analogWrite(pwm1, signal1);
  analogWrite(pwm2, signal2);
}
