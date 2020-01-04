#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Program name: calculatorE.c
 *   Author: Thulasi Jothiravi
 *   Last Update: September 27, 2019
 *   Function: Calculate the days in between start and end dates.
 *   Compilation: gcc -ansi -o calculatorE calculatorE.c
 *   Execution: ./calculatorE
 */

int main ( int argc, char *argv[] ) {

   int i = 0;

   int totalDays = 0;

   int leapYear = 0;
   int naturalYear = 0;

   int startDate = 0;
   int endDate = 0;

   int dd1 = 0;
   int dd2 = 0;
   int mm1 = 0;
   int mm2 = 0;
   int yyyy1 = 0;
   int yyyy2 = 0;

   int includeBool = 0;

   char startDateStr[3];
   char startMonthStr[3];
   char startYearStr[5];

   char endDateStr[3];
   char endMonthStr[3];
   char endYearStr[5];

int monthLength[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int day_of_year[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int day_of_leapYear[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};

   if ( argc < 3 || argc > 4 ) {

      printf ( "Usage: ./calculatorE dd1-mm1-yyyy1 dd2-mm2-yyyy2\n" );
      exit (1);

   } else {
     startDateStr[0] = argv[1][0];
     startDateStr[1] = argv[1][1];
     startDateStr[2] = '\0';

     startMonthStr[0] = argv[1][3];
     startMonthStr[1] = argv[1][4];
     startMonthStr[2] = '\0';

     startYearStr[0] = argv[1][6];
     startYearStr[1] = argv[1][7];
     startYearStr[2] = argv[1][8];
     startYearStr[3] = argv[1][9];
     startYearStr[4] = '\0';

     endDateStr[0] = argv[2][0];
     endDateStr[1] = argv[2][1];
     endDateStr[2] = '\0';

     endMonthStr[0] = argv[2][3];
     endMonthStr[1] = argv[2][4];
     endMonthStr[2] = '\0';

     endYearStr[0] = argv[2][6];
     endYearStr[1] = argv[2][7];
     endYearStr[2] = argv[2][8];
     endYearStr[3] = argv[2][9];
     endYearStr[4] = '\0';

     dd1 = atoi (startDateStr);
     mm1 = atoi (startMonthStr);
     yyyy1 = atoi (startYearStr);

     dd2 = atoi (endDateStr);
     mm2 = atoi (endMonthStr);
     yyyy2 = atoi (endYearStr);

   }
     if ((argc == 4) && (strcmp("include",argv[3]) == 0))  {
         includeBool = 1;

         startDateStr[0] = argv[1][0];
         startDateStr[1] = argv[1][1];
         startDateStr[2] = '\0';

         startMonthStr[0] = argv[1][3];
         startMonthStr[1] = argv[1][4];
         startMonthStr[2] = '\0';

         startYearStr[0] = argv[1][6];
         startYearStr[1] = argv[1][7];
         startYearStr[2] = argv[1][8];
         startYearStr[3] = argv[1][9];
         startYearStr[4] = '\0';

         endDateStr[0] = argv[2][0];
         endDateStr[1] = argv[2][1];
         endDateStr[2] = '\0';

         endMonthStr[0] = argv[2][3];
         endMonthStr[1] = argv[2][4];
         endMonthStr[2] = '\0';

         endYearStr[0] = argv[2][6];
         endYearStr[1] = argv[2][7];
         endYearStr[2] = argv[2][8];
         endYearStr[3] = argv[2][9];
         endYearStr[4] = '\0';

         dd1 = atoi (startDateStr);
         mm1 = atoi (startMonthStr);
         yyyy1 = atoi (startYearStr);

         dd2 = atoi (endDateStr);
         mm2 = atoi (endMonthStr);
         yyyy2 = atoi (endYearStr);
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
if (yyyy1%4 == 0 && (yyyy1%400 == 0 || yyyy1%100 != 0)){
  startDate = day_of_leapYear[mm1-1] + dd1;
} else {
  startDate = day_of_year[mm1-1] + dd1;
}

if (yyyy2%4 == 0 && (yyyy2%400 == 0 || yyyy2%100 != 0)){
  if (includeBool == 1) {
  endDate = day_of_leapYear[mm2-1] + dd2;
  } else {
  endDate = day_of_leapYear[mm2-1] + dd2;
  }
} else {
  if (includeBool == 1) {
  endDate = day_of_leapYear[mm2-1] + dd2;
} else {
  endDate = day_of_leapYear[mm2-1] + dd2;
  }
 }


if (yyyy1 == yyyy2) {
  if (includeBool == 1) {
    printf("%02d\n", endDate - startDate + 1);
  }
  else {
    printf("%02d\n", endDate - startDate);
  }
  return(0);
}

if (yyyy1%4 == 0 && (yyyy1%400 == 0 || yyyy1%100 != 0)) {
  dd1 = 366 - startDate;
} else {
  dd1 = 365 - startDate;
}

if (yyyy2%4 == 0 && (yyyy2%400 == 0 || yyyy2%100 != 0)) {
  dd2 = endDate;
} else {
  dd2 = endDate;
}

for (i=yyyy1+1; i<yyyy2; i++) {
  if ((i%4 == 0 && (i%400 == 0 || i%100 != 0))) { /*check leap year for i*/
    leapYear++;
  } else {
    naturalYear++;
  }
}

if(includeBool == 1) {
  totalDays = (365*naturalYear)+(366*leapYear)+1+dd1+dd2;
  printf("%02d\n", totalDays);
} else {
totalDays = (365*naturalYear)+(366*leapYear)+dd1+dd2;
printf("%02d\n", totalDays);
}

   return ( 0 );
}
