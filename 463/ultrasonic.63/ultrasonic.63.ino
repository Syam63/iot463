#include<WiFi.h>
#include "FirebaseESP32.h"
#define FIREBASE_HOST "iot63-8b5d7-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "49OtvW2ZaghUWfVYYbj4T3XlyB19uV7cDLn7xjjn"
#define WIFI_SSID "Nothing Phone(2a)5G"
#define WIFI_PASSWORD "9705991317"
FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;
float smValue;
String tag="ultrasonic/test_1/distance";
const int trigPin=25;
const int echoPin=26;
long duration;
int distance;
void setup(){
  Serial.begin(115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  WiFiInit();
  FirebaseInit();
}
 void loop(){
  Serial.println("Starting FirebseWrite");
  FirebaseWrite();
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(echoPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  didtance=duration*0.034/2;
  Serial.print("diatance:");
  Serial.println(distance);
  delay(1000);
 }
 void WiFiInit()
 Serial.print("Connecting to WiFi");
 WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 while(WiFi.status()!=WL_CONNECTTED);
 {
  Serial.print(".");
  delay(300);
 }
 Serial.println();
 Serial.print("Connected with IP:");
 Serial.println(WiFi.localIP());
 }
 void FirebaseInit(){
    firebaseConfig.host = FIREBASE_HOST;
    firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;
    Firebase.begin(&firebaseConfig,&firebaseAuth);
    Firebase.reconnectWiFi(true);
    Serial.println("Firebase Initialized");
}
void FirebaseWrite(){
  if(Firebase.ssetFloat(firebaseData,tag,distance))
  {
    Serial.println("Data sent to Firebase successfully:");
    else{
      Serial.print("Error sending data:");
      Serial.println(firbaseData,errorReason());
    }
 
 }
