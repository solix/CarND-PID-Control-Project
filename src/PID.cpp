#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}



void PID::Init(double Kp, double Ki, double Kd) {

	//coefficient
	this -> Kp = Kp;
	this -> Ki =  Ki;
	this -> Kd = Kd;
	this -> p_error=0;
    this -> i_error=0;
    this -> d_error=0;
    

}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error+=cte;

	// cout<<"PID Error"<<p_error<<i_error<<d_error<<endl;
}

double PID::TotalError() {

	return Kp*p_error+Ki*i_error+Kd*d_error;
}

// void Twiddle(double cte,double Kp,double Ki,double Kd){
// 	vector dp={1,1,1};
// 	vector p={p_error,i_error,d_error};
// 	double best_error = cte;
// 	double threshold = 0.001;

// 	while(best_error>threshold){
// 		for(int i = 0; i < p.size(); i++){
// 			p[i]+=dp[i];
// 			UpdateError(cte);
// 			if(best_error<cte){
// 				best_error = cte;
// 				dp[i]*=1.1;

// 			}else{
// 				p[i] -=2*dp[i];
// 				UpdateError(cte);

// 				if()
// 			}
// 		}

// 	}


// }

