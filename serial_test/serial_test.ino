int pins[] = {30, 32, 34, 36, 38, 40};
//int counter = 0;

void setup() {
  Serial.begin(115200);
  for(int i = 30; i<=40; i+=2){
    pinMode(i, OUTPUT);
    }
}

void loop() {
    if(Serial.available()){
      digitalWrite(pins[0], HIGH); 
      /*counter++;
      if(counter == 6){
        counter = 0;
      }
     }
     else{
      digitalWrite(pins[counter], LOW);
      counter++;
      if(counter == 6){
        counter = 0;
        }
        */
      }
      
    }



/*Serial.println("Enter your name.");
    while (Serial.available() == 0){}
    names = Serial.readString(); //Reading the Input string from Serial port.  
    Serial.println("Enter your Moblie No.");  
    //while (Serial.available() == 0) {}  
    Mobile = Serial.readString();  
    Serial.println("Enter your Address.");  
    //while (Serial.available() == 0) {}  
    Address = Serial.readString();  
    Serial.println("Enter your Email.");  
    //while (Serial.available() == 0) {}  
    Email = Serial.readString();  
    Serial.println("-------------------------"); //Showing the details  
    Serial.println("YOUR NAME:" + names);  
    Serial.println("YOUR MOBILE NO:" + Mobile);  
    Serial.println("YOUR ADDRESS:" + Address);  
    Serial.println("YOUR EMAIL:" + Email);  
    Serial.println("Thanks You...");  
    Serial.println("");  
    //while (Serial.available() == 0) {}
    */
