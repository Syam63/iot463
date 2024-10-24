const int trigpin=25;
const int echopin=26;
long duration;
int distance;

void setup() {
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(115200);  
}

void loop() {
digitalWrite(trigpin,LOW);
delayMicroseconds(2);

digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=duration*0.034/2;
Serial.print("Distce:");
Serial.println(distance);
delay(100);
}
