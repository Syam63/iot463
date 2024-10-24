
void setup()
{
 pinMode(16,INPUT-PULLUP);
 Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(16)==HIGH)

  Serial.println("open");
else
 Serial.println("close");
delay(2000);
}
