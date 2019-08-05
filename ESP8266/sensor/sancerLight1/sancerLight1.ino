#define analogPinR A0
#define analogPinW D1
#define brightTreshold 600
#define fadeStage 5//times to fade out
#define PWMRANGE 1023
#define Keep 10//hold the stage


int fadeDelay = 5;
int stageDelay = 500;
int cb;//currentBrightness
int tb;//targetBrightness
int ab, sb;
int a, b, c, k, gap, esb;
void setup() {
  Serial.begin(9600);
  b = 0;
  cb = 0;
  tb = 0;
  k = 0;
  esb = int(PWMRANGE / fadeStage);


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
  Serial.println("_");
  Serial.println("analog__tb__cb__k__b");
  Serial.print(analogRead(analogPinR));
  Serial.print(",");
  Serial.print(tb);
  Serial.print(",");
  Serial.print(cb);
  Serial.print(",");
  Serial.print(k);
  Serial.print(",");
  Serial.print(b);
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
    Serial.print("fading...");
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
    Serial.print("fading...");
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
