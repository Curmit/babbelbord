void setup() {
  // put your setup code here, to run once:
  pinMode(42,INPUT);
  pinMode(44,INPUT);
  pinMode(46,INPUT);
  pinMode(48,INPUT);
  pinMode(50,INPUT);
  
  pinMode(52,OUTPUT);
  pinMode(53,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(22,OUTPUT);

  digitalWrite(52,HIGH);
  digitalWrite(53,HIGH);
  digitalWrite(25,HIGH);
  digitalWrite(23,HIGH);
  digitalWrite(22,HIGH);

  Serial.begin(9600);
  Serial.println("1:\t2:\t3:\t4:\t5:");
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp[5] = {0};
  temp[0] = digitalRead(42);
  temp[1] = digitalRead(44);
  temp[2] = digitalRead(46);
  temp[3] = digitalRead(48);
  temp[4] = digitalRead(50);

  for (int i = 0; i < 5; i++)
  {
    if (temp[i] == HIGH)
      Serial.print("HIGH\t");
    else
      Serial.print("LOW\t");
  }
  Serial.println();
  delay(500);
}
