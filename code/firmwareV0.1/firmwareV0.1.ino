//GlowTie Firmware v0.1
//Stephen Hawes 2018

#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ADC_MODE(ADC_VCC);

const char *ssid = "GLOWTIEbeta";
const char *password = "letmeintoglowtie";
 
ESP8266WebServer server(80);

#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            12
#define NUMPIXELS      13

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int delayval = 80; 
int btMode = 1;
int rVal = 30;
int gVal = 0;
int bVal = 60;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);
  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.begin();
}

void handleRoot() {
  server.send(200, "text/html", "<h1>Hello from Glowtie!</h1>");
}

void loop() {
  server.handleClient();
  Serial.println(ESP.getVcc());
  if(ESP.getVcc() <= 3.26){
    pixels.setPixelColor(6, pixels.Color(50,0,0));
    pixels.show();
  }
  else{
    if(btMode == 0){
      //Standby mode
    }
    else if(btMode == 1){
      //Burst mode
      burst(rVal, gVal, bVal);
    }
    else if(btMode == 2){
      //Infinity Mode
      infin(rVal, gVal, bVal);
    }
    
  }
}


void burst(int red, int green, int blue){
  
  int a=0;
  int b=0;
  int c=0;
  int d=0;

  for(int i=0; i<300; i++){
    // a column
    if(i<=50){
      a = a + 1;
    }
    if(i>50 && a>0){
      a = a - 1;
    }

    // b column
    if(i>=25 && i<=75){
      b = b + 1;
    }
    if(i>75 && b>0){
      b = b - 1;
    }

    //c column
    if(i>=50 && i<=100){
      c = c + 1;
    }
    if(i>100 && c>0){
      c = c - 1;
    }

    //d column
    if(i>=75 && i<=125){
      d = d + 1;
    }
    if(i>125 && d>0){
      d = d - 1;
    }

    float fA = float(a);
    float fB = float(b);
    float fC = float(c);
    float fD = float(d);
    
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
    delay(5);
  }
}

void infin(int red, int green, int blue){

  pixels.setPixelColor(0, pixels.Color(red, green, blue)); // Moderately bright green color.
  
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(1, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(2, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(1, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(3, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(2, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(4, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(3, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(5, pixels.Color(red, green, blue)); // Mode rately bright green color.
  pixels.setPixelColor(4, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(6, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(5, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(12, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(6, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(11, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(12, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(10, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(11, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(9, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(10, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(8, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(9, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(7, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(8, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(6, pixels.Color(red, green, blue)); // Moderately bright green color.
  pixels.setPixelColor(7, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).

  
  pixels.setPixelColor(6, pixels.Color(0,0,0));

}


