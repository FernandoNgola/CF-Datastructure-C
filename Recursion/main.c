#include <stdlib.h>
#include <stdio.h>
#include "recursion.h"

int main(int argc, char const *argv[])
{
	// static int i = 1;
	// i++;
	int x = 5;
	//fun(x);
	//int value = fun3(x);
	fun1(x);
	//printf("=========================================\n");
	//i++;
	//printf("%i\n", value);

/*	printf("%i\n",  fun1(5));
	printf("%i\n",  fun1(5));	
	printf("%i\n",  fun1(5));*/
	//tree_recursion(3);
	//indirect_recursionA(20);

	/*int sum = r_sum_first_n_numbers(1000);
	printf("%i\n", sum);
	printf("%i\n", f_sum_first_n_numbers(1000000000));
	printf("%d\n", i_sum_first_n_numbers(10000));
*/
	// int number = 5;
	// int fact;
	// fact = factorial_r(number);
	// printf("%d\n", fact);

	// fact = factorial_i(number);
	// printf("%d\n", fact);

	/*int power = power_r(2,10);
	printf("%d\n", power);
	power = power_i(2, 10);
	printf("%d\n", power);
	power = power_r_f(2, 10);
	printf("%d\n", power);

	printf("%lf\n", euler(2,10));
	printf("%lf\n", euler_faster(2, 15));
	printf("%lf\n", euler_iter(2, 10));*/
	TOH(8, 'A', 'B', 'C');

	return 0;
}