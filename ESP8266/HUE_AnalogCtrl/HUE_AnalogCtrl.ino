#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 100
#define PIN    D1
#define Bright 50
#define HU     2000
#define PWMRANGE 1023
float vhu;
int a, r, g, b, d;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  strip.begin();
  delay(100);
  vhu = (HU - 1) * 2 / 3;
}


void loop() {
  
  d = analogRead(A0);
  float c = map(d, 0, 1023, 0, HU);

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
    Serial.print("d:_");
    Serial.println(d);
    Serial.print("c:_");
    Serial.println(c);
    Serial.print("RGB:_");
    Serial.print(r);
    Serial.print(",");
    Serial.print(g);
    Serial.print(",");
    Serial.println(b);
    delay(50);
}
