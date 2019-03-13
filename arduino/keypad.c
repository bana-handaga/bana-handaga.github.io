#include <TimerOne.h>


int COUNTER = 0;
byte KEY = 0;
char CH = "";

void setup() {
  pinMode(2, INPUT_PULLUP);  // R1 melalui Diode
  pinMode(3, INPUT_PULLUP);  // R2
  pinMode(4, INPUT_PULLUP);  // R3
  pinMode(5, INPUT_PULLUP);  // R4
  pinMode(6, OUTPUT);    // C1
  pinMode(7, OUTPUT);    // C2
  pinMode(8, OUTPUT);    // C3
  pinMode(9, OUTPUT);    // C4
  //setting INT0 interrupt, pin 2
  attachInterrupt(digitalPinToInterrupt(2), Baca_keypad, FALLING); 
  //setting timer interrupt
  Timer1.initialize(10000); //10 ms
  Timer1.attachInterrupt(SCAN_KOLOM);

  Serial.begin(115200);

}
void SCAN_KOLOM() {
  COUNTER = COUNTER + 1;
  if (COUNTER == 1 ) { 
      digitalWrite(6, LOW);  
      digitalWrite(7, HIGH);  
      digitalWrite(8, HIGH);  
      digitalWrite(9, HIGH);  
  } else if (COUNTER == 2) {
      digitalWrite(6, HIGH);  
      digitalWrite(7, LOW);  
      digitalWrite(8, HIGH);  
      digitalWrite(9, HIGH);  
  } else if (COUNTER == 3) {
      digitalWrite(6, HIGH);  
      digitalWrite(7, HIGH);  
      digitalWrite(8, LOW);  
      digitalWrite(9, HIGH);  
  } else if (COUNTER == 4) {
      digitalWrite(6, HIGH);  
      digitalWrite(7, HIGH);  
      digitalWrite(8, HIGH);  
      digitalWrite(9, LOW);  
      COUNTER = 0;
  }
}

void Baca_keypad() {
  KEY = 0x00;
  if (COUNTER == 1) {
    KEY = KEY + 0xE0;
  } else if (COUNTER == 2 ) {
    KEY = KEY + 0xD0;
  } else if (COUNTER == 3 ) {
    KEY = KEY + 0xB0;
  } else if (COUNTER == 0 ) {
    KEY = KEY + 0x70;
  }
  if (digitalRead(5) == 1 ) { KEY = KEY + 0x08; }
  if (digitalRead(4) == 1 ) { KEY = KEY + 0x04; }
  if (digitalRead(3) == 1 ) { KEY = KEY + 0x02; }
  if (KEY && 0x0E == 0xE ) { KEY = KEY + 0x01; }

  if (KEY == 0xEE ) { CH = "1"; };
  if (KEY == 0xDE ) { CH = "2"; };
  if (KEY == 0xBE ) { CH = "3"; };
  if (KEY == 0x7E ) { CH = "A"; };
  
  if (KEY == 0xED ) { CH = "4"; };
  if (KEY == 0xDD ) { CH = "5"; };
  if (KEY == 0xBD ) { CH = "6"; };
  if (KEY == 0x7D ) { CH = "B"; };
  
  if (KEY == 0xEB ) { CH = "7"; };
  if (KEY == 0xDB ) { CH = "8"; };
  if (KEY == 0xBB ) { CH = "9"; };
  if (KEY == 0x7B ) { CH = "C"; };

  if (KEY == 0xE7 ) { CH = "*"; };
  if (KEY == 0xD7 ) { CH = "0"; };
  if (KEY == 0xB7 ) { CH = "#"; };
  if (KEY == 0x77 ) { CH = "D"; };
  
}

void loop() {
  Serial.println( KEY );
}
