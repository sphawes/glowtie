//GlowTie Firmware v0.2
//Stephen Hawes 2018
//TOOLS:
//Stringify HTML file:
//http://davidjwatts.com/youtube/esp8266/esp-convertHTM.html#
//Reference for sending data between site and server
//https://bitbucket.org/Remnis/neopixelwebserver/src/0ae6ce3b2122?at=master

#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include "FS.h"


#define PIN            12
#define NUMPIXELS      13

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

ADC_MODE(ADC_VCC);

const char *ssid = "Glowtie";
const char *password = "pleaseletmein";

ESP8266WebServer server(80);

int const battCacheSize = 30;
int battCachePosition = 0;
int battCache[battCacheSize] = {3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300,3300};
int summedCache = 99000;
float avgBatt = 3300;
int newBatt = 0;

int delayVal = 8; 
int btMode = 0;
int rVal = 0;
int gVal = 100;
int bVal = 100;
int brightness = 50;
int checkBattTimer = 0;

int ba = 0;
int bb = 0;
int bc = 0;
int bd = 0;
int bi = 0;

int pa = 0;
int pi = 0;

int ii = 0;

unsigned long prevMillis = millis();

void setup() {
  delay(1000);
  Serial.begin(115200);

  SPIFFS.begin();
  
  Serial.print("Creating Glowtie netowork...");
  if(WiFi.softAP(ssid, password)){
    Serial.println("Successfully started access point.");
  }
  else{
    Serial.println("Could not start access point.");
  }
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("IP address: ");
  Serial.println(myIP);

  server.on("/", handleRoot);
  server.begin(); 
  
  pixels.begin();
  for(int i=0; i<100; i++){
    updateAvgBatt();
    delay(2);
    Serial.print("Polling ");
    Serial.print(i);
    Serial.println(" out of 100 for battery charge.");
  }
  if(avgBatt <= 3100){
    btMode = 1;
    Serial.println("Battery low, going into low battery mode.");
  }
  else{
    for(int j = 0;j<300;j++){
      burst(20,20,20);
      delay(5);
    }
    btMode = 0;
  }
  checkBattTimer = millis();
}



