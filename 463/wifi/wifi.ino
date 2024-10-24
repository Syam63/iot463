#include<WiFi.h>
#include "FirebaseESP32.h"
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
FirebaseData firebaseData;
 float val=0.0;
 String tag="IOTLAB/MY_App/Sensor_Value";
void setup() {
  Serial.begin(115200);
  WiFiInit();
  FirebaseInit();
}

void loop() {
  FirebaseWrite();
  Serial.println(val);
  val=val+1.54;
  if(val>10.0) val=0.0;
 delay(700);
}
void WiFiInit(){
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP:");
  Serial.println(WiFi.localIP());
  Serial.println();
}
void FirebaseInit(){
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectedWiFI(true);
}
void FirebaseWrite(){
  Firebase.setFloat(firebaseData,tag,val);
}
