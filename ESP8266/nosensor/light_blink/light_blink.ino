#define SPING       0
#define analogPing  A3
#define BRIGHT      200
#define INPUTMODE   1//0=random,1=analog
int maxPin = 10;
int fadedelay = 0;
int ttdelay = 10;
int inval, outval, pinnum, a;
//int st = 5;//sample take

void setup() {
  inval = 0;
  outval = 0;
}

void loop() {
  picnum();
  
  if(inval < outval)
  {
    gradeDown();
  }else if(inval > outval){
    gradeUp();
  }
  delay(ttdelay);
  outval = inval;
}

void picnum(){
  inval = 0;
  if (INPUTMODE == 1){
      inval += analogRead(SPING) / 200;
    if(inval >= maxPin){inval = maxPin;}}else{inval = random(0, maxPin + 1);}
}
void gradeDown(){
  pinnum = outval + 1;
  for(a = inval; a < outval; a++){
    pinnum --;
    analogWrite(pinnum + 2, 0);
    delay(fadedelay);
  }
}
  
void gradeUp(){
  pinnum = outval - 1;
  for(a = inval; a > outval; a--){
    pinnum ++;
    analogWrite(pinnum + 2, BRIGHT);
    delay(fadedelay);
  }
}
