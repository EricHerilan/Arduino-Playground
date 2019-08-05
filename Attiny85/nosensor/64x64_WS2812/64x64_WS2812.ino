#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 64
#define PIN    0
#define Bright 10
#define RANDOMCOLOR 0
int a, c, x, y, i, l, rs;
int r, g, b, t, s;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin();
}


void loop() {
  theshow();
}

//TheShow---------------------------------------------------------------
void theshow(){
  rs = random(0,5);
  if(rs == 1){
    BLINK(random(-1,3), random(10,50));
    }
  else if(rs == 2){
      for(int t = 0; t<random(5,20);t++){
        PKP(2,1);
        drawCircl();
        delay(200);
        clean();
        }
    }
  else if(rs == 3){
      for(int t = 0; t<random(5,20);t++){
        PKP(1,1);
        triangle();
        delay(200);
        clean();
        }
    }
  else if(rs == 4){
    PKP(0,1);
    for(a = 0;a < NUMPIXELS; a++){
      strip.setPixelColor(a,r,g,b);
      strip.show();
      delay(10);
      }
    for(a = 0;a < NUMPIXELS; a++){
      strip.setPixelColor(a,0,0,0);
      strip.show();
      delay(10);
      }
    }
/*  else if(rs == 5){
      for(int t = 0; t<random(5,20);t++){
        PKP(0);
        QM();
        delay(200);
        clean();
        delay(50);
        }
    }
    */
  else{
      for(int t = 0; t<random(5,10);t++){
        tColor(50, 10, 0);
        Wtriangle();
        delay(300);
        clean();
        delay(150);
        QM();
        delay(300);
        clean();
        delay(150);
        }
    }
rs = 0;
/*  else{

    }

  else{

    for(int z = 0;z < Bright;z++){
        for(a = 0;a < NUMPIXELS;a++){
        strip.setPixelColor(a,z,z,z);
        }
      strip.show();
      delay(20);
      }
    for(int z = Bright;z >= 0;z--){
        for(a = 0;a < NUMPIXELS;a++){
        strip.setPixelColor(a,z,z,z);
        }
      strip.show();
      delay(20);
      }
*/
}

//ColorSet--------------------------------------------------------------
void tColor(int Cr,int Cg, int Cb){
  r = Cr;
  g = Cg;
  b = Cb;
  }

//Value-----------------------------------------------------------------
void PKP(int Type, int Tc){
  if(Type == 0){
    x = 3;
    y = 3;
    }
    //t
  else if(Type == 1){
      x = int(random(3, 5));
      y = int(random(0, 5));
    }
    //c
  else if(Type == 2){
      x = int(random(2, 6));
      y = int(random(2, 6));
    }
  if(Tc == 1){tColor(random(1, Bright), random(1, Bright), random(1, Bright));};
  }

//Funktion--------------------------------------------------------------

void BLINK(int t,int s){
  tColor(50, 10, 0);
  for(int e = s;e > 0;e--){
    if(t == 0){
      QM();
      delay(50);
      clean();
      delay(10);
    }else if(t == 1){
      PKP(1,0);
      triangle();
      delay(50);
      clean();
      delay(10);
    }else if(t == 2){
      PKP(2,0);
      drawCircl();
      delay(50);
      clean();
      delay(10);
    }
  }
}
void clean(){
  for(a = 0;a <= NUMPIXELS;a++){strip.setPixelColor(a,0,0,0);}
  strip.show();
  }


//Shapes-----------------------------------------------------------------
//!------------------------------0
//0 1 2 x x 5 6 7--x
//1     x x     15
//2     x x     23
//3     x x     31
//4     x x     39
//5             47 
//6     x x     55
//7     x x     63
//y
void QM(){
  for(a = 0;a <= 7;a++){
    if(a != 5){
      for(c = 0;c <= 1;c++){
      i = (a * 8) + 3 + c;
      strip.setPixelColor(i,r,g,b);
      }
    }
  }
  strip.show();
}
//circle----------------1
//0 1 2 3 4 5 6 7--x
//1             15
//2     x x x   23
//3   x       x 31
//4   x   36  x 39
//5   x       x 47 
//6     x x x   55
//7             63
//y
void drawCircl(){
    for(a = 2;a > -3;a--){
      if(a == 2 || a == -2){
          for(c = 1;c > -2;c--){
            i = ((y - a) * 8) + x + c;
            strip.setPixelColor(i,r,g,b);
            }
      }else{
            i = ((y - a) * 8) + x + 2;
            strip.setPixelColor(i,r,g,b);
            i = ((y - a) * 8) + x - 2;
            strip.setPixelColor(i,r,g,b);
          }
      }
strip.show();
}

//triangle
//0 1 2 3 4 5 6 7--x
//1             15
//2       x     23
//3     x   x   31
//4   x   36  x 39
//5 x x x x x x x7 
//6             55
//7             63
//y
//lim x 3-4 y 0-4
void triangle(){
  l = 0;
  for(a = 0; a < 4;a++){
    if(a != 3){
        i = ((y + a) * 8) + x - a;
        strip.setPixelColor(i,r,g,b);
        i = i + l;
        strip.setPixelColor(i,r,g,b);
        l += 2;
      }else if(a = 3){
        for(c = -3; c <= 3; c++){
        i = ((y + a) * 8) + x + c;
          strip.setPixelColor(i,r,g,b);
          }
        }
  }
  strip.show();
  }
//0 1 2 x x 5 6 7--x
//1     x x     15
//2   x     x   23
//3   x     x   31
//4 x         x 39
//5 x         x 47 
//x             x5
//x x x x x x x x3
void Wtriangle(){
  tColor(50, 10, 0);
  l = 1;
  for(a = 0; a <= 6;a+=2){
    for(c = 0; c < 2;c++){
      for(int e = 0; e < 2;e++){
          i = ( a + c ) * 8 + 3 - a * 0.5 + l * e;
          strip.setPixelColor(i,r,g,b);
      }
    }
    l += 2;
    if(a == 6){
      for(int f = 0; f < 6;f++){
      i = 57 + f;
      strip.setPixelColor(i,r,g,b);
    } 
      }
  }

  strip.show();
}

/*

 */
