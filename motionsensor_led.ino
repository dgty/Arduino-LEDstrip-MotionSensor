#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9

// Led stip config
int brightness = 255;
int gBright = 0;
int rBright = 0;
int bBright = 0;

const int fadeSpeed = 10;

// motion sensor
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                // PIR status

void setup() {
  // LED strip
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);

  // motion sensor
  pinMode(pirPin, INPUT);
  
  Serial.begin(9600); 
}

void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(BLUE_LED, bBright);
       bBright += 1;
       delay(fadeSpeed);
   } 
}

void TurnOff() {
   for (int i = 0; i < 256; i++) {
       analogWrite(BLUE_LED, brightness);
       brightness -= 1;
       delay(fadeSpeed);
   }
   analogWrite(BLUE_LED, 0);
}

void loop() {
  pirStat = digitalRead(pirPin); 
  if (pirStat == HIGH) {            // if motion detected
     Serial.println("Movement");
     TurnOn();
     delay(5000);
     TurnOff();
   }
}
