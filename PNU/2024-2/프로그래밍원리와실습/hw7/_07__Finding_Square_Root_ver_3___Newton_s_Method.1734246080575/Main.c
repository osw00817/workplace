#include <stdio.h>
#include <math.h>

double findroot_exhaustive(double x, double epsilon);	
double findroot_bisection(double x, double epsilon);

/**
* @brief : Find an approximation to the square root of a non-negative number using the Newton's method. 
* @return: An approximation to the square root. The square of it should be in the range [x-epsilon, x+epsilon].
          -1 if it can't find an answer.
* @param : x - target number, epsilon - the allowed difference 
*/
double findroot_newton(double x, double epsilon) {
	if(x < 0) return -1;
	if(x == 0) return 0;
	double ans = x/2.0;
	int numGuesses = 0;
	
	double diff = fabs(ans*ans - x);
	
	while (diff >= epsilon) {
	  ans = ans - (ans*ans-x)/(2*ans);
		diff = fabs(ans*ans -x);
		numGuesses++;
	}
	
	printf("# of Guesses = %d\n", numGuesses);
		
	return ans;	
}

int main(void) {
	double x;
	double epsilon = 0.001;

	scanf("%lf",&x);
	
	if (x > 0) {
		printf("[EXHAUSTIVE] sqrt(%lf) ~= %.20lf\n",x,findroot_exhaustive(x,epsilon));
		printf("[BISECTION ] sqrt(%lf) ~= %.20lf\n",x,findroot_bisection(x,epsilon));
		printf("[  NEWTON  ] sqrt(%lf) ~= %.20lf\n",x,findroot_newton(x,epsilon));
		printf("[  MATH.H  ] sqrt(%lf) ~= %.20lf\n",x,sqrt(x));
	}	

	return 0;
} 


/**
* @brief : Find an approximation to the square root of a non-negative number using the exaustive search method. 
* @return: An approximation to the square root. The square of it should be in the range [x-epsilon, x+epsilon].
          -1 if it can't find an answer.
* @param : x - target number, epsilon - the allowed difference 
*/
double findroot_exhaustive(double x, double epsilon) {
	double step = epsilon * epsilon;
	double ans = 0.0;
	int numGuesses = 0;
	
	double diff = fabs(ans*ans - x);
	
	while (diff >= epsilon && ans*ans <= x) {
		ans = ans + step;
		diff = fabs(ans*ans -x);
		numGuesses = numGuesses + 1;
	}
	if (diff >= epsilon) ans = -0.1;	
	
	printf("# of Guesses = %d\n", numGuesses);
		
	return ans;	
}

/**
* @brief : Find an approximation to the square root of a non-negative number using the bisection search method. 
* @return: An approximation to the square root. The square of it should be in the range [x-epsilon, x+epsilon].
          -1 if it can't find an answer.
* @param : x - target number, epsilon - the allowed difference 
*/
double findroot_bisection(double x, double epsilon) {
	double low = 0.0;
	double high = fmax(1.0,x);
	double ans = (high+low)/2;
	int numGuesses = 0;
	
	double diff = fabs(ans*ans - x);
	
	while (diff >= epsilon) {
	//Enter Your Code Here
		if(ans*ans < x) low = ans;
		if(ans*ans > x) high = ans;
		ans = (high+low)/2;

		diff = fabs(ans*ans -x);
		numGuesses = numGuesses + 1;
	}
	
	printf("# of Guesses = %d\n", numGuesses);
		
	return ans;
}