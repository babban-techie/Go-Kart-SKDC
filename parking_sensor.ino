#include <NewPing.h>
 
#define TRIGGER_PIN  13
#define ECHO_PIN     12
#define MAX_DISTANCE 200
#define RED 11
#define GREEN 10
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(115200);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
}
 
void loop() {
  int x = sonar.ping_cm();
  delay(50);
  if (x>20 || x==0)
  {
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
  }
  else
  {
    digitalWrite(GREEN,LOW);
    digitalWrite(RED,HIGH);
  }
  Serial.print("Ping: ");
  Serial.print(x);
  Serial.println("cm");
}
