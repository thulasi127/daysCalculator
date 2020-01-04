#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: calculatorA.c
 *   Author: Thulasi Jothiravi
 *   Last Update: September 27, 2019
 *   Function: Calculate the days in between start and end dates.
 *   Compilation: gcc -ansi -o calculatorA calculatorA.c
 *   Execution: ./calculatorA
 */

int main ( int argc, char *argv[] ) {

   int startDate = 0;
   int endDate = 0;

   int dd1 = 0;
   int dd2 = 0;
   int mm1 = 0;
   int mm2 = 0;
   int yyyy1 = 0;
   int yyyy2 = 0;

int monthLength[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int day_of_year[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int day_of_leapYear[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};

   if ( argc < 7 ) {
      printf ( "Usage: ./calculatorA dd1 mm1 yyyy1 dd2 mm2 yyyy2\n" );
      exit (1);
   } else {
      dd1 = atoi (argv[1]);
      mm1 = atoi (argv [2]);
      yyyy1 = atoi (argv [3]);

      dd2 = atoi (argv [4]);
      mm2 = atoi (argv[5]);
      yyyy2 = atoi (argv[6]);
   }

if (yyyy1%4 == 0 && (yyyy1%400 == 0 || yyyy1%100 != 0) ) {
  monthLength[1] = 29;
}

if (((yyyy1%400 == 0 || yyyy1%100 > 0) && (yyyy1%4 == 0)) && ((mm1 == 2) && (dd1 < 1 || dd1>29)) || ((mm2 == 2) && (dd2<1 || dd2>29))) {
  printf("Error\n");
  return (1);
}
else if ((( dd1<0 || dd1>28) ||(dd2<0 || dd2>28)) && ((mm1 == 2 || mm2 == 2) && ((yyyy1%400 == 0 || yyyy1%100 > 0) && (yyyy1%4 == 0)))) {
  printf("Error\n");
  return(1);
}

if ((dd1<0 || dd1>31) && (mm1 == 1 || mm1 == 3 || mm1 == 5 || mm1 == 7 || mm1 == 8 || mm1 == 10 || mm1 == 12)) {
  printf("Error\n");
  return(1);
} else if ((dd1<0 || dd1>30) && (mm1 == 4 || mm1 == 6 || mm1 == 9 || mm1 == 11)) {
  printf("Error\n");
  return(1);
}
if (mm1<1 || mm1>12) {
  printf("Error\n");
  return(1);
}

if ((dd2<0 || dd2>31) && (mm2 == 1 || mm2 == 3 || mm2 == 5 || mm2 == 7 || mm2 == 8 || mm2 == 10 || mm2 == 12)) {
  printf("Error\n");
  return(1);
} else if ((dd2<0 || dd2>30) && (mm2 == 4 || mm2 == 6 || mm2 == 9 || mm2 == 11)) {
  printf("Error\n");
  return(1);
}
if (mm2<1 || mm2>12) {
  printf("Error\n");
  return(1);
}

if (startDate < endDate) {
  startDate = day_of_leapYear[mm1-1] + dd1;
  endDate = day_of_leapYear[mm2-1] + dd2;

    printf("%02d\n", endDate - startDate);
}
else {
  startDate = day_of_year[mm1-1] + dd1;
  endDate = day_of_year[mm2-1] + dd2;

    printf("%02d\n", endDate - startDate);
  }

if (startDate > endDate) {
  printf("Error - the end date is before the start date.\n");
}

   return ( 0 );
}
