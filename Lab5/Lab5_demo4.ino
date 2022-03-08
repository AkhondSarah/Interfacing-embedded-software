const int SER = 14; //data
const int LATCH = 15; //RCLK
const int CLOCK = 16; //SRCLK
volatile int i, j;
IntervalTimer myTimer;

byte sevenSegmentDisplay[10] ={
B00000011,  //0   common anode not used in this lab
B10011111,  //1
B00100101,  //2
B00001101,  //3
B10011001,  //4
B01001001,  //5
B11000001,  //6
B00011111,  //7
B00000001,  //8
B00011001   //9
};



void setup() {
  //put your setup code here, to run once:
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  myTimer.begin(resetCounter, 5000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i =0; i < 10; i++){
    for(j = 0; j < 10; j++){
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLOCK, LSBFIRST, sevenSegmentDisplay[j]); //Always pass 2nd reigster first
      shiftOut(SER, CLOCK, LSBFIRST, sevenSegmentDisplay[i]); 
      digitalWrite(LATCH, HIGH);
      delay(300);
    }
  }
}
void resetCounter(){
  i = j = 0;
}
