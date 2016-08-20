/*
 * spider_servo_test_BT_functions.h
 *
 *  Created on: Aug 20, 2016
 *      Author: richard
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
