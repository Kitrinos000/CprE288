/*
 * movment.h
 *
 *  Created on: Sep 12, 2024
 *      Author: sg15
 */

#ifndef MOVMENT_H_
#define MOVMENT_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Timer.h"
#include <inc/tm4c123gh6pm.h>
#include "lcd.h"
#include "open_interface.h"

void move_forward(oi_t *sensor, int centimeters);

void turn_clockwise(oi_t *sensor, int degrees);

int bump(oi_t *sensor);

void turn_counterclockwise(oi_t *sensor, int degrees);

void move_forward2(oi_t *sensor, int centimeter);
#endif /* MOVMENT_H_ */
