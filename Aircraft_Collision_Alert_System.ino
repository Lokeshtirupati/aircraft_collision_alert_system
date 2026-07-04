#define TRIG_PIN 9
#define ECHO_PIN 10

#define GREEN_LED 2
#define YELLOW_LED 3
#define RED_LED 4

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Measure Distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Green Alert Zone
  if (distance > 50) {

    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);

    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    digitalWrite(GREEN_LED, LOW);
    delay(500);
  }

  // Yellow Alert Zone
  else if (distance > 20 && distance <= 50) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    digitalWrite(YELLOW_LED, HIGH);
    delay(300);
    digitalWrite(YELLOW_LED, LOW);
    delay(300);
  }

  // Red Danger Zone
  else {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);

    digitalWrite(RED_LED, HIGH);
    delay(150);
    digitalWrite(RED_LED, LOW);
    delay(150);
  }
}
