/*
 * lab2.c
 *
 *  Created on: Sep 12, 2024
 *      Author: sg15
 */

#include "movment.h"
#include "cyBot_uart.h"

//must have a main function somewhere, computer does not like it when there is no main function. you get the error there are weird symbols.
//void main() {
//
//    ///Allocate and clear all memory for OI Struct
//    oi_t *sensor = oi_alloc();
//
//    ///Initialize open interface
//    oi_init(sensor);
//
//    int i = 0;
//
//    //this for loop moves the iRobot in a box
//    for(i = 0; i < 4; i++){
//        //moves the iRobot forward 50 centimeters
//        move_forward(sensor, 50);
//        //turns the iRobot clockwise 90 degrees
//        turn_clockwise(sensor, 75);
//    }
//
//    //deletes the sensor information (variable)
//    oi_free(sensor);
//
//}

//int main() {
//
//    ///Allocate and clear all memory for OI Struct
//    oi_t *sensor = oi_alloc();
//
//    ///Initialize open interface
//    oi_init(sensor);
//
//    //moves forward 2 meters without any bumps
//    move_forward2(sensor, 200);
//
//    //deletes the sensor information (variable)
//    oi_free(sensor);
//
//    return 0;
//
//}



int main(){
    cyBot_uart_init();
    lcd_init();
    oi_t* sensor = oi_alloc();
    oi_init(sensor);

//    while (1) {
//        int received = cyBot_getByte();
//        lcd_putc((char)(received));
//    }

//    while(1){
//    int received = cyBot_getByte();
//    char convertedChar = (char)(received);
//    char data[] = "Got an m";
//
//
//        if(convertedChar == 'm'){
//            int i = 0;
//            while(data[i] != 0){
//                cyBot_sendByte(data[i]);
//                i++;
//            }
//        }
//    }
    int i = 0;
    char data[] = "Going Forward";


    while(1){
        int received = cyBot_getByte();
        char convertedChar = (char)(received);

        switch(convertedChar){
                  case 'w':
                      while(data[i] != 0){
                          cyBot_sendByte(data[i]);
                          i++;
                      }
                      move_forward(sensor, 500);
                      break;
                  case 's':
                      move_backward(sensor, 500);
                      break;
                  case 'a':
                      turn_counterclockwise(sensor, 90);
                      move_forward(sensor, 500);
                      break;
                  case'd':
                      turn_clockwise(sensor, 90);
                      move_forward(sensor, 500);
                      break;
        }


    }

    return 0;
}