void loop() {
  yield();
  server.handleClient();
  //Serial.println(millis());
  
  if(millis() >= checkBattTimer + 10000){
    updateAvgBatt();
    if(avgBatt <= 3100){
      btMode = 1;
    }
    checkBattTimer = millis();
  }
  
  if(btMode == 0){
    //stanby mode
    off();
    
    pixels.show();
  }

  else if(btMode == 1){
    //low battery mode
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.setPixelColor(6, pixels.Color(50, 0, 0));
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));
    pixels.setPixelColor(12, pixels.Color(0, 0, 0));
    
    pixels.show();
    
  }

  else if(btMode == 2){
    //solid color mode
    pixels.setPixelColor(0, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(1, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(2, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(3, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(4, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(5, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(6, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(7, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(8, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(9, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(10, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(11, pixels.Color(rVal, gVal, bVal));
    pixels.setPixelColor(12, pixels.Color(rVal, gVal, bVal));
    
    pixels.show();
    
  }

  else if(btMode == 3){
    bi = 0;
    if(millis() > prevMillis + 70){
      //Infinity Mode
      prevMillis = millis();
      infin(rVal, gVal, bVal);
      
    }
  }
  
  else if(btMode == 4){
    if(millis() > prevMillis + 7) {
      //pulse mode
      prevMillis = millis();
      pulse(rVal, gVal, bVal);
      
    }
  }
  
  else if(btMode == 5){
    if(millis() > prevMillis + 10) {
      //Burst mode
      prevMillis = millis();
      burst(rVal, gVal, bVal);
      
    }
  }
  
}

void handleRoot(){
  Serial.println("Client connected");
  Serial.println("Killing LEDS to handle HTTP request:");
  off();
  pixels.show();
  
//  Serial.println(getContentType("/index.html"));

  //Serial.println(SPIFFS.exist("/index.html"));

  //Serial.println("opening spiffs file");
  //File f = SPIFFS.open("/index.html", "r");
  
  //Serial.println("streaming spiffs file");
  //server.streamFile(f, "text/html");

  //Serial.println("closing the file");
  // f.close();

  
  
  Serial.println("creating html string variable");
  String html ="<!DOCTYPE html> <html> <head> <title>Glowtie</title> <style> body { background-color: #000000; font-family: \"Helvetica\"; color: #ffffff; } .slider{ width:90%; } #colorUpdate{ background-color: black; width:200px; height:40px; margin:auto; text-align: center; padding:20px; border-radius: 10px; } </style> <meta name=\"viewport\" content=\"width=device-width, height=device-height, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0\" /> <script> //alert(\"inline js working in spiffs\"); function updateColor(){ document.getElementById(\"colorUpdate\").style.backgroundColor = document.forms['settings'].color.value; } </script> </head> <body> <h1 id=\"colorUpdate\">Glowtie</h1> <form action=\"\" name=\"settings\" id=\"settings\" method=\"post\"> <input type=\"color\" name=\"color\" style=\"text-align: center;\" onchange=\"updateColor()\"> <br /> <input type=\"radio\" name=\"mode\" value=\"0\"> Off<br /> <input type=\"radio\" name=\"mode\" value=\"2\"> Solid<br /> <input type=\"radio\" name=\"mode\" value=\"3\"> Infinity<br /> <input type=\"radio\" name=\"mode\" value=\"4\"> Breathe<br /> <input type=\"radio\" name=\"mode\" value=\"5\"> Burst <br /> <button onclick=\"document.forms['settings'].submit()\" type=\"button\">Send to Glowtie!</button> </form> </body> </html>";

  Serial.println("sending html string");
  server.send(200,"text/html", html);

  Serial.println("erasing html string to save memory");
  html = "";
  
  Serial.println("pulling out color variables");
  
  String color = server.arg("color");
  int number = (int) strtol( &color[1], NULL, 16);
  int r = number >> 16;
  int g = number >> 8 & 0xFF;
  int b = number & 0xFF;
  
  String btModeS = server.arg("mode");
  btMode = btModeS.toInt();
  Serial.println("printing mode and color values");
  Serial.print("Mode: ");
  Serial.println(btModeS);
  
  Serial.println("Dividing color value by 2.54 because DAMN this shit is bright.");
  int red = r/2.54;
  int green = g/2.54;
  int blue = b/2.54;
  
  Serial.println("Color: ");
  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);

  Serial.println("assigning variable to global color variable");
  rVal = red;
  gVal = green;
  bVal = blue;
  Serial.println("finished with server handle function");

  
}

void updateAvgBatt(){
  newBatt = ESP.getVcc();
  summedCache = summedCache - battCache[battCachePosition];
  summedCache = summedCache + newBatt;
  battCache[battCachePosition] = newBatt;
  
  if(battCachePosition == (battCacheSize - 1)){
    battCachePosition = 0;
  }
  else{
    battCachePosition++;
  }
  avgBatt = summedCache / battCacheSize;
  
}

void off(){
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  pixels.setPixelColor(4, pixels.Color(0, 0, 0));
  pixels.setPixelColor(5, pixels.Color(0, 0, 0));
  pixels.setPixelColor(6, pixels.Color(0, 0, 0));
  pixels.setPixelColor(7, pixels.Color(0, 0, 0));
  pixels.setPixelColor(8, pixels.Color(0, 0, 0));
  pixels.setPixelColor(9, pixels.Color(0, 0, 0));
  pixels.setPixelColor(10, pixels.Color(0, 0, 0));
  pixels.setPixelColor(11, pixels.Color(0, 0, 0));
  pixels.setPixelColor(12, pixels.Color(0, 0, 0));
}

void burst(int red, int green, int blue){
  if(bi>=300){
    bi=0;
  }

  // a column
  if(bi<=50){
    ba = ba + 1;
  }
  if(bi>50 && ba>0){
    ba = ba - 1;
  }

  // b column
  if(bi>=25 && bi<=75){
    bb = bb + 1;
  }
  if(bi>75 && bb>0){
    bb = bb - 1;
  }

  //c column
  if(bi>=50 && bi<=100){
    bc = bc + 1;
  }
  if(bi>100 && bc>0){
    bc = bc - 1;
  }

  //d column
  if(bi>=75 && bi<=125){
    bd = bd + 1;
  }
  if(bi>125 && bd>0){
    bd = bd - 1;
  }

  float fA = float(ba);
  float fB = float(bb);
  float fC = float(bc);
  float fD = float(bd);
  
  pixels.setPixelColor(6, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  
  pixels.setPixelColor(5, pixels.Color(fB/50*red, fB/50*green, fB/50*blue));
  pixels.setPixelColor(0, pixels.Color(fB/50*red, fB/50*green, fB/50*blue));
  pixels.setPixelColor(7, pixels.Color(fB/50*red, fB/50*green, fB/50*blue));
  pixels.setPixelColor(12, pixels.Color(fB/50*red, fB/50*green, fB/50*blue));
  
  pixels.setPixelColor(1, pixels.Color(fC/50*red, fC/50*green, fC/50*blue));
  pixels.setPixelColor(4, pixels.Color(fC/50*red, fC/50*green, fC/50*blue));
  pixels.setPixelColor(8, pixels.Color(fC/50*red, fC/50*green, fC/50*blue));
  pixels.setPixelColor(11, pixels.Color(fC/50*red, fC/50*green, fC/50*blue));

  pixels.setPixelColor(2, pixels.Color(fD/50*red, fD/50*green, fD/50*blue));
  pixels.setPixelColor(3, pixels.Color(fD/50*red, fD/50*green, fD/50*blue));
  pixels.setPixelColor(9, pixels.Color(fD/50*red, fD/50*green, fD/50*blue));
  pixels.setPixelColor(10, pixels.Color(fD/50*red, fD/50*green, fD/50*blue));
  
  pixels.show();
  bi = bi + 1;
}

void pulse(int red, int green, int blue){
  if(pi>=200){
    pi=0;
  }

  // a column
  if(pi<=50){
    pa = pa + 1;
  }
  if(pi>50 && pa>0){
    pa = pa - 1;
  }


  float fA = float(pa);
  
  pixels.setPixelColor(6, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  
  pixels.setPixelColor(5, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(0, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(7, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(12, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  
  pixels.setPixelColor(1, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(4, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(8, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(11, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));

  pixels.setPixelColor(2, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(3, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(9, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  pixels.setPixelColor(10, pixels.Color(fA/50*red, fA/50*green, fA/50*blue));
  
  pixels.show();
  pi = pi + 1;
}

void infin(int red, int green, int blue){

  if(ii == 0){
    pixels.setPixelColor(6, pixels.Color(0,0,0));
    pixels.setPixelColor(0, pixels.Color(red, green, blue));
    pixels.show();
  }
  else if(ii == 1){
    pixels.setPixelColor(1, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  else if(ii == 2){
    pixels.setPixelColor(2, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(1, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 3){
    pixels.setPixelColor(3, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(2, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 4){
    pixels.setPixelColor(4, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(3, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 5){
    pixels.setPixelColor(5, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(4, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 6){
    pixels.setPixelColor(6, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(5, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 7){
    pixels.setPixelColor(12, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(6, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 8){
    pixels.setPixelColor(11, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(12, pixels.Color(0,0,0));
    pixels.show(); 
  }
  else if(ii == 9){
    pixels.setPixelColor(10, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(11, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 10){
    pixels.setPixelColor(9, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(10, pixels.Color(0,0,0));
    pixels.show(); 
  }
  else if(ii == 11){
    pixels.setPixelColor(8, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(9, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 12){
    pixels.setPixelColor(7, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(8, pixels.Color(0,0,0));
    pixels.show();
  }
  else if(ii == 13){
    pixels.setPixelColor(6, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.setPixelColor(7, pixels.Color(0,0,0));
    pixels.show();
  }


  if(ii > 12){
    ii = 0;
  }
  else{
    ii = ii + 1;
  }
  
}


