#include <Adafruit_NeoPixel.h>
#include <DigiKeyboard.h>
#define PIN 0
#define KEYPAD_PLUS                (  87  | 0xF000 )

int ttalpix = 9; // number of pixel
int val, pinpl, a;
int n = 0;
int r, g, b, s;
int delaytime = 100;
int stime = 100; //display times
int ftime = 100; //fadeout time

Adafruit_NeoPixel strip = Adafruit_NeoPixel(ttalpix, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  s = 1;
  g = 0;
  r = 0;
  b = 100;
  //test1
    strip.begin();
    for (a = 0; a < ttalpix; a++){
    strip.setPixelColor(a, 200, 100, 0);
    if (g >= 250){s = -1;}
    else if (g <= 0){s = 1;}
    g += 10 * s;
    strip.show();
    delay(delaytime);
    }
   //end test
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("notepad");
  DigiKeyboard.delay(850);
  DigiKeyboard.println("hallo I'm Eric");
  DigiKeyboard.println("Email:a88662668@hotmail.com");
  DigiKeyboard.println("you can visit ericherilan.com for more information!");
  DigiKeyboard.sendKeyPress(KEYPAD_PLUS, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);
}
void loop() {
  strip.begin();
  pickColor();
  for (a = 0; a < ttalpix; a++){
  strip.setPixelColor(a, r, g, b);
  if (g >= 250){s = -1;}
  else if (g <= 0){s = 1;}
  g += 10 * s;
  strip.show();
  delay(delaytime);
  }
    s = 1;
}
void pickColor() {
  r = random(0, 100);
  g = random(0, 100);
  b = random(0, 100);
  }
