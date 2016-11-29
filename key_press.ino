//The Car uses two motors for the rear left and right whhels and a Swiveling Front Caster wheel. 

int led1=13; //Inputs for the 2 motors.Each motor has 2 inputs. 
int led2=12; // Depending on which of them is and which is low the motor rotates in one direction and vice versa.
int led3=8;
int led4=9;
int horn_pin=4 ;
void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(5,HIGH); //enable pins 
  digitalWrite(6,HIGH);
}
void move_forward(){
  digitalWrite(led1,HIGH); 
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  
}
void move_backward(){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
}

void stop_it(){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
}
void horn(){
  digitalWrite(horn_pin,HIGH);
  delay(1000);
  digitalWrite(horn_pin,LOW);
}
void turn_right(){
  digitalWrite(led1,LOW);     // To turn right, the left wheel should move forward while right should be stopped.
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  
}
void turn_left(){            // To turn left, the right wheel should move forward while the left one shoyuld be stopped.
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  
}
  
  
  
void loop(){

  while(Serial.available()==0);             
  char comm= (char) Serial.read();        //Reads Input coming from laptop over bluetooth.
  if(comm=='w'){
    move_forward();
  }
  else if(comm=='s'){
    move_backward();
  }
  else if(comm=='t'){
    stop_it();
  }
   else if(comm=='d'){
     turn_right();
     delay(1000);
     stop_it();
   }
   else if(comm=='a'){
     turn_left();
     delay(1000);
     stop_it();
   }
   else if (comm=='h'){
     horn();
     
   }
  }



