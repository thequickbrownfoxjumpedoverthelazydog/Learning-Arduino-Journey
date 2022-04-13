#define RT0 10000
#define B 3977
#define LED 13
#define VCC 5
#define R 10000

float RT, VR, ln, TX, T0, VRT; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  T0 = 25+273.15; 
  pinMode(LED, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  VRT = analogRead(A0);
  VRT = (5.00 / 1023.00) * VRT;
  VR = VCC - VRT; 
  RT = VRT / (VR / R);

  ln = log(RT / RT0);
  TX = (1 / ((ln / B) + (1 / T0)));

  TX = TX - 273.15; 
  Serial.print("Temperature"); 
  Serial.print("\t");
  Serial.print(TX);
  Serial.print("C\t\t");
  Serial.print(TX + 273.15);
  Serial.print("K\t\t");
  Serial.print((TX * 1.8) + 32);
  Serial.println("F");
  delay(500);

  if (TX >= 28){
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW); 
  }
}
