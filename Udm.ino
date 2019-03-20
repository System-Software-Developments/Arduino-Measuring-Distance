const int trigger = 7;
const int echoPin = 6;

void setup() {
 Serial.begin(9600);
}

void loop() {
  long duration, inches, cm;
   pinMode(trigger, OUTPUT);
   digitalWrite(trigger, LOW);
   delayMicroseconds(2);
   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm/100.0);
   Serial.print("m ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(1000);

}

long microsecondsToCentimeters(long microseconds) {
   return microseconds * 0.034 *0.5;
}
