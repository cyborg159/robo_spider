/*
 * spider_walk.ino
 *
 *  Created on: July 30, 2016
 *      Author: cyborg159
 * 
 * Do NOT use this code for: commercial purposes, mass application.
 */

#include "Arduino.h"
#include "Servo.h"

Servo //vertical
	  vL1, vR1,
      vL2, vR2,
      vL3, vR3,

	  //horizontal
      hL1, hR1,
      hL2, hR2,
      hL3, hR3;

//initialization positions of each servo
short posvL1 = 65,  //up '-', down '+'
	  posvR1 = 120, //up '-', down '+'
	  posvL2 = 48,  //up '+', down '-'
	  posvR2 = 5,   //up '-', down '+'
	  posvL3 = 60,	//up '+', down '-'
	  posvR3 = 85,	//up '-', down '+'

	  poshL1 = 40,	//forward '+', backward '-'
	  poshR1 = 100,	//forward '-', backward '+'
	  poshL2 = 77,	//forward '+', backward '-'
	  poshR2 = 75,	//forward '+', backward '-'
	  poshL3 = 45,	//forward '+', backward '-'
	  poshR3 = 95;	//forward '-', backward '+'

const byte time = 5, //delay in ms
		   angleH= 40, //value of turning horizontal servos
		   angleV = 60; //value of turning vertical servos

void BodyUp(){
  for(int i = 0; i < angleV; i++){
    vL1.write(++posvL1);
    vL2.write(--posvL2);
    vL3.write(--posvL3);
    vR1.write(++posvR1);
    vR2.write(++posvR2);
    vR3.write(++posvR3);
    delay (time);
  }
}

void BodyDown(){
  for(int i = 0; i < angleV; i++){
    vL1.write(--posvL1);
    vL2.write(++posvL2);
    vL3.write(++posvL3);
    vR1.write(--posvR1);
    vR2.write(--posvR2);
    vR3.write(--posvR3);
    delay(time);
  }
}

void LegsUpL(){
  for(int i = 0; i < angleV; i++){
    vL1.write(--posvL1);
    vR2.write(--posvR2);
    vL3.write(++posvL3);
    delay(time);
  }
}

void LegsDownL(){
  for(int i = 0; i < angleV; i++){
    vL1.write(++posvL1);
    vR2.write(++posvR2);
    vL3.write(--posvL3);
    delay (time);
  }
}

void LegsUpR(){
  for(int i = 0; i < angleV; i++){
    vR1.write(--posvR1);
    vL2.write(++posvL2);
    vR3.write(--posvR3);
    delay(time);
  }
}

void LegsDownR(){
  for(int i = 0; i < angleV; i++){
    vR1.write(++posvR1);
    vL2.write(--posvL2);
    vR3.write(++posvR3);
    delay (time);
  }
}

void LegsForwR(){
 for(int i = 0; i < angleH; i++){
    hR1.write(--poshR1);
    hR3.write(--poshR3);
    hL2.write(37+2*i);
    delay(time);
 }
}

void LegsBackR(){
  for(int i = 0; i < angleH; i++){
    hR1.write(++poshR1);
    hR3.write(++poshR3);
    hL2.write(117-2*i);
    delay(time);
  }
}

void LegsForwL(){
 for(int i = 0; i < angleH; i++){
    hL1.write(++poshL1);
    hL3.write(++poshL3);
    hR2.write(30+2*i);
    delay(time);
 }
}

void LegsBackL(){
  for(int i = 0; i < angleH; i++){
    hL1.write(--poshL1);
    hL3.write(--poshL3);
    hR2.write(110-2*i);
    delay(time);
  }
}

//set each servo to it's initialization position
void init_nor(){
  vL1.write(posvL1);
  vR1.write(posvR1);
  vL2.write(posvL2);
  vR2.write(posvR2);
  vL3.write(posvL3);
  vR3.write(posvR3);

  hL1.write(poshL1);
  hR1.write(poshR1);
  hL2.write(poshL2);
  hR2.write(poshR2);
  hL3.write(poshL3);
  hR3.write(poshR3);
}

