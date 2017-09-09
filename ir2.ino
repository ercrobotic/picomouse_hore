//-----
//        ___
//       /   \
//1 ---  | x |  -- 3 (GND)
//2 ---  | y |  -- 4 (GND)
//   |
//
//-----
//x = transmitter
//y = receiver
//
//1 = vcc (digital pin) -> 100 ohm -> kaki 1
//2 = -----
#define ledIR 15
#define VCC 16
#define inPin A0
float noise, IR, selisih;

void setup()
{
  Serial.begin(9600);
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);
  pinMode(ledIR, OUTPUT);
}

void loop()
{
  //  float mapping;
  digitalWrite(ledIR, LOW);
  delay(5);
  noise = analogRead(inPin);
  delay(5);
  digitalWrite(ledIR, HIGH);
  delay(5);
  IR = analogRead(inPin);
  selisih = IR - noise;
  //  mapping = map(selisih, -250, -15, 2, 10);
  Serial.print(noise);
  Serial.print(" ");
  Serial.print(IR);
  Serial.print(" ");
  Serial.print(selisih);
  //  Serial.print(" ");
  //  Serial.print(mapping);
  Serial.println();
  delay(50);
}
