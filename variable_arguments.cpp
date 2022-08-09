// To accept variable number of arguments
/*There are four parts needed: va_list, which stores the list of arguments,
va_start, which initializes the list, 
va_arg, which returns the next argument in the list, and
va_end, which cleans up the variable argument list. */

//the cstdarg header file

#include<iostream>
#include<cstdarg>
using namespace std;

class solution {
public:
	double average ( int num, ... )      // ( int x, ... ); tell the compiler tos accept x arguments.

{
  va_list arguments;                     // A place to store the list of arguments
  double sum = 0;
 
  va_start ( arguments, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( arguments, double ); // Adds the next value in argument list to sum.
  va_end ( arguments );                  // Cleans up the list
 
  return sum / num;                      // Returns the average
}
};

int main(){
	solution ob;
	 // this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average)
  cout<< ob.average ( 3, 12.2, 22.3, 4.5 ) <<endl;
    // here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
  cout<< ob.average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) <<endl;
}