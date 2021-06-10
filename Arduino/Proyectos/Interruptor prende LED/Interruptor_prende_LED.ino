const int pinSwitch=2; 
const int pinLed=13;

void setup() {
  pinMode(pinSwitch,INPUT);
  pinMode(pinLed,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pinSwitch)==HIGH){
    digitalWrite(pinLed,HIGH);      
  }
  else{
    digitalWrite(pinLed,LOW);      
  }
  Serial.println(digitalRead(pinSwitch));
  delay(250);  
}
