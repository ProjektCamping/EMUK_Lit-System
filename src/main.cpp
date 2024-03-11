#include <Arduino.h>
#include "Table.h"

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"


#define HELP_Button1 27
#define HELP_Button2 26

// To Chage to
// Replace with your network credentials
const char* ssid = "HomeKit";
const char* password = "CZH-D21-206-HHA38";

AsyncWebServer server(80);
String processor(const String& var);

// Set LED GPIO
const int ledPin = 12;
// Stores LED state
String ledState;



// put function declarations here:
Table T;
short drivingTime = 100 ; //ms global Var to drive Stems 


void setup() {
  Serial.begin(115200);
  Serial.write("Here I am");
  // put your setup code here, to run once:
 
  pinMode(HELP_Button1, INPUT_PULLUP);
  pinMode(HELP_Button2, INPUT_PULLUP);



  //WIFI + Server
  pinMode(ledPin, OUTPUT);

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }


  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });


  // Route to set GPIO to HIGH
  server.on("/LF_UP", HTTP_GET, [](AsyncWebServerRequest *request){
  T.driveStemUP4(FrontLeft,drivingTime);

    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to set GPIO to LOW
  server.on("/LF_DOWN", HTTP_GET, [](AsyncWebServerRequest *request){
    T.driveStemDOWN4(FrontLeft,drivingTime);
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Route to set GPIO to HIGH
  server.on("/RF_UP", HTTP_GET, [](AsyncWebServerRequest *request){
    T.driveStemUP4(FrontRight,drivingTime);
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to set GPIO to LOW
  server.on("/RF_DOWN", HTTP_GET, [](AsyncWebServerRequest *request){
   T.driveStemDOWN4(FrontRight,drivingTime); 
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Route to set GPIO to HIGH
  server.on("/LB_UP", HTTP_GET, [](AsyncWebServerRequest *request){
    T.driveStemUP4(BackLeft,drivingTime);
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to set GPIO to LOW
  server.on("/LB_DOWN", HTTP_GET, [](AsyncWebServerRequest *request){
  T.driveStemDOWN4(BackLeft,drivingTime);
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Route to set GPIO to HIGH
  server.on("/RB_UP", HTTP_GET, [](AsyncWebServerRequest *request){
  T.driveStemUP4(BackRight,drivingTime);
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to set GPIO to LOW
  server.on("/RB_DOWN", HTTP_GET, [](AsyncWebServerRequest *request){
    T.driveStemDOWN4(BackRight,drivingTime); 
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Start server
  server.begin();

}

void loop() {
  int buttonState1 = digitalRead(HELP_Button1);
  int buttonState2 = digitalRead(HELP_Button2);
  if(!buttonState1){
    T.driveAllUP(1000);
  }
  
  if(!buttonState2){
    T.driveAllDOWN(1000);
  }
}

/**
 * WIFI + Server
 * 
 */

String processor(const String& var){
  Serial.println(var);
  if(var == "STATE"){
    if(digitalRead(ledPin)){
      ledState = "ON";
    }
    else{
      ledState = "OFF";
    }
    Serial.print(ledState);
    return ledState;
  }
  return String();
}