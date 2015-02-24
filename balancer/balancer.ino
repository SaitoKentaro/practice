const int motor1A = 8;
const int motor1P = 9;
const int motor2A = 10;
const int motor2P = 11;

int c = 0;
int u,d;
int Kp = 1;
int Ki = 1;
int center = 515;

void setup(){
  Serial.begin(9600);
  pinMode(motor1A,OUTPUT);
  pinMode(motor1P,OUTPUT);
  pinMode(motor2A,OUTPUT);
  pinMode(motor2P,OUTPUT);
}

int P_I(int x,int y){
  
  int a=(x+y)/2;//今回の偏差と前回の偏差の平均
  
  return Kp*x+Ki*a;
}

void foward(){
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(5);
  digitalWrite(8,LOW);
  delay(5);
}

void back(){
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(5);
  digitalWrite(9,LOW);
  delay(5);
}

void loop(){
  long x;
  x = analogRead(0);
  d=c;//前回の偏差
  c=center-x;// 今回の偏差
  
  u=P_I(c,d);//出力
  
  if(x>center){
    analogWrite(10,125);
    analogWrite(11,LOW);
    back();
  }else{
    analogWrite(10,LOW);
    analogWrite(11,125);
    foward();
  }
  
  delay(5);
}
