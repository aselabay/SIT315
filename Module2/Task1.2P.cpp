#define SENSOR_PIN 2
#define LED_PIN 13
volatile int state = LOW;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), motionDetected, CHANGE);
}

void loop() {
  digitalWrite(LED_PIN, state);
  delay(100); 
}

void motionDetected() {
  state = !state;
  Serial.println(state == HIGH ? "Motion Detected" : "No Motion");
}
