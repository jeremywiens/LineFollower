#define en_L 10
#define en_R  11 //define the enable pins to motor driver

#define left_f 8 //define motor inputs
#define left_b 9

#define right_f 12
#define right_b 13

#define MUCH_LEFT  3//define digital read pins
#define LEFT  4
#define CENTER  5
#define RIGHT 6
#define MUCH_RIGHT  2



#define S_HIGH 900  //analog readings above 900 if line detected 
                    //digital readings will be HIGH
#define S_LOW 50  // analog readings below 50 if no line is detected
                    // digital readings will be LOW


void setup() {
    Serial.begin(9600);
    pinMode(right_f, OUTPUT);
    pinMode(right_b, OUTPUT);
    pinMode(left_f, OUTPUT);
    pinMode(left_b, OUTPUT);
    
}

// arduino PWM varies is from 0 to 255 
//controlling PWM controls speed by turning voltage high and low for //various frequencies 
//for i.e pwm of 30% means voltage is high for 30% of the time and low //for 70% of the time
void Forward(){
    analogWrite (en_L,150); 
    analogWrite (en_R,150); 
    digitalWrite(left_f, HIGH);
    digitalWrite(right_f, HIGH);
    digitalWrite(left_b, LOW);
    digitalWrite(right_b, LOW);
}
void HardLeft(){
    analogWrite (en_L,150); 
    analogWrite (en_R,150);
    digitalWrite(left_f, LOW);
    digitalWrite(right_f, HIGH); 
    digitalWrite(left_b, HIGH);
    digitalWrite(right_b, LOW);
}

void Stop(){
    digitalWrite(left_f, LOW);
    digitalWrite(right_f, LOW);
    digitalWrite(left_b, LOW);
    digitalWrite(right_b, LOW);
}

void Back(){    
  analogWrite (en_L,150); 
    analogWrite (en_R,150); 
    digitalWrite(left_f, LOW);
    digitalWrite(right_f, LOW);
    digitalWrite(left_b, HIGH);
    digitalWrite(right_b, HIGH);

}
void HardRight(){
    analogWrite (en_L,150); 
    analogWrite (en_R,150); 
    digitalWrite(left_f, HIGH);
    digitalWrite(right_f, LOW);
    digitalWrite(left_b, LOW);
    digitalWrite(right_b, HIGH);
}
void SlightLeft(){      
    analogWrite (en_L,75); 
    analogWrite (en_R,150); 
    digitalWrite(left_f, LOW);
    digitalWrite(right_f, HIGH);    
    digitalWrite(left_b, LOW);
    digitalWrite(right_b, LOW);
    }
void SlightRight(){
    analogWrite (en_L,150); 
    analogWrite (en_R,75); 
    digitalWrite(left_f, HIGH);
    digitalWrite(right_f, LOW);
    digitalWrite(left_b, LOW);
    digitalWrite(right_b, LOW);
    }

void loop (){

    int m_left=digitalRead(MUCH_LEFT);
    int left=digitalRead(LEFT);
    int center= !digitalRead(CENTER);
    int right=digitalRead(RIGHT);
    int m_right=digitalRead(MUCH_RIGHT);

    //concating sensor readings together
    int readings = m_left*10000 + left*1000 + center*100 + right*10 + m_right;
    Serial.print("\n");
    Serial.print(m_left);
    Serial.print("\t");
    Serial.print(left);
    Serial.print("\t");
    Serial.print(center);
    Serial.print("\t");
    Serial.print(right);
    Serial.print("\t");
    Serial.print(m_right);
    Serial.print("\n");
    Serial.print(readings);
   
    switch (readings) {
    case 10000:    // very left sensor detects line
        SlightLeft();
        break;

    case 1000:    //  slightly left sensor detects line
        SlightLeft();
        break;

    case 100:
        Forward();
        break;

    case 10:
        SlightRight();
        break;

    case 1:
        SlightRight();
        break;

    //ADD MORE CASES

    case 11100: //90:degree left

        HardLeft();
        break;
      
    case 111: //90:degree right

        HardRight();
        break;

    

    default:  // if no cases are met execute the default statement
        Forward();  
        break;

    }}
