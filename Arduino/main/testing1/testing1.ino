/*  YUMO 200 P/R rotary encoder
 *  
 *  Wiring
 *  Black - pin 2
 *  White - pin 3
 *  Brown - Ard. 5V
 *  Blue  - GND
 *  Orange - nothing for this use (is possibly for dir encoding?). 
 */



long encoder = 0; // counts overall number of 'ticks' since beginning of program
const int encoder_a = 2; // black 
const int encoder_b = 3; // white 

void setup() {
  Serial.begin(9600);
  pinMode(encoder_a, INPUT);
  pinMode(encoder_b, INPUT);

  // encoder pin on interrupt 0 (pin 2)
  attachInterrupt(0, encoderPinChangeA, CHANGE);
  // encoder pin on interrupt 1 (pin 3)
  attachInterrupt(1, encoderPinChangeB, CHANGE);
}

void loop() {
  
  Serial.println(encoder);
}


void encoderPinChangeA() {
 if (digitalRead(encoder_a)==digitalRead(encoder_b)) {
  encoder--;
 }
 else{
  encoder++;
 }
}

void encoderPinChangeB() {
 if (digitalRead(encoder_a) != digitalRead(encoder_b)) {
  encoder--;
 }
 else {
  encoder++;
 }
}

