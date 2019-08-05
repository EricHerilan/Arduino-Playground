#define analogPinR 2
#define analogPinW 0
#define PWMRANGE 255
#define brightTreshold 100
#define fadeStage 5//times to fade out
#define Keep 10//hold the stage

int fadeDelay = 10;
int stageDelay = 500;
int cb;//currentBrightness
int tb;//targetBrightnedd
int ab, sb;
int a, b, c, k, gap, esb;
void setup() {
esb = int(PWMRANGE / fadeStage);
tb = fadeStage;
lightUp();
tb = 0;
lightDown();
  b = 0;
  cb = 0;
  tb = 0;
  k = 0;
}

void loop() {
  if(k > 0){ 
    k--;
  }else{
    anaHum();
    }
  if(tb > cb){
      lightUp();
    }else if(tb < cb){
      lightDown();
      }
  delay(stageDelay);
}
void anaHum(){
  if(analogRead(analogPinR) >= brightTreshold){
      tb = fadeStage;
      k = 0;
    }else{
      if(tb <= 0){
        tb = 0;
      }else{
        tb--;
      }
    }
  }

void lightUp(){
    gap = tb - cb;
    for(a = gap; a > 0; a--){
      for(c = esb; c > 0; c--){
        b++;
        if(b >= PWMRANGE){b = PWMRANGE;}
        analogWrite(analogPinW, b);
        delay(fadeDelay);
      }
    }
    cb = tb;
    k = Keep;
  }

void lightDown(){
    gap = cb - tb;
    for(a = gap; a > 0; a--){
      for(c = esb; c > 0; c--){
        b--;
        if(b <= 0){b = 0;}
        analogWrite(analogPinW, b);
        delay(fadeDelay);
      }
    if(a == 1 && tb == 0 && b > 0){a++;}
    }
    cb = tb;
    k = Keep;
  }
