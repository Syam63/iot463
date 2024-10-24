#include<WiFi.h>
#include "FirebaseESP32.h"
#define FIREBASE_HOST "https://iot63-8b5d7-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "49OtvW2ZaghUWfVYYbj4T3XlyB19uV7cDLn7xjjn"
#define WIFI_SSID "Nothing Phone(2a)5G"
#define WIFI_PASSWORD "9705991317"
FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;
const int Pir=33;
String mystring;
String tag="Firebase/Pir";
void setup() {
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  firebaseConfig.host = FIREBASE_HOST;
firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;
    Firebase.begin(&firebaseConfig,&firebaseAuth);
    Firebase.reconnectWiFi(true);
  pinMode(Pir,INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
int sw=digitalRead(Pir);
if(sw==1)
mystring="detected";
else
mystring="not detected";
}
Serial.Println(mystring);
Firebase.setString(firebaseData,tag,mystring);
delay(100);
}
