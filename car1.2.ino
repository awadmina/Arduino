int LIRSensor1 = 4; // connect ir sensor 1 left side
int RIRSensor2 = 2; // connect ir sensor 2 right side
const int ENABLE = 7; //enable
const int ENABLE2 = 8; //enable
const int ENR1 = 12; //Engine right 1
const int ENR2 = 11; //Engine right 2
const int ENL1 = 10; //Engine left 1
const int ENL2 = 9; //Engine left2
 
void setup()
{
  //IR sensor
  pinMode (LIRSensor1, INPUT); // sensor pin INPUT
  pinMode (RIRSensor2, INPUT); // sensor pin INPUT
  Serial.begin(9600); // open the serial port at 9600 bps:
 
   //wheels
  pinMode(ENABLE, OUTPUT);
  pinMode(ENABLE2, OUTPUT);
  //wheels right
  pinMode(ENR2, OUTPUT);
  pinMode(ENR1, OUTPUT);
  //wheels left
  pinMode(ENL2, OUTPUT);
  pinMode(ENL1, OUTPUT);
 
}
 
void loop()
{
 
  //IR sensor
  int statusSensor1 = digitalRead (LIRSensor1);
  int statusSensor2 = digitalRead (RIRSensor2);
  analogWrite(ENABLE, 100); //0-255
  analogWrite(ENABLE2, 100);
  //digitalWrite(ENABLE, HIGH);
  //digitalWrite(ENABLE2, HIGH);
   
  if (statusSensor1 == 1 && statusSensor2 == 1){
    Serial.print("HIGH-No Obstacle/Black Surface\n");
    Serial.print("HIGH-No Obstacle/Black Surface\n");
  
    digitalWrite(ENR1, HIGH);
    digitalWrite(ENR2, LOW);
    digitalWrite(ENL1, HIGH);
    digitalWrite(ENL2, LOW);
  }else if (statusSensor1 == 1 && statusSensor2 == 0){
    Serial.print("turn LEFT\n");
    digitalWrite(ENR1, HIGH);
    digitalWrite(ENR2, LOW);
    digitalWrite(ENL1, LOW);
    digitalWrite(ENL2, LOW);
  
  }else if(statusSensor1 == 0 && statusSensor2 == 1){
    Serial.print("turn RIGHT\n");
    digitalWrite(ENR1, LOW);
    digitalWrite(ENR2, LOW);
    digitalWrite(ENL1, HIGH);
    digitalWrite(ENL2, LOW);
   
  } else if (statusSensor1 == 0 && statusSensor2 == 0){
    Serial.print("error not reading any white light\n");
    digitalWrite(ENR1, HIGH);
    digitalWrite(ENR2, LOW);
    digitalWrite(ENL1, HIGH);
    digitalWrite(ENL2, LOW);
  } else {
    Serial.print("something is wring\n");
    digitalWrite(ENR1, LOW);
    digitalWrite(ENR2, LOW);
    digitalWrite(ENL1, LOW);
    digitalWrite(ENL2, LOW);
  }
  delay(1000);
}
 
