//Glowtie Firmware v1.0
//Stephen Hawes 2018  
//TOOLS:
//Stringify HTML file:
//http://davidjwatts.com/youtube/esp8266/esp-convertHTM.html#
//Reference for sending data between site and server
//https://bitbucket.org/Remnis/neopixelwebserver/src/0ae6ce3b2122?at=master
//https://github.com/jasoncoon/esp8266-fastled-webserver/blob/master/data/index.htm

#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

#define PIN            12
#define NUMPIXELS      13

#define SN "FamousJeans"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

ADC_MODE(ADC_VCC);

const char *ssid = SN;
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
int gVal = 0;
int bVal = 0;
int brightness = 50;
int checkBattTimer = 0;
int prevMode = 0;

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
  Serial.begin(9600); 
  
  pixels.begin(); 

  //storing 4 eeprom values. the 0th is the saved mode, then the 1-3th are r, g, and b values, respectively. 4 bytes per int with 4 ints is 16 bytes:
  EEPROM.begin(512);

  btMode = EEPROM.read(0);
  rVal = EEPROM.read(4);
  gVal = EEPROM.read(8);
  bVal = EEPROM.read(12);

  //CHECKING BATTERY
  
  for(int i=0; i<30; i++){
    updateAvgBatt();
    delay(1);
    Serial.print("Polling ");
    Serial.print(i);
    Serial.println(" out of 100 for battery charge.");
  }
  if(avgBatt <= 3100){
    btMode = 1;
    Serial.println("Battery low, going into low battery mode.");
  }
  
  //Animation
  for(int j = 0;j<300;j++){
      burst(50,20,0);
      delay(10);
  }

  //WIFI JAZZ
  Serial.print("Creating Glowtie netowork...");
  if(WiFi.softAP(ssid)){
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
  
  //END WIFI STUFF
  
  checkBattTimer = millis(); 
   
}



void loop() {
  //yield();
  server.handleClient();
  //Checking battery value
  
  if(millis() >= checkBattTimer + 10000){
    updateAvgBatt();
    if(avgBatt <= 3100){
      btMode = 1;
    }
    checkBattTimer = millis();
  }
  
  
  //OFF MODE
  if(btMode == 0){
    if(prevMode != 0){
      off();
      prevMode = 0;
    }
  }

  //LOW BATTERY MODE
  else if(btMode == 1){
    if(prevMode != 1){
      lowBatt();
      prevMode = 1;
    } 
  }

  //SOLID COLOR MODE
  else if(btMode == 2){
    if(prevMode != 2){
      solid();
      prevMode = 2;
    } 
  }
  
  //INFINITY MODE
  else if(btMode == 3){
    if(prevMode != 3){
      prevMillis = millis() - 71;
      prevMode = 3;
      ii = 0;
    }
    if(millis() > prevMillis + 70){
      prevMillis = millis();
      infin(rVal, gVal, bVal);
    }
  }

  //PULSE MODE
  else if(btMode == 4){
    if(prevMode != 4){
      pi = 0;
      prevMode = 4;
    }
    if(millis() > prevMillis + 7) {
      prevMillis = millis();
      pulse(rVal, gVal, bVal);
    }
  }

  //BURST MODE
  else if(btMode == 5){
    if(prevMode != 5){
      bi = 0;
      prevMode = 5;
    }
    if(millis() > prevMillis + 10) {
      //Burst mode
      prevMillis = millis();
      burst(rVal, gVal, bVal);
    }
  }
}

