const int analogApi = A0;
const int analogVoice = A1;
const int signalLed = 4;

void setup() {
  Serial.begin(9600);
  pinMode(signalLed, OUTPUT);

  Serial.print("Memulai program ");

  for (int i = 0; i < 3; i++) {
    Serial.print(".");
    delay(1000);
  }
}

void loop() {
  readApi();
  delay(100);
  readVoice();
  delay(100);
}

void readApi() {
  int val = analogRead(analogApi);

  Serial.println();
  Serial.print("Nilai Sensor Api: ");
  Serial.print(val);

  if (val < 200) {
    digitalWrite(signalLed, 1);
    delay(1000);
    digitalWrite(signalLed, 0);
  }
}

void readVoice() {
  int val = analogRead(analogVoice);
  Serial.println();
  Serial.print("Nilai Sensor Suara: ");
  Serial.print(val, DEC);

  if (val > 150) {
    digitalWrite(signalLed, 1);
    delay(1000);
    digitalWrite(signalLed, 0);
  }
}
