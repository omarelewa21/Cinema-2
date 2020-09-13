int pins[] = {2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3};
int Movements[] = {2,3,6,7,4,5};
int effects[] = {A3, A2, A1};
long moves[7];
int nrows;
int count;


void all_default(){
  for(int i = 0; i < 16; i++){
    digitalWrite(pins[i], HIGH);
    }
  }

/*void printall(){
  for(int i = 0; i<16; i++){
    Serial.print(digitalRead(pins[i]));
    }
    Serial.println();
  }

void default_pos(){
  for(int i = 0; i < 6; i++){
    digitalWrite(Movements[i], HIGH);
    }
  }

void allup(){
  // all pistons goes up
  for(int i = 0; i < 6; i++){
    digitalWrite(Movements[i], LOW);
    }
   delay(delaytime);
   printall();
   for(int i = 0; i < 6; i++){
    digitalWrite(Movements[i], HIGH);
    }
}

void roll_left(){
  digitalWrite(Movements[0], LOW);
  digitalWrite(Movements[1], LOW);
  delay(delaytime);
  digitalWrite(Movements[0], HIGH);
  digitalWrite(Movements[1], HIGH);
  }

void pitch_down(){
  digitalWrite(Movements[4], LOW);
  digitalWrite(Movements[5], LOW);
  delay(delaytime);
  digitalWrite(Movements[4], HIGH);
  digitalWrite(Movements[5], HIGH);
  }

void roll_right(){
  digitalWrite(Movements[2], LOW);
  digitalWrite(Movements[3], LOW);
  delay(delaytime);
  digitalWrite(Movements[2], HIGH);
  digitalWrite(Movements[3], HIGH);
  }

void light_effect(){
  digitalWrite(effects[0], LOW);
  delay(delaytime);
  digitalWrite(effects[0], HIGH);
  }

void bubbles(){
  digitalWrite(effects[1], LOW);
  delay(delaytime);
  digitalWrite(effects[1], HIGH);
  }

void smoke(){
  digitalWrite(effects[2], LOW);
  delay(delaytime);
  digitalWrite(effects[2], HIGH);
  }
*/

void setup() {
  Serial.begin(115200);
  
  for(int i =0; i<16; i++){
    pinMode(pins[i], OUTPUT);
  };
  
  all_default();
  
  if(Serial.available()){
      nrows = Serial.read();
    }
   
   Serial.end();
   count  = nrows;
}

void loop() {
  while(count > 0){
    Serial.begin(115200);
    for (int i  = 0; i<7; i++){
      if(Serial.available()){
        moves[i] = Serial.read();
      }
     }
     Serial.flush();
  
     for(int i = 0; i<6; i++){
      digitalWrite(Movements[i], moves[i]); 
     }
     delay(moves[6]);
     Serial.end();
     count = count-1;
  }
}