void handleRoot(){
  //off();

  if(server.args()>0){
    int r = server.arg("red").toInt();
    int g = server.arg("green").toInt();
    int b = server.arg("blue").toInt();
    String btModeS = server.arg("mode");
    btMode = btModeS.toInt();

    int red = r/2;
    int green = g/2;
    int blue = b/2;

    rVal = red;
    gVal = green;
    bVal = blue;

    EEPROM.write(0, btMode);
    EEPROM.write(4, rVal);
    EEPROM.write(8, gVal);
    EEPROM.write(12, bVal);
    EEPROM.commit(); 
  }
  
  //String html ="<!DOCTYPE html> <html> <head> <title>Glowtie</title> <style> body { background-color: #000000; font-family: \"Helvetica\"; color: #ffffff; } .slider{ width:90%; } #colorUpdate{ background-color: black; width:200px; height:40px; margin:auto; text-align: center; padding:20px; border-radius: 10px; } </style> <meta name=\"viewport\" content=\"width=device-width, height=device-height, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0\" /> <script> console.log(\"Inline JS running.\"); function updateColor(){ var red = document.forms['settings'].red.value; var green = document.forms['settings'].green.value; var blue = document.forms['settings'].blue.value; var rgb = blue | (green << 8) | (red << 16); var color = \"#\" + (0x1000000 + rgb).toString(16).slice(1); document.getElementById(\"colorUpdate\").style.backgroundColor = color; } </script> </head> <body> <h1 id=\"colorUpdate\">Glowtie</h1> <form action=\"\" name=\"settings\" id=\"settings\" method=\"post\"> <!--Color: <input class=\"jscolor\" value=\"ffffff\" name=\"color\">--> Red:<br /> <input type=\"range\" class=\"slider\" min=\"0\" max=\"255\" value=\"127\" name=\"red\" onchange=\"updateColor()\"><br /> Green<br /> <input type=\"range\" class=\"slider\" min=\"0\" max=\"255\" value=\"127\" name=\"green\" onchange=\"updateColor()\"><br /> Blue<br /> <input type=\"range\" class=\"slider\" min=\"0\" max=\"255\" value=\"127\" name=\"blue\" onchange=\"updateColor()\"><br /> <input type=\"radio\" name=\"mode\" value=\"0\" checked> Off<br /> <input type=\"radio\" name=\"mode\" value=\"2\"> Solid<br /> <input type=\"radio\" name=\"mode\" value=\"3\"> Infinity<br /> <input type=\"radio\" name=\"mode\" value=\"4\"> Breathe<br /> <input type=\"radio\" name=\"mode\" value=\"5\"> Burst<br /><br /> <button onclick=\"document.forms['settings'].submit()\" type=\"button\">Send to Glowtie!</button> </form> </body> </html>";
  String html ="<!DOCTYPE html> <html> <head> <title>Glowtie</title> <style> body { background-color: #000000; font-family: \"Helvetica\"; color: #ffffff; } .slider { -webkit-appearance: none; /* Override default CSS styles */ appearance: none; width: 100%; /* Full-width */ margin:auto; margin-bottom:40px; margin-top:10px; height: 25px; /* Specified height */ background:black; /* Grey background */ outline: none; /* Remove outline */ opacity: 0.7; /* Set transparency (for mouse-over effects on hover) */ -webkit-transition: .2s; /* 0.2 seconds transition on hover */ transition: opacity .2s; border:3px solid white; } .slider::-webkit-slider-thumb { -webkit-appearance: none; /* Override default look */ appearance: none; width: 50px; /* Set a specific slider handle width */ height: 50px; /* Slider handle height */ background: white; /* Green background */ cursor: pointer; /* Cursor on hover */ border-radius: 5px; border: 1px solid black; } #sliderCont { width:70%; margin:auto; } #colorUpdate{ background-color: black; width:200px; height:40px; margin:auto; text-align: center; padding:20px; border-radius: 10px; font-family:'Courier New', Courier, monospace } .container { display: block; position: relative; padding-left: 80px; padding-top:5px; margin-bottom: 30px; cursor: pointer; font-size: 22px; font-family: \"Courier New\"; font-weight: bold; color:white; -webkit-user-select: none; -moz-user-select: none; -ms-user-select: none; user-select: none; } /* Hide the browser's default radio button */ .container input { position: absolute; opacity: 0; cursor: pointer; } /* Create a custom radio button */ .checkmark { position: absolute; top: 0; left: 0; height: 40px; width: 70px; background-color: white; border-radius: 10px; } /* On mouse-over, add a grey background color */ .container:hover input ~ .checkmark { background-color: #ccc; } /* When the radio button is checked, add a blue background */ .container input:checked ~ .checkmark { background-color: gold; } /* Create the indicator (the dot/circle - hidden when not checked) */ .checkmark:after { content: \"\"; position: absolute; display: none; } /* Show the indicator (dot/circle) when checked */ .container input:checked ~ .checkmark:after { display: block; } /* Style the indicator (dot/circle) */ .container .checkmark:after { top: 15px; left: 15px; width: 40px; height: 10px; border-radius: 3px; background: black; } </style> <meta name=\"viewport\" content=\"width=device-width, height=device-height, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0\" /> <script> console.log(\"Inline JS running.\"); function updateColor(){ var red = document.forms['settings'].red.value; var green = document.forms['settings'].green.value; var blue = document.forms['settings'].blue.value; var rgb = blue | (green << 8) | (red << 16); var color = \"#\" + (0x1000000 + rgb).toString(16).slice(1); document.getElementById(\"colorUpdate\").style.backgroundColor = color; } </script> </head> <body> <h1 id=\"colorUpdate\">Glowtie</h1> <form action=\"\" name=\"settings\" id=\"settings\" method=\"post\"> <!--Color: <input class=\"jscolor\" value=\"ffffff\" name=\"color\">--> <div id=\"sliderCont\"> RED<br /> <input type=\"range\" class=\"slider\" min=\"0\" max=\"255\" value=\"127\" name=\"red\" onchange=\"updateColor()\"><br /> GREEN<br /> <input type=\"range\" class=\"slider\" min=\"0\" max=\"255\" value=\"127\" name=\"green\" onchange=\"updateColor()\"><br /> BLUE<br /> <input type=\"range\" class=\"slider\" min=\"0\" max=\"255\" value=\"127\" name=\"blue\" onchange=\"updateColor()\"><br /> </div> <br /> <div style=\"width:200px;margin:auto;\"> <!-- <input class=\"radio\" type=\"radio\" name=\"mode\" value=\"0\" checked> Off<br /> <input class=\"radio\" type=\"radio\" name=\"mode\" value=\"2\"> Solid<br /> <input class=\"radio\" type=\"radio\" name=\"mode\" value=\"3\"> Infinity<br /> <input class=\"radio\" type=\"radio\" name=\"mode\" value=\"4\"> Breathe<br /> <input class=\"radio\" type=\"radio\" name=\"mode\" value=\"5\"> Burst<br /><br />--> <label class=\"container\">Off <input type=\"radio\" checked=\"checked\" name=\"mode\" value=\"0\"> <span class=\"checkmark\"></span> </label> <label class=\"container\">Solid <input type=\"radio\" name=\"mode\" value=\"2\"> <span class=\"checkmark\"></span> </label> <label class=\"container\">Infinity <input type=\"radio\" name=\"mode\" value=\"3\"> <span class=\"checkmark\"></span> </label> <label class=\"container\">Breathe <input type=\"radio\" name=\"mode\" value=\"4\"> <span class=\"checkmark\"></span> </label> <label class=\"container\">Burst <input type=\"radio\" name=\"mode\" value=\"5\"> <span class=\"checkmark\"></span> </label> <button style=\"width:150px;height:50px;background-color:gold;color:black;position:relative;margin-left:25px;margin-top:20px;font-family: 'Courier New', Courier, monospace;font-size:20px;border:0px;border-radius:10px;\" onclick=\"document.forms['settings'].submit()\" type=\"button\">UPDATE</button> </div> </form> </body> </html>";

  
  server.send(200, "text/html", html);
  
  
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
  pixels.show();
}

void lowBatt(){
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

void solid(){
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

void pulse(int red, int green, int blue){
  if(pi>=200){
    pi=0;
  }

  //Brightness value counter
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
