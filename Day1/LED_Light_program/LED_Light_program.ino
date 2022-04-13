# define LED 3

void setup() {
  pinMode(LED, OUTPUT); 
}

void loop() {
  digitalWrite(LED, HIGH); 
  delay(2000); 
  digitalWrite(LED, LOW); 
  delay(2000);
}
