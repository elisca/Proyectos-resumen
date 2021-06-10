const int analogInPin = A0; 
 
int sensorValue = 0;
 
void setup() {
 Serial.begin(9600); 
}
 
void loop() {
 sensorValue = analogRead(analogInPin); 
 
 Serial.print("Sensor cubierto = " ); 
 Serial.print(sensorValue*100/1024); 
 Serial.println("%");
 Serial.println(sensorValue);
 if(sensorValue>0){
  Serial.println("Agua detectada");  
 }
 else{
  Serial.println("Agua no detectada");  
 }
 
 delay(1000); 
}
