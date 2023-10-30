/*Eyeball Twitch Pumpkin
 * Idea by 68percentwater
 * Modified for Learn Robotics by Liz Miller
 * Full tutorial on www.learnrobotics.org/blog
 * 
 * This code generates a random position for four groups of 3 servos (12 total servos)
 * Place eyeballs from each group around the surface of the pumpkin
 * Code compiles but is untested. Use with caution.
 */

#include <Servo.h>  //this is a servo library

Servo eyeOne;    // servos on pin 8
Servo eyeTwo;    // servos on pin 7
Servo eyeThree;  // servos on pin 6
Servo eyeFour;   // servos on pin 5
Servo eyeFive;   // servos on pin 3

const unsigned long eyeDelay = 1000;

unsigned long lastTimeOne;
unsigned long lastTimeTwo;
unsigned long lastTimeThree;
unsigned long lastTimeFour;
unsigned long lastTimeFive;

int pos = 90;  //eyeball starting position
int deg = 0;
unsigned int blink = 0;
int ledPin = 13;


//initialization - runs once
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  //connect the servo objects
  eyeOne.attach(7);
  eyeTwo.attach(6);
  eyeThree.attach(5);
  eyeFour.attach(4);
  eyeFive.attach(3);

  //initialize the eye in the center (90-deg)
  eyeOne.write(pos);
  eyeTwo.write(pos);
  eyeThree.write(pos);
  eyeFour.write(pos);
  eyeFive.write(pos);
  lastTimeOne = millis() + random(0, 500);
  lastTimeTwo = millis() + random(0, 500);
  lastTimeThree = millis() + random(0, 500);
  lastTimeFour = millis() + random(0, 500);
  lastTimeFive = millis() + random(0, 500);
}

// picks a random position to move the servo
// this gives the appearance of a "twitching eyeball"

void randomTwitch(Servo eyeBall, int msecs) {
  delay(msecs);
  deg = random(10, 170);
  eyeBall.write(deg);
}

// picks a random position to move the servo
// this gives the appearance of a "twitching eyeball"

void randomTwitch(Servo eyeBall, unsigned long *lastTime) {
  const unsigned long current = millis();
  if (current - *lastTime >= eyeDelay + random(0, 1000)) {
    deg = random(10, 165);
    eyeBall.write(deg);
    *lastTime = current;
  }
}

void randomBlink() {
  /*
  blink = random(0, 3);
  if (blink == 0) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);*/
  analogWrite(ledPin, random(80) + 110);
}

//runs forever
void loop() {
  randomTwitch(eyeOne, &lastTimeOne);
  randomTwitch(eyeTwo, &lastTimeTwo);
  randomTwitch(eyeThree, &lastTimeThree);
  randomTwitch(eyeFour, &lastTimeFour);
  randomTwitch(eyeFive, &lastTimeFive);
  //delay(random(400)+50);
  randomBlink();
  delay(100);
}
