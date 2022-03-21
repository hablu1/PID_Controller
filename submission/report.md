## Setup Carla Simulator
![setup](./screenshots/initial_setup.JPG)

## How to Run the Code
copy the pid_controller.ccp and pid_controller.h file to your pid_controller folder in the provided starter code.
The existing files need to be replaced by my files.
Compile the code using make.
Run carle server in background and run ./run_main_pid.sh to see the PID controller in action.

## Resluting Plots 
![steering_error](./screenshots/steering_error_plot.JPG)
![throttle_error](./screenshots/throttle_error_plot.JPG)

## Questions
### Q1
// Add the plots to your report and explain them (describe what you see)
The plots are added above.
The throttle_error_plot shows the output of the brake control signal and the throttle control signal. The error of the desired velocity and the
actual velocity is also display as error throttle.
The steering error plot shows the control output of the steering pid controller and the error between the x y waypoint coordiantes and the actual coordinates. 
In both plots it can be seen that the control signal is within defined output limits of the steering and throttle pid contoller.
Also, the bigger the error, the bigger the control signal output value.
### Q2
// What is the effect of the PID according to the plots, how each part of the PID affects the control command?
The PID controller keeps oszillating. 
The proporional gain controls the biggest part of the control signal's magnitude, that is, the bigger the error between desired value and actal value, the bigger the proportional part (multiplied by the proportional gain). With the proportional gain, the ramp can be adjusted.
The integral gain accounts for the residual error between desired and actual value. That is, if there was a big error in the past, the integral part of the PID controller will be bigger.
The derivative part of the PID controller accounts for the change in the error. It therefore predicts the system behaviour and makes the contoller more stable. 
### Q3
// How would you design a way to automatically tune the PID parameters?
Using the Twiggle algorithm from Sebastian's class.
### Q4
// PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
Pros:
-no need to find a suitable model
-can be applied/transfered to different vehicles with different models
-robust tuning mechanisms available (Twiggle algo or Ziegler–Nichols method)
-only the errors needs to be measured
Cons:
-not suitable for complex systems
-does not account for non-linearity
### Q5
// (Optional) What would you do to improve the PID controller?
One could smooth the control signal using a filter to make the system even more stable.
