/*
(a) Write a "wrapper" function named try_math_fcn that calls a math function
(assumed to have a double argument and return a double value) and then checks
whether the call succeeded.
Here's how we might use try_math_fcn:

y = try_math_fcn(sqrt, x, "Error in call of sqrt");

If the call sqrt(x) is successful, try_math_fcn returns the value computed by
sqrt. If the call fails, try_math_fcn calls perror to print the message "Error
in call of sqrt", then calls exit to terminate the program.

(b) Write a macro that has the same effect as try_math_fcn but builds the error
message from the functions name:

y = TRY_MATH_FCN(sqrt, x);

If the call of sqrt fails, the message will be
"Error in call of sqrt".
Hint: Have the TRY_MATH_FCN call try_math_fcn
*/

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRY_MATH_FCN(f, x) try_math_fcn(f, x, "Error in call of " #f)

// NOTE: can try compiling with flag -fmath-errno
double try_math_fc(double fn(double), double x, char *err_msg) {
  errno = 0;

  double result = fn(x);

  if (errno != 0) {
    perror(err_msg);
    exit(EXIT_FAILURE);
  } else if (math_errhandling != MATH_ERRNO) {
    printf("math_errhandling is not set to MATH_ERRNO\n");
  }

  return result;
}

int main(void) {
  char *err_msg = "exp error";

  try_math_fc(sqrt, 4, err_msg);
  try_math_fc(sqrt, 10000, err_msg);

  return 0;
}
