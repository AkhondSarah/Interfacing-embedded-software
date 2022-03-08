//Pin connected to ST_CP of 74HC595
int LATCH = 15;
//Pin connected to SH_CP of 74HC595
int CLOCK = 16;
////Pin connected to DS of 74HC595
int SER = 14;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

  delay(1000);
}
void loop() {
  int bitArray[] = {1, 3, 7, 15, 31, 63, 127, 255};
   for(int i = 0; i < 8; i++) {
      //digitalWrite(LATCH, LOW);
      shiftOut(SER, CLOCK, MSBFIRST, 0);
       shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
       
      digitalWrite(LATCH, HIGH);
       digitalWrite(LATCH, LOW);
      delay(50);
   }  
      // bitshift left }
      for(int i = 0; i < 8; i++) {
      //digitalWrite(LATCH, LOW);
      shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
       shiftOut(SER, CLOCK, MSBFIRST, 255);
       
      digitalWrite(LATCH, HIGH);
       digitalWrite(LATCH, LOW);
      delay(50);
      }
      for (int i = 8; i > (-1); i--) {
        shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
       shiftOut(SER, CLOCK, MSBFIRST, 255);
        digitalWrite(LATCH, HIGH);
       digitalWrite(LATCH, LOW);
      delay(50);
      }
       for (int i = 8; i > (-1); i--) {
        shiftOut(SER, CLOCK, MSBFIRST, 0);
       shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
       
      digitalWrite(LATCH, HIGH);
       digitalWrite(LATCH, LOW);
      delay(50);
       }
}
      
