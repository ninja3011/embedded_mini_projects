int in3= 7;
int in4=6;
int enb= 9;  
int pd2 = 2;
int pd3 = 3;
int pd4 = 4;
float duty_cycle=1;

void setup(){ 
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(pd2, INPUT);
  pinMode(pd3, INPUT);
  pinMode(pd4, INPUT);
}

void analogWriter(float a){
  if(a>0 && a<=255){
  duty_cycle = a/255.0;
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enb, HIGH);
  delay(1000*duty_cycle);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
  else{
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("not between 0 and 255");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(pd2) == LOW) && (digitalRead(pd3) == LOW) && (digitalRead(pd4) == LOW)){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enb, HIGH);
  Serial.println("0");
  }
  else if((digitalRead(pd3) == LOW) && (digitalRead(pd2) == LOW)){
  analogWriter(192);
  Serial.println("75");
  }
  else if((digitalRead(pd4) == LOW) && (digitalRead(pd2) == LOW)){
  analogWriter(128);
  Serial.println("50");
  }
  else if((digitalRead(pd4) == LOW) && (digitalRead(pd3) == LOW)){
  analogWriter(64);
  Serial.println("25");
  }
  else{
  Serial.println("dont know whats going on");
  }
  

  delay(1000*(1-duty_cycle));
}
