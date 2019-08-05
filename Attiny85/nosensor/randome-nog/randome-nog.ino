#include <Adafruit_NeoPixel.h>

#define PIN       0
#define NUMPIXELS 64
#define BRIGHTNESS 10
int offtime;
int offs = 10;
int s;
int i;
int r, g, b;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
}

void loop() {
    if (s <= 0){
      offtime = random(1, 500);
      s = offs;
    }
    pinkPin();
    strip.setPixelColor(i,r,g,b);
    strip.show();
    delay(offtime);
    pinkPin();
    strip.setPixelColor(i,0,0,0);
    strip.show();
    delay(offtime);
}

void pinkPin(){
  i = int(random(-1, 65));
  r = int(random(0, BRIGHTNESS));
  g = int(random(0, BRIGHTNESS));
  b = int(random(0, BRIGHTNESS));
  }
