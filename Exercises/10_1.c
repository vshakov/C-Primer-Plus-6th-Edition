/* 10_1.c */
// C Primer Plus
// Chapter 10 Exercise 1:

// Modify the rain program in Listing 10.7 so that it does the calculations
// using pointers instead of subscripts. (You still have to declare and
// initialize the array.)

#include <stdio.h>
#define MONTHS 12 // number of months in a year 
#define YEARS 5 // number of years of data 

int main(void)
{
	// initializing rainfall data for 2010 - 2014
	const float rain[YEARS][MONTHS] = 
    {
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6}, 
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3}, 
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4}, 
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2}, 
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
    int year, month;
    float subtot, total;
    printf("  ГОД     КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
    const float (* ptr_year)[MONTHS];
    const float * ptr_month;
    for (ptr_year = rain, total = 0; ptr_year < rain + YEARS; ptr_year++)
    {
        // для каждого года суммировать количество осадков за каждый месяц
        for (ptr_month = * ptr_year, subtot = 0; ptr_month < (* ptr_year) + MONTHS; ptr_month++)
        {
            subtot += *ptr_month;
        }
        printf("%5.0ld %15.1f\n", 2010 + (ptr_year - rain), subtot);
        total += subtot;        // общая сумма для всех лет
    }
    printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n", total/YEARS);
    printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf("Янв Фев Мар Апр Май Июн Июл Авг Сен Окт Ноя Дек\n");
    for (month = 0; month < MONTHS; month++)
	{ 
		// for each month, sum rainfall over years
		for (year = 0, subtot = 0,ptr_year = rain; year < YEARS; year++)
			subtot += *(*(ptr_year + year) + month);
		printf("%4.1f", subtot/YEARS);
	}
    printf("\n");

    return 0;
}