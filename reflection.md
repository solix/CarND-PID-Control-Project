### PID COMPONENT

In PID control we are trying to set steering angle in proportion of  cross track error (cte) which is the lateral difference between the vehicle and reference trajectory.

Here I will address effect of each P, I and D controller of the algorithm and the expectations from them.

##### Proportional Controller

for the proportional control rather than turn the wheel a fixed amount, proportional control steers harder the further we are from the reference trajectory. but alone with proportional control the car can be crooked when it reaches the center line; this led to car overshooting that constantly reaches desired trajectory and not actually follow to it (car oscillates), to correct overshooting we need to consider additional error measurement D Controller

##### D for derivative of cte
 This is simply a good candidate, temporal derivative will be added to the error measurement.this means that when the car reaches a reference trajectory it will not overshoot anymore because it knows the rate of change in the cross track error and can recover well reduce cte to almost 0 and avoids overshooting. by alone PD the result is satisfying.

##### Integral part of the controller

This Controller is useful when there are some environmental forces such as hard wind or car drives over a rock. We add Integral controller to our error measurement to check in such special cases where 0 steering angel command no longer keep the vehicle driving straight, this case is a lane offset. Integral term sums up the cross track error to indicate if the vehicle is spending more time on one side a trajectory or the other. 


 


*Visual aids i.e. record of a small video of the car in the simulator 

 
![alt text](http://g.recordit.co/89jbEDbiAT.gif "final")
### Hyperparameters (P, I, D coefficients)



 SO PID controller requires 3 coefficient tuned all at once which I did manually. Although twiddle was a better choice. (will try in future). I have added a high coefficient value to D controller while keeping Proportional controller lower. This helped to reduce the oscillation. For the current trajectory I did not wanted to add Integral gain to the model since the model already showed a good performance.



 |  kp0 | kd0 | ki0 |
| ------------- |:-------------:|:-------------:|
|  0.27| 7.0 | 0.0|