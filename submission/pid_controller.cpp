/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
    Kp = Kpi;
    Ki = Kii;
    Kd = Kdi;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    d_time = 1.0;
    lim_max = output_lim_maxi;
    lim_min = output_lim_mini;
}



void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
    d_error = (cte - p_error)/d_time;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
  
  double control = (Kp * p_error) - (Ki * i_error) - (Kd * d_error);
  control= max(min(control,lim_max), lim_min);
  return control;

}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  d_time = new_delta_time;
  return d_time;
}