//set each horizontal servo to position for moving body forward
void init_stepF(){
    hL1.write(50);
    hR1.write(90);
    hL2.write(37);
    hR2.write(23);
    hL3.write(45);
    hR3.write(90);
}

//set each horizontal servo to position for turning body to left
void init_turnL(){
    hL1.write(90);
    hR1.write(70);
    hL2.write(77);
    hR2.write(70);
    hL3.write(85);
    hR3.write(130);
}

//set each horizontal servo to position for turning body to right
void init_turnR(){
    hL1.write(70);
    hR1.write(50);
    hL2.write(77);
    hR2.write(70);
    hL3.write(5);
    hR3.write(55);
}

//one step forward
void stepF(){
  init_stepF();
  LegsUpR();
  LegsForwR();
  LegsDownR();
  LegsUpL();
  LegsBackR();
  LegsForwL();
  LegsDownL();
  LegsUpR();
  LegsBackL();
  LegsDownR();
}

//turn body to left
void turnL(){
  init_turnL();

  LegsUpR();

  //turn right legs forward and left leg backward
  for(int i = 0; i < angleH; i++){
    hR1.write(70-i);
    hR3.write(130-i);
    hL2.write(77-i);
    delay(time);
  }

  LegsDownR();
  LegsUpL();

  //turn right legs backward and left leg forward
  for(int i = 0; i < angleH; i++){
    hR1.write(30+i);
    hR3.write(90+i);
    hL2.write(37+i);
    delay(time);
  }

  //turn left legs backward and right leg forward
  for(int i = 0; i < angleH; i++){
    hL1.write(90-i);
    hL3.write(85-i);
    hR3.write(130-i);
    delay(time);
  }

  LegsDownL();
  LegsUpR();

  //turn left legs forward and right leg backward
  for(int i = 0; i < angleH; i++){
    hL1.write(50+i);
    hL3.write(45+i);
    hR3.write(90+i);
    delay(time);
  }

  LegsDownR();
}

//turn body to right
 void turnR(){
  init_turnR();

  LegsUpL();

  //turn left legs forward and right leg backward
  for(int i = 0; i < angleH; i++){
    hL1.write(70+i);
    hL3.write(5+i);
    hR2.write(70-i);
    delay(time);
  }

  LegsDownL();
  LegsUpR();

  //turn left legs backward and right leg forward
  for(int i = 0; i < angleH; i++){
    hL1.write(110-i);
    hL3.write(45-i);
    hR2.write(30+i);
    delay(time);
  }

  //turn right legs backward and left leg forward
  for(int i = 0; i < angleH; i++){
    hR1.write(50+i);
    hR3.write(55+i);
    hL2.write(77+i);
    delay(time);
  }

  LegsDownR();
  LegsUpL();

  //turn right legs forward and left leg backward
  for(int i = 0; i < angleH; i++){
    hR1.write(90-i);
    hR3.write(95-i);
    hL2.write(117-i);
    delay(time);
  }

  LegsDownL();
}

//The setup function is called once at startup of the sketch
void setup() {

    vL1.attach(13);
    vR1.attach(12);
    vL2.attach(11);
    vR2.attach(10);
    vL3.attach(9);
    vR3.attach(8);

    hL1.attach(7);
    hR1.attach(6);
    hL2.attach(5);
    hR2.attach(4);
    hL3.attach(3);
    hR3.attach(2);

    init_nor();
}

// The loop function is called in an endless loop
void loop() {
  //walking in the square

  BodyUp();

  for(int i = 0; i < 4; i++){
	  init_stepF();
	  for(int j = 0; j < 3; j++){
		  stepF();
	  }
	  init_turnL();
	  for(int j = 0; j < 4; j++){
		  turnL();
	  }
  }

  BodyDown();

}
