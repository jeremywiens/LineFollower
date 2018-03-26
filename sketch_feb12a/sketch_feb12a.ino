#define lmf 9 // left motor front,
#define rmf 11 
#define lmb 10 
#define rmb 12
//#define loutside 12
//#define left 11
//#define center 10
//#define right 9
//#define routside 8


void setup() {
pinMode(lmf,OUTPUT);
pinMode(rmf,OUTPUT);
pinMode(lmb,OUTPUT);
pinMode(rmb,OUTPUT);
//pinMode(loutside, INPUT);
//pinMode(left, INPUT);
//pinMode(center, INPUT);
//pinMode(right, INPUT);
//pinMode(routside, INPUT);


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

