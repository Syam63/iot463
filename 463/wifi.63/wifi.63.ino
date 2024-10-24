  #include<WiFi.h>
#include"FirebaseESP32.h"
#define FIREBASE_HOST "iot63-8b5d7-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "49OtvW2ZaghUWfVYYbj4T3XlyB19uV7cDLn7xjjn"
#define WIFI_SSID "Nothing Phone(2a)5G"
#define WIFI_PASSWORD "9705991317"
FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;
float val = 0.0;
String tag = "IOTLAB/My_App/Sensor_Value";
void setup(){
  Serial.begin(115200);
  WiFiInit();
  FirebaseInit();
}
void loop(){
  FirebaseWrite();
  Serial.println(val);
  val= val + 1.54;
  if(val > 10.0) val = 0.0;
  delay(1000);
}
void WiFiInit(){
 WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 Serial.print("connecting to wi-fi");
 while (WiFi.status() !=WL_CONNECTED);
 {
  Serial.print(".");
  delay(300);
 }
Serial.println();
Serial.print("connected with IP:");
Serial.println(WiFi.localIP());
Serial.println();
 }
void FirebaseInit(){
    firebaseConfig.host = FIREBASE_HOST;
    firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;
    Firebase.begin(&firebaseConfig,&firebaseAuth);
    Firebase.reconnectWiFi(true);
}
void FirebaseWrite(){
  Firebase.setFloat(firebaseData, tag, val);
}
