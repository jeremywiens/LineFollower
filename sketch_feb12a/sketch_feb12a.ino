//void setup()
//{
//    Serial.begin(9600);
//}
//
//void loop()
//{
//    delay(1000);
//
//    pinMode(3, OUTPUT);
//    digitalWrite(3, HIGH);
//    delay(1000);
//
//    // pinMode(3, INPUT); // get rid of this line
//    Serial.println(digitalRead(3));
//}

const int IN_A5 = A5;
const int IN_D7 = 7;
void setup()
{
  Serial.begin(9600);
  pinMode(IN_A5, INPUT);      // sets the digital pin 13 as output
  pinMode(IN_D7, INPUT);        // sets the digital pin 7 as input
}

int value_A5;
bool value_D7;

void loop()
{
  value_A5 = analogRead(IN_A5);
  value_D7 = digitalRead(IN_D7);
  Serial.println(value_A5);
  Serial.println(value_D7);
  delay(1000);
}
