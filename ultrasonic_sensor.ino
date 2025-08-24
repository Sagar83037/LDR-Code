#define trigPin 11
#define echoPin 9



void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  
}


void loop(){
  long duration;
  float distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2.0)/29.1;

  if (distance>=100 || distance<= 0){
    Serial.println("beyond limit");
    
  }
  else if (distance <=40 ){
    Serial.print(distance);
    Serial.println("cm");
    digitalWrite(4,HIGH);
    delay(2000);
    
  }
    
  else{
    Serial.print(distance);
    Serial.println("cm");
  }
  delay(500);
}
