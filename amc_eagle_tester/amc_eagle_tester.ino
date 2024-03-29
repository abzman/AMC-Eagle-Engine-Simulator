int tach_pin = 40;
int o2_pin = 44;
int choke_pin = 24;
int start_pin = 25;
int solvac_pin = 28;
int pcv_pin = 27;
int idle_pin = 26;
int altitude_pin = 29;
int downstream_pin = 30;
int wot_pin = 31;
int upstream_pin = 32;
int idlespeed_pin = 33;
int thermal_pin = 34;
int coolant_pin = 35;
int tenvac_pin = 36;
int fourvac_pin = 37;
int a0_pin = 38;
int b0_pin = 39;

void setup() {
  pinMode(tach_pin, OUTPUT);
  digitalWrite(tach_pin, 0);
  pinMode(o2_pin, OUTPUT);
  digitalWrite(o2_pin, 0);
  pinMode(choke_pin, OUTPUT);
  digitalWrite(choke_pin, 0);
  pinMode(start_pin, OUTPUT);
  digitalWrite(start_pin, 0);
  pinMode(solvac_pin, OUTPUT);
  digitalWrite(solvac_pin, 0);
  pinMode(pcv_pin, OUTPUT);
  digitalWrite(pcv_pin, 0);
  pinMode(idle_pin, OUTPUT);
  digitalWrite(idle_pin, 0);
  pinMode(altitude_pin, OUTPUT);
  digitalWrite(altitude_pin, 0);
  pinMode(downstream_pin, OUTPUT);
  digitalWrite(downstream_pin, 0);
  pinMode(wot_pin, OUTPUT);
  digitalWrite(wot_pin, 0);
  pinMode(upstream_pin, OUTPUT);
  digitalWrite(upstream_pin, 0);
  pinMode(idlespeed_pin, OUTPUT);
  digitalWrite(idlespeed_pin, 0);
  pinMode(thermal_pin, OUTPUT);
  digitalWrite(thermal_pin, 0);
  pinMode(coolant_pin, OUTPUT);
  digitalWrite(coolant_pin, 0);
  pinMode(tenvac_pin, OUTPUT);
  digitalWrite(tenvac_pin, 0);
  pinMode(fourvac_pin, OUTPUT);
  digitalWrite(fourvac_pin, 0);
  pinMode(a0_pin, OUTPUT);
  digitalWrite(a0_pin, 0);
  pinMode(b0_pin, OUTPUT);
  digitalWrite(b0_pin, 0);
  Serial.begin(115200);

}

