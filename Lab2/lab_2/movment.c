/*
 * movment.c
 *
 *  Created on: Sep 12, 2024
 *      Author: sg15
 */

//include the needed header files
#include "movment.h"
#include "open_interface.h"

//function that moves the iRobot forward a specified centimeters
void move_forward(oi_t *sensor, int centimeter) {

    //set the iInitial distance to 0
    double distance = 0;

    //move forward; full speed
    oi_setWheels(500, 500);

    //while the distance is less than the specified centimeters update
     while (distance < (920/100) * centimeter ) {
         oi_update(sensor);
         distance += sensor->distance;
     }

     //stop
     oi_setWheels(0, 0);

}

void move_backward(oi_t *sensor, int centimeter) {

    //set the iInitial distance to 0
    double distance = 0;

    //move forward; full speed
    oi_setWheels(-500, -500);

    //while the distance is less than the specified centimeters update
     while (distance > -(920/100) * centimeter) {
         oi_update(sensor);
         distance += sensor->distance;
     }

     //stop
     oi_setWheels(0, 0);

}

//this function will turn the iRobot clockwise for a specified degree
void turn_clockwise(oi_t *sensor, int degrees){

    //set the angle to 0 degrees
    double angle = 0;

    //spin the iRobot at the center, spinning clockwise
    oi_setWheels(-100, 100);

    //while the angle is less than the degrees specified update the sensor
    while(angle > -degrees){
        oi_update(sensor);
        angle += sensor->angle;
   }

   //once the condition is met stop the iRobot
   oi_setWheels(0, 0); // stop
}

void turn_counterclockwise(oi_t *sensor, int degrees){

    //set the angle to 0 degrees
    double angle = 0;

    //spin the iRobot at the center, spinning clockwise
    oi_setWheels(100, -100);

    //while the angle is less than the degrees specified update the sensor
    while(angle < degrees){
        oi_update(sensor);
        angle += sensor->angle;
   }

   //once the condition is met stop the iRobot
   oi_setWheels(0, 0); // stop
}

//move forward 2 meters
void move_forward2(oi_t *sensor, int centimeter) {

    //set the iInitial distance to 0
    double distance = 0;

    //while the distance is less than the specified centimeters update
     while (distance < (920/100) * centimeter) {
         if (sensor->bumpLeft || sensor->bumpRight){//
             distance += bump(sensor);
         }else{
             distance += sensor->distance;
         }

         oi_update(sensor);

         //move forward; full speed
         oi_setWheels(300, 300);
     }

     //stop
     oi_setWheels(0, 0);
}

//this is the bump function
int bump(oi_t *sensor){

    //move back full speed
    move_backward(sensor, 15);

    //turn right if left bumper hit, turn left if right bumper hit
    if(sensor ->bumpLeft){
        turn_clockwise(sensor, 90);
        move_forward(sensor, 25);
        turn_counterclockwise(sensor, 90);
    }else {
        turn_counterclockwise(sensor, 90);
        move_forward(sensor, 25);
        turn_clockwise(sensor, 90);
    }

    return (-40 * (920 / 100));
}







































//if no obstical go
//

