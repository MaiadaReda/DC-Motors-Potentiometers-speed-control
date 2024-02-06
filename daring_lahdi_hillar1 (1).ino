int switch1= 12;
int switch2 = 11;
int h1 = 3;
int h2 = 5;
int sensorvalue=0;
int hobbyvalue=0;
int sensorvalue2=0;
int hobbyvalue2=0;
int read=0;

void setup() {
 pinMode(switch1,INPUT);
 pinMode(switch2,INPUT);
 pinMode(A0,INPUT);
 pinMode(A2,INPUT);
 pinMode(h1,OUTPUT);
 pinMode(h2,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  if(digitalRead(switch1)==HIGH){
  sensorvalue=analogRead(A0);
  hobbyvalue= map(sensorvalue, 0 , 1023 , 1 , 255);
  analogWrite(h1,hobbyvalue);
  }
  else if(Serial.available()>0) {read=Serial.read();
    switch(read){
     case 'M' :
               sensorvalue=analogRead(A0);
               hobbyvalue= map(sensorvalue, 0 , 1023 , 1 , 255);
               analogWrite(h1,hobbyvalue);
      break;}}
  if(digitalRead(switch2)==HIGH){
  sensorvalue2=analogRead(A2);
  hobbyvalue2= map(sensorvalue2, 0 , 1023 , 1 , 255);
  analogWrite(h2,hobbyvalue2);
  }
  else if (Serial.available()>0) {read=Serial.read();
    switch(read){
    case 'L' : 
               sensorvalue2=analogRead(A2);
               hobbyvalue2= map(sensorvalue2, 0 , 1023 , 1 , 255);
               analogWrite(h2,hobbyvalue2);
               break;
  }}
  }