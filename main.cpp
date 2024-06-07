#define ena 8
#define in1 32
#define in2 34
#define in3 36
#define in4 38
#define enb 7
int front = 220;
int back = 200;

const int trigPin = 3;
const int echoPin = 2;
// defines variables
long duration;
int distance;

void setup(){
   pinMode(ena, OUTPUT);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
   pinMode(in4, OUTPUT);
   pinMode(enb, OUTPUT);

   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

void loop() {
  
  analogWrite(ena, front);
  analogWrite(enb, back);

  //digitalWrite(in1, HIGH);
  //digitalWrite(in2, LOW);

  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(1000);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 50) {
    analogWrite(enb, back - 50);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    delay(1500);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

        analogWrite(enb, back - 100);
        digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);


    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(800);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);


    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
    
  } else {
    analogWrite(enb, back - 50);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(1500);
    
  }

  delay(2000);

  analogWrite(enb, back);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(1200);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  



  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  exit(0);

  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);

  /*

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(4000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  exit(0);
  */
  
  

  
  
}