void loop() {
  Serial.println("1000rpm");
    tone(tach_pin, 50);
    delay(2000);
  Serial.println("2000rpm");
    tone(tach_pin, 100);
    delay(2000);
  Serial.println("3000rpm");
    tone(tach_pin, 150);
    delay(2000);
  Serial.println("4000rpm");
    tone(tach_pin, 200);
    delay(2000);
  Serial.println("5000rpm");
    tone(tach_pin, 250);
    delay(2000);
  Serial.println("6000rpm");
    tone(tach_pin, 300); //6000rpm
    delay(2000);
    noTone(tach_pin);

  Serial.println("o2 sweep up");
    for (int fadeValue = 0 ; fadeValue <= 72; fadeValue += 1) {
      // sets the value (range from 0 to 255):
      analogWrite(o2_pin, fadeValue);
      delay(20);
    }
    delay(500);
  Serial.println("o2 sweep down");
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 72 ; fadeValue >= 0; fadeValue -= 1) {
      // sets the value (range from 0 to 255):
      analogWrite(o2_pin, fadeValue);
      delay(20);
    }
      delay(100);

  Serial.println("choke");
    digitalWrite(choke_pin, 1);
      delay(500);
    digitalWrite(choke_pin, 0);
      delay(500);
  Serial.println("start");
    digitalWrite(start_pin, 1);
      delay(500);
    digitalWrite(start_pin, 0);
      delay(500);
  Serial.println("solvac");
    digitalWrite(solvac_pin, 1);
      delay(500);
    digitalWrite(solvac_pin, 0);
      delay(500);
  Serial.println("pcv");
    digitalWrite(pcv_pin, 1);
      delay(500);
    digitalWrite(pcv_pin, 0);
      delay(500);
  Serial.println("idle");
    digitalWrite(idle_pin, 1);
      delay(500);
    digitalWrite(idle_pin, 0);
      delay(500);
  Serial.println("altitude");
    digitalWrite(altitude_pin, 1);
      delay(500);
    digitalWrite(altitude_pin, 0);
      delay(500);
  Serial.println("downstream");
    digitalWrite(downstream_pin, 1);
      delay(500);
    digitalWrite(downstream_pin, 0);
      delay(500);
  Serial.println("wot");
    digitalWrite(wot_pin, 1);
      delay(500);
    digitalWrite(wot_pin, 0);
      delay(500);
  Serial.println("upstream");
    digitalWrite(upstream_pin, 1);
      delay(500);
    digitalWrite(upstream_pin, 0);
      delay(500);
  Serial.println("idlespeed");
    digitalWrite(idlespeed_pin, 1);
      delay(500);
    digitalWrite(idlespeed_pin, 0);
      delay(500);
  Serial.println("tes");
    digitalWrite(thermal_pin, 1);
      delay(500);
    digitalWrite(thermal_pin, 0);
      delay(500);
  Serial.println("cts");
    digitalWrite(coolant_pin, 1);
      delay(500);
    digitalWrite(coolant_pin, 0);
      delay(500);
  Serial.println("10\" vac");
    digitalWrite(tenvac_pin, 1);
      delay(500);
    digitalWrite(tenvac_pin, 0);
      delay(500);
  Serial.println("4\" vac");
    digitalWrite(fourvac_pin, 1);
      delay(500);
    digitalWrite(fourvac_pin, 0);
      delay(500);
  Serial.println("a0");
    digitalWrite(a0_pin, 1);
      delay(500);
    digitalWrite(a0_pin, 0);
      delay(500);
  Serial.println("b0");
    digitalWrite(b0_pin, 1);
      delay(500);
    digitalWrite(b0_pin, 0);
      delay(500);
      
  digitalWrite(tenvac_pin, 1);
  digitalWrite(fourvac_pin, 1);
  digitalWrite(wot_pin, 1);

  //richer
  Serial.println("richer");
  richer(20);
  delay(500);

  //leaner
  Serial.println("leaner");
  leaner(20);
  delay(500);

  //low
  Serial.println("low");
  digitalWrite(tenvac_pin, 1);
  digitalWrite(fourvac_pin, 1);
  digitalWrite(wot_pin, 1);
  delay(500);
  //med
  Serial.println("med");
  digitalWrite(tenvac_pin, 1);
  digitalWrite(fourvac_pin, 0);
  digitalWrite(wot_pin, 1);
  delay(500);
  //other med
  Serial.println("med");
  digitalWrite(tenvac_pin, 0);
  digitalWrite(fourvac_pin, 1);
  digitalWrite(wot_pin, 1);
  delay(500);
  //high
  Serial.println("high");
  digitalWrite(tenvac_pin, 0);
  digitalWrite(fourvac_pin, 0);
  digitalWrite(wot_pin, 1);
  delay(500);
  //max
  Serial.println("wot");
  digitalWrite(tenvac_pin, 0);
  digitalWrite(fourvac_pin, 0);
  digitalWrite(wot_pin, 0);
  delay(500);

  Serial.println("hot");
  digitalWrite(thermal_pin, 1);
  digitalWrite(coolant_pin, 0);
  delay(500);
  Serial.println("cold");
  digitalWrite(thermal_pin, 0);
  digitalWrite(coolant_pin, 0);
  delay(500);


}

void richer(int i) {
  for (int j = 0; j < i; j++) {
    Serial.println("r");
    digitalWrite(a0_pin, 1);
    delay(25);
    digitalWrite(b0_pin, 1);
    delay(25);
    digitalWrite(a0_pin, 0);
    delay(25);
    digitalWrite(b0_pin, 0);
    delay(25);
  }
}

void leaner(int i) {
  for (int j = 0; j < i; j++) {
    Serial.println("l");
    digitalWrite(b0_pin, 1);
    delay(25);
    digitalWrite(a0_pin, 1);
    delay(25);
    digitalWrite(b0_pin, 0);
    delay(25);
    digitalWrite(a0_pin, 0);
    delay(25);
  }
}
