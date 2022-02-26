#define r1 44
#define y1 46
#define g1 48
#define s1 34//Sensor at S2

#define r2 36
#define y2 38
#define g2 40
#define s2 43//Sensor at S3

#define r3 45
#define y3 47
#define g3 49
#define s3 35//Sensor at S4

#define r4 37
#define y4 39
#define g4 41
#define s4 42//Sensor at S1

int a=1,b=1,c=1,d=1;

void setup()
{
  //LEDs
  pinMode(r1,OUTPUT);
  pinMode(y1,OUTPUT);
  pinMode(g1,OUTPUT);

  pinMode(r2,OUTPUT);
  pinMode(y2,OUTPUT);
  pinMode(g2,OUTPUT);

  pinMode(r3,OUTPUT);
  pinMode(y3,OUTPUT);
  pinMode(g3,OUTPUT);

  pinMode(r4,OUTPUT);
  pinMode(y4,OUTPUT);
  pinMode(g4,OUTPUT);
  
  //Sensors
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  initial();
  sensors_read();
  if(a==1&&b==1&&c==1&&d==1)//no traffic
    initial();
  else if(a==0&&b==1&&c==1&&d==1)//A has traffic
  {
    signal_1();
    delay(7500);
    stop_1();  
  }
  else if(a==1&&b==0&&c==1&&d==1)//B has traffic
  {
    signal_2();
    delay(7500);
    stop_2();  
  }
  else if(a==1&&b==1&&c==0&&d==1)//C has traffic
  {
    signal_3();
    delay(7500);
    stop_3();  
  }
  else if(a==1&&b==1&&c==1&&d==0)//D has traffic
  {
    signal_4();
    delay(7500);
    stop_4();  
  }
  else if(a==0&&b==0&&c==1&&d==1)//A & B have traffic
  {
    signal_1();
    delay(7500);
    stop_1();
    delay(250);
    signal_2();
    delay(7500);
    stop_2();  
  }
  else if(a==1&&b==0&&c==0&&d==1)//B & C have traffic
  {
    signal_2();
    delay(7500);
    stop_2();
    delay(250);
    signal_3();
    delay(7500);
    stop_3();  
  }
  else if(a==1&&b==1&&c==0&&d==0)//C & D have traffic
  {
    signal_3();
    delay(7500);
    stop_3();
    delay(250);
    signal_4();
    delay(7500);
    stop_4();  
  }
  else if(a==0&&b==1&&c==1&&d==0)//D & A have traffic
  {
    signal_4();
    delay(7500);
    stop_4();
    delay(250);
    signal_1();
    delay(7500);
    stop_1();  
  }
  else if(a==1&&b==0&&c==1&&d==0)//D & B have traffic
  {
    signal_4();
    delay(7500);
    stop_4();
    delay(250);
    signal_2();
    delay(7500);
    stop_2();  
  }
  else if(a==0&&b==1&&c==0&&d==1)//C & A have traffic
  {
    signal_3();
    delay(7500);
    stop_3();
    delay(250);
    signal_1();
    delay(7500);
    stop_1();  
  }
  else if(a==1&&b==0&&c==0&&d==0)//B, C & D have traffic | A doesn't have traffic
  {
    signal_2();
    delay(7500);
    stop_2();
    delay(250);
    signal_3();
    delay(7500);
    stop_3();
    delay(250);
    signal_4();
    delay(7500);
    stop_4();  
  }
  else if(a==0&&b==1&&c==0&&d==0)//A, C & D have traffic | B doesn't have traffic
  {
    signal_1();
    delay(7500);
    stop_1();
    delay(250);
    signal_3();
    delay(7500);
    stop_3();
    delay(250);
    signal_4();
    delay(7500);
    stop_4();  
  }
  else if(a==0&&b==0&&c==1&&d==0)//A, B & D have traffic | C doesn't have traffic
  {
    signal_1();
    delay(7500);
    stop_1();
    delay(250);
    signal_2();
    delay(7500);
    stop_2();
    delay(250);
    signal_4();
    delay(7500);
    stop_4();  
  }
  else if(a==0&&b==0&&c==0&&d==1)//A, B & C have traffic | D doesn't have traffic
  {
    signal_1();
    delay(7500);
    stop_1();
    delay(250);
    signal_2();
    delay(7500);
    stop_2();
    delay(250);
    signal_3();
    delay(7500);
    stop_3();  
  }
  else //all lanes have equal traffic
  {
    signal_1();
    delay(4500);
    stop_1();
    delay(250);
    signal_2();
    delay(4500);
    stop_2();
    delay(250);
    signal_3();
    delay(4500);
    stop_3();
    delay(250);
    signal_4();
    delay(4500);
    stop_4(); 
  }
}

void initial()
{
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  delay(500);
  return;
}

void sensors_read()
{
  a=digitalRead(s1);
  b=digitalRead(s2);
  c=digitalRead(s3);
  d=digitalRead(s4);
}

void signal_1()
{
  Serial.println("Signal 1 is green");
  digitalWrite(r1, LOW);
  digitalWrite(y1, LOW);
  digitalWrite(g1, HIGH);
}

void stop_1()
{
  Serial.println("Signal 1 is yellow");
  digitalWrite(r1, LOW);
  digitalWrite(y1, HIGH);
  digitalWrite(g1, LOW);
  delay(1500);
  Serial.println("Signal 1 is red");
  digitalWrite(r1, HIGH);
  digitalWrite(y1, LOW);
  digitalWrite(g1, LOW);
}

void signal_2()
{
  Serial.println("Signal 2 is green");
  digitalWrite(r2, LOW);
  digitalWrite(y2, LOW);
  digitalWrite(g2, HIGH);
}

void stop_2()
{
  Serial.println("Signal 2 is yellow");
  digitalWrite(r2, LOW);
  digitalWrite(y2, HIGH);
  digitalWrite(g2, LOW);
  delay(1500);
  Serial.println("Signal 2 is red");
  digitalWrite(r2, HIGH);
  digitalWrite(y2, LOW);
  digitalWrite(g2, LOW);
}

void signal_3()
{
  Serial.println("Signal 3 is green");
  digitalWrite(r3, LOW);
  digitalWrite(y3, LOW);
  digitalWrite(g3, HIGH);
}

void stop_3()
{
  Serial.println("Signal 3 is yellow");
  digitalWrite(r3, LOW);
  digitalWrite(y3, HIGH);
  digitalWrite(g3, LOW);
  delay(1500);
  Serial.println("Signal 3 is red");
  digitalWrite(r3, HIGH);
  digitalWrite(y3, LOW);
  digitalWrite(g3, LOW);
}

void signal_4()
{
  Serial.println("Signal 4 is green");
  digitalWrite(r4, LOW);
  digitalWrite(y4, LOW);
  digitalWrite(g4, HIGH);
}

void stop_4()
{
  Serial.println("Signal 4 is yellow");
  digitalWrite(r4, LOW);
  digitalWrite(y4, HIGH);
  digitalWrite(g4, LOW);
  delay(1500);
  Serial.println("Signal 4 is red");
  digitalWrite(r4, HIGH);
  digitalWrite(y4, LOW);
  digitalWrite(g4, LOW);
}
