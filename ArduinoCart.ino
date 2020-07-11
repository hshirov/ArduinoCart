String command;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;

void setup() {
pinMode(in1,OUTPUT);   //left motors forward
pinMode(in2,OUTPUT);   //left motors reverse
pinMode(in3,OUTPUT);   //right motors forward
pinMode(in4,OUTPUT);   //right motors reverse
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  command = Serial.read();
  Serial.println(command);
}
 
if(command == "FORWARD"){            //move forward(all motors rotate in forward direction)
  digitalWrite(in1,HIGH);
  digitalWrite(in3,HIGH);
}
 
else if(command == "BACKWARD"){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(in2,HIGH);
  digitalWrite(in4,HIGH);
}
 
else if(command == "LEFT"){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(in3,HIGH);
}
 
else if(command == "RIGHT"){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(in1,HIGH);
}
 
else if(command == "STOP"){      //STOP (all motors stop)
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
delay(100);
}
