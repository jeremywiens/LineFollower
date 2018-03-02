#define lmf 2 // left motor front,
#define rmf 4 
#define lmb 3 
#define rmb 5

void setup() {
pinMode(lmf,OUTPUT);
pinMode(rmf,OUTPUT);
pinMode(lmb,OUTPUT);
pinMode(rmb,OUTPUT);

}

void loop() {
digitalWrite(lmf, HIGH);
digitalWrite(rmf, HIGH);
digitalWrite(lmb, LOW);
digitalWrite(rmb, LOW);

delay(1000);

digitalWrite(lmf, LOW);
digitalWrite(rmf, LOW);
digitalWrite(lmb, HIGH);
digitalWrite(rmb, HIGH);

delay(1000);

digitalWrite(lmb, HIGH);
digitalWrite(rmf, LOW);
digitalWrite(lmf, LOW);
digitalWrite(rmb, LOW);

delay(1000);

}

