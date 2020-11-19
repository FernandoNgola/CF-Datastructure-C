#include "recursion.h"
#include <stdio.h>

//int x = 0;
void tail_recursion(int n){
	/*Nesta função primeiro imprime depois chama a função
	de novo. Neste caso o resultado seŕa imprime f(n) e chama f(n-1)*/
	if (n>0)
	{
		printf("%d\n", n);
		tail_recursion(n-1);
	}
}

void head_recursion(int n){
	/*Nest a função primeior chama depois imprime. Neste caso, as imprissões só serão feitas
	após as chamadas serem concluídas. Chama  f(n), chamaf(n-1) chama f(n-n) e imprime f(n-n),
	f(n-2) etc*/
	if (n>0)
	{
		head_recursion(n-1);
		printf("%d\n", n);
	}
}

int fun(int n){
	if(n>0){
		//1. chamada->Ascendente
		return fun(n-1) +n;
		//2. Retorno->Descendente
	}
	return 0;
}

int fun1(int n){
	//A cada chamada
	static int x = 0;
	if (n > 0)
	{
		x++;
		return fun1(n - 1) + x; 
	}
	return 0;
}

void tree_recursion(int n){

	if (n > 0)
	{
		printf("%d\n", n);
		tree_recursion(n - 1);
		// printf("\n");
		// printf("%d\n", n);
		tree_recursion(n - 1);
	}
}


void indirect_recursionA(int n){
	if(n > 0){
		printf("%d\n", n);
		indirect_recursionB(n-1);
	}
}
void indirect_recursionB(int n){
	if (n > 1)
	{
		printf("%i\n", n);
		indirect_recursionA(n/2);
	}
}

int nested_recursion(int n){
	if (n > 100)
	{
		return n - 10;
	}
	return nested_recursion(nested_recursion(n + 11));
}

int r_sum_first_n_numbers(int n){
		if (n == 0)
	{
		return 0;
	}
	return r_sum_first_n_numbers(n - 1) + n;
}

int i_sum_first_n_numbers(int n){
	int sum = 0;
	for (int i = 0; i <= n; ++i)
	{
		sum += i;
	}
 return sum;
}
int f_sum_first_n_numbers(int n){
	return (n + 1)*n/2;
}

int factorial_r(int n){
	if(n == 0)
		return 1;
	return factorial_r(n-1)*n;

}

int factorial_i(int n){
	int fact = 1;
	for (int i = 1; i <= n; ++i)
	{
		fact *= i;
	}
	return fact;
}

int power_r(int m, int n){
	if(n == 0)
		return 1;
	return power_r(m, (n-1)) * m;

}

int power_i(int m, int n){
	int power = 1;
	for (int i = 1; i <= n; ++i)
	{
		power = power * m;	
	}
	return power;
}

int power_r_f(int m, int n){


	if (n == 0)
	{
		return 1;
	}

	if (n % 2 == 0)
	{
		return power_r_f(m*m, n/2);
	}else{
		return m * power_r_f(m * m, (n - 1)/2);
	}
}

double euler(int x, int n){
	static double p = 1, f = 1;
	double r;
	if(n == 0)
		return 1;

	r = euler(x, n - 1);
	p = p * x;
	f = f * n;
	return r + (p / f); 

}

double euler_faster(int x, int n){
	static double s;
	if (n == 0)
	{
		return s;
	}
	s = 1 + (x*s)/n;
	return euler_faster(x, (n - 1));
}

double euler_iter(int x, int n){
	double s = 1;
	for (; n > 0; --n)
	{
		s = 1 + (x*s)/n;
	}
	return s;
}


void TOH(int n, char A, char B, char C){
	if (n > 0)
	{
		TOH(n-1, A, C, B);
		printf("(%c, %c)\n", A, C);
		TOH(n-1, B,A, C);
	}
}