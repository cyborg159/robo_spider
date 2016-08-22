/*
 * spider_servo_test_BT_functions.h
 *
 *  Created on: Aug 20, 2016
 *      Author: cyborg159
 */

#ifndef SPIDER_SERVO_TEST_BT_FUNCTIONS_H_
#define SPIDER_SERVO_TEST_BT_FUNCTIONS_H_

Servo // vertical
	  vL1, vR1,
      vL2, vR2,
      vL3, vR3,

	  // horizontal
      hL1, hR1,
      hL2, hR2,
      hL3, hR3;

SoftwareSerial BT(1,0);
// creates a "virtual" serial port/UART
// connect BT module TX to D1
// connect BT module RX to D0
// connect BT Vcc to 5V, GND to GND

short posvL1 = 0,
	  posvR1 = 0,
	  posvL2 = 180,
	  posvR2 = 0,
	  posvL3 = 180,
	  posvR3 = 0,

	  poshL1 = 40,
	  poshR1 = 100,
	  poshL2 = 77,
	  poshR2 = 75,
	  poshL3 = 45,
	  poshR3 = 95;

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

void vert1(){
	for(int i = 0; i <= 180; i++){
		vL1.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vL1.write(i);
	}
}

void vert2(){
	for(int i = 0; i <= 180; i++){
		vR1.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vR1.write(i);
	}
}

void vert3(){
	for(int i = 0; i <= 180; i++){
		vL2.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vL2.write(i);
	}
}

void vert4(){
	for(int i = 0; i <= 180; i++){
		vR2.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vR2.write(i);
	}
}

void vert5(){
	for(int i = 0; i <= 180; i++){
		vL3.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vL3.write(i);
	}
}

void vert6(){
	for(int i = 0; i <= 180; i++){
		vR3.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vR3.write(i);
	}
}

void horiz1(){
	for(int i = 0; i <= 180; i++){
		vL1.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vL1.write(i);
	}
}

void horiz2(){
	for(int i = 0; i <= 180; i++){
		vR1.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vR1.write(i);
	}
}

void horiz3(){
	for(int i = 0; i <= 180; i++){
		vL2.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vL2.write(i);
	}
}

void horiz4(){
	for(int i = 0; i <= 180; i++){
		vR2.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vR2.write(i);
	}
}

void horiz5(){
	for(int i = 0; i <= 180; i++){
		vL3.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vL3.write(i);
	}
}

void horiz6(){
	for(int i = 0; i <= 180; i++){
		vR3.write(i);
	}
	for(int i = 180; i >= 0; i--){
		vR3.write(i);
	}
}

#endif /* SPIDER_SERVO_TEST_BT_FUNCTIONS_H_ */
