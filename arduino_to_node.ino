const int trigPin = 9;
const int echoPin = 10;
const int ledr = 2;
const int ledg = 4;
bool avail = true;
bool prevavail  = true;
long duration;
int distance;

void setup() {
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  
  if(distance >=20){
    avail = true;
    digitalWrite(ledr, LOW);
    digitalWrite(ledg, HIGH);

  }else{
    avail = false;
    digitalWrite(ledr, HIGH);
    digitalWrite(ledg, LOW);

  }
  if(avail != prevavail){
    Serial.println(avail);
    prevavail=avail;
  }



}