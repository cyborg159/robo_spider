/*
 * spider_bluetooth.ino
 *
 *  Created on: Aug 21, 2016
 *      Author: cyborg159
 *
 * Do NOT use this code for: commercial purposes or mass application.
 */

#include "Arduino.h"
#include "Servo.h"
#include "SoftwareSerial.h"

#include "spider_bluetooth_functions.h"


char c; // stores incoming character from other device

// The setup function is called once at startup of the sketch
void setup() {
    BT.begin(9600); // set baud rate of bluetooth module

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
  while (BT.available())
    // if text arrived in from BT serial...
    {
      c=(BT.read());

      // known BT commands
      switch(c){
        case 's' : BodyUp(); break;
        case 'e' : BodyDown(); break;
        case 'n' : init_nor(); break;
        case '1' : init_stepF(); stepF(); break;
        case '2' : init_turnL(); turnL(); break;
        case '3' : init_turnR(); turnR(); break;
      }
    }

}
