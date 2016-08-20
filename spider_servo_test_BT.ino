/*
 * spider_servo_test_BT.ino
 *
 *  Created on: Aug 21, 2016
 *      Author: cyborg159
 *
 * Do NOT use this code for: commercial purposes or mass application.
 */

#include "Arduino.h"
#include "Servo.h"
#include "SoftwareSerial.h"

#include "spider_servo_test_BT_functions.h"

char c; // stores incoming character from other device

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop()
{
	while (BT.available())
	    // if text arrived in from BT serial...
	    {
	      c=(BT.read());

	      // known BT commands
	      switch(c){
	        //verticals
	        case '1' : vert1(); break;
	        case '2' : vert2(); break;
	        case '3' : vert3(); break;
	        case '4' : vert4(); break;
	        case '5' : vert5(); break;
	        case '6' : vert6(); break;

	        //horizontals
	        case 'a' : horiz1(); break;
	       	case 'b' : horiz2(); break;
	       	case 'c' : horiz3(); break;
	       	case 'd' : horiz4(); break;
	       	case 'e' : horiz5(); break;
	       	case 'f' : horiz6(); break;
	      }
	    }
}
