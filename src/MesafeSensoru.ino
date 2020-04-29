#define TRIG 9
#define ECHO 10
#define SARI 8
#define KIRMIZI 7
#define MAVI 6

int mesafeOlc(int trigPin,int echoPin) {
  
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  return distance;
}

void pinleriTemizle(int pin1,int pin2,int pin3){
   digitalWrite(pin1, LOW); 
   digitalWrite(pin2, LOW); 
   digitalWrite(pin3, LOW); 
}

void setup() {
  pinMode(TRIG, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(SARI, OUTPUT);
  pinMode(KIRMIZI, OUTPUT);
  pinMode(MAVI, OUTPUT);
}

void loop() {
  int distance = mesafeOlc(TRIG,ECHO);
  Serial.print("distance: ");
  Serial.println(distance);
  pinleriTemizle(SARI,KIRMIZI,MAVI);
  if (distance<10){
   digitalWrite(KIRMIZI, HIGH);  
  }
  if (10<distance && distance<50){
   digitalWrite(SARI, HIGH);  
  }
    if (distance>50){
   digitalWrite(MAVI, HIGH);  
  }
 
}
