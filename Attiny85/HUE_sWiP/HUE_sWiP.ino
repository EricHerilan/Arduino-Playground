#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 100
#define PIN    2
#define Bright 50
#define HU     2000
int a, vhu;
int r, g, b;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin();
  delay(100);
  vhu = (HU - 1) * 2 / 3;
}


void loop() {
  for(float c = 0; c < HU; c += 1){
    if(c <= vhu){
      r = sin((c/vhu + 0.5) * PI) * Bright;
      }else{
        r = sin((c/vhu - 1) * PI) * Bright;
        }

      g = sin((c/vhu) * PI) * Bright;
      
      b = sin((c/vhu - 0.5) * PI) * Bright;
    if(r<=0){r = 0;}
    if(g<=0){g = 0;}
    if(b<=0){b = 0;}
    for(a = 0; a < NUMPIXELS; a ++){
      strip.setPixelColor(a,r,g,b);
      }
    strip.show();
    delay(10);
    }
}
