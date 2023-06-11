int in1 = 13; //M1
int in2 = 12;
int speeds1 = 11;

int in3 = 10; //M2
int in4 = 9;
int speeds2 = 8;

int in5 = 7; //M3
int in6 = 6;
int speeds3 = 5;

int in7 = 22; //M4
int in8 = 24;
int speeds4 = 26;

int in9 = 29;
int in10 = 30;
int speeds5 = 31;

int in11 = 34;
int in12 = 35;
int speeds6 = 36;

//downup
int in13 = 16;
int in14 = 17;

//roll of rope
int in15 = 18;
int in16 = 19;

int in17 = 20;
int in18 = 21;

int bit1 = 31;
int bit2 = 33;
int bit3 = 35;
int bit4 = 37;
int bit5 = 39;

void setup() {
  //SetpinMOde motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(speeds1, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(speeds2, OUTPUT);

  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(speeds3, OUTPUT);

  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  pinMode(speeds4, OUTPUT);

  pinMode(in9, OUTPUT);
  pinMode(in10, OUTPUT);
  pinMode(speeds5, OUTPUT);

  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);
  pinMode(speeds6, OUTPUT);

  pinMode(in13, OUTPUT);
  pinMode(in14, OUTPUT);

  pinMode(in15, OUTPUT);
  pinMode(in16, OUTPUT);

  pinMode(in17, OUTPUT);
  pinMode(in18, OUTPUT);
  
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
  if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 0 && Bvalue5 == 1){
      setMotor(in1, in2, speeds1, HIGH, LOW, 255);
      setMotor(in3, in4, speeds2, HIGH, LOW, 255);
      setMotor(in5, in6, speeds3, HIGH, LOW, 255);
      setMotor(in7, in8, speeds4, HIGH, LOW, 255);
      Serial.println("FORWARD");
      delay(100);
    } else {
      setMotor(in1, in2, speeds1, LOW, LOW, 0);
      setMotor(in3, in4, speeds2, LOW, LOW, 0);
      setMotor(in5, in6, speeds3, LOW, LOW, 0);
      setMotor(in7, in8, speeds4, LOW, LOW, 0);
    }
   //right
   if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 0 && Bvalue5 == 1){
      setMotor(in1, in2, speeds1, LOW, HIGH, 255); //backward
      setMotor(in3, in4, speeds2, HIGH, LOW, 255); //forward
      setMotor(in5, in6, speeds3, LOW, HIGH, 255); //backward
      setMotor(in7, in8, speeds4, HIGH, LOW, 255); //forward
      Serial.println("TUNRIGHT");
      delay(100);
    } else {
      setMotor(in1, in2, speeds1, LOW, LOW, 0);
      setMotor(in3, in4, speeds2, LOW, LOW, 0);
      setMotor(in5, in6, speeds3, LOW, LOW, 0);
      setMotor(in7, in8, speeds4, LOW, LOW, 0);
    }
    //left
    if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(in1, in2, speeds1, HIGH, LOW, 255); //forward
      setMotor(in3, in4, speeds2, LOW, HIGH, 255); //backward
      setMotor(in5, in6, speeds3, HIGH, LOW, 255); //forward
      setMotor(in7, in8, speeds4, LOW, HIGH, 255); //backward
      Serial.println("TURNLEFT");
      delay(100);
    } else {
      setMotor(in1, in2, speeds1, LOW, LOW, 0);
      setMotor(in3, in4, speeds2, LOW, LOW, 0);
      setMotor(in5, in6, speeds3, LOW, LOW, 0);
      setMotor(in7, in8, speeds4, LOW, LOW, 0);
    }

    //backward
    if(Bvalue1 == 0 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(in1, in2, speeds1, LOW, HIGH, 255); //backward
      setMotor(in3, in4, speeds2, LOW, HIGH, 255); //backward
      setMotor(in5, in6, speeds3, LOW, HIGH, 255); //backward
      setMotor(in7, in8, speeds4, LOW, HIGH, 255); //backward
      Serial.println("BACKWARD");
      delay(100);
    } else {
      setMotor(in1, in2, speeds1, LOW, LOW, 0);
      setMotor(in3, in4, speeds2, LOW, LOW, 0);
      setMotor(in5, in6, speeds3, LOW, LOW, 0);
      setMotor(in7, in8, speeds4, LOW, LOW, 0);
    }

    //shoot
   if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotor(in9, in10, speeds5, LOW, HIGH, 255); //backward
      setMotor(in11, in12, speeds6, LOW, HIGH, 255); //backward
      Serial.println("SHOOT");
      delay(1000);
      setCylinder(in18, HIGH);
      delay(100);
    } else {
       setMotor(in9, in10, speeds5, LOW, LOW, 0); //backward
       setMotor(in11, in12, speeds6, LOW, LOW, 0); //backward
       setCylinder(in18, LOW);
    }
    
    //downup for shoot
    if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 1 && Bvalue5 == 0){
      setMotorRelay(in13, in14, HIGH, LOW);
      Serial.println("DOWN");
      delay(100);
    } else {
       setMotorRelay(in13, in14, HIGH, HIGH);
    }

    if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 1 && Bvalue5 == 1){
      setMotorRelay(in13, in14, LOW, HIGH);
      Serial.println("UP");
      delay(100);
    } else {
       setMotorRelay(in13, in14, HIGH, HIGH);
    }

    //roll of rope
    if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 0 && Bvalue4 == 0 && Bvalue5 == 1){
      setMotorRelay(in15, in16, HIGH, LOW);
      Serial.println("UP");
      delay(100);
    } else {
       setMotorRelay(in15, in16, HIGH, HIGH);
    }
    if(Bvalue1 == 1 && Bvalue2 == 0 && Bvalue3 == 1 && Bvalue4 == 0 && Bvalue5 == 0){
      setMotorRelay(in15, in16, LOW, HIGH);
      Serial.println("DOWN");
      delay(100);
    } else {
       setMotorRelay(in15, in16, HIGH, HIGH);
    }

    //push
    if(Bvalue1 == 1 && Bvalue2 == 1 && Bvalue3 == 0 && Bvalue4 == 0 && Bvalue5 == 0){
      setCylinder(in17, HIGH);
      Serial.println("Cylinder_push");
      delay(100);
    }

    //pull
    if(Bvalue1 == 1 && Bvalue2 == 0&& Bvalue3 == 1&& Bvalue4 == 1&& Bvalue5 == 0){
      setCylinder(in17, LOW);
      Serial.println("Cylinder_push");
      delay(100);
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

void setCylinder(int pin, int signal_){
    digitalWrite(pin, signal_);
  }

//for use relay
void setMotorRelay(int pin1, int pin2, int signal1, int signal2){
    digitalWrite(pin1, signal1);
    digitalWrite(pin2, signal2);
  }

//funtion set motor for use driver and set speed
void setMotor(int pin1, int pin2, int speedPin, int signal1, int signal2, int speeds) {
  digitalWrite(pin1, signal1);
  digitalWrite(pin2, signal2);
  analogWrite(speedPin, speeds);
}
