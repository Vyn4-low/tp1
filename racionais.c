#include <stdio.h>
#include <stdlib.h>
#include "racionais.h"
/* acrescente demais includes que voce queira ou precise */

int aleat (int min, int max)
{

	//Retorna um numero aleatorio entre min e max
	return (min + (rand() % (max+1-min)));
}

int mdc (int a, int b)
{
	int res = 0;
	
	//Transforma negativos em positivos
	if(a < 0)
		a = a * -1;
	if(b < 0)
		b = b * -1;
		
	//Verifica se a eh maior que b
	if(b > a)
	{
		int temp = b;
		b = a;
		a = temp;
	}
	//Retorna 0 se a ou b forem 0
	if((a == 0) || (b == 0))
		return 0;
	//Caso base
	if(a % b == 0)
		return b;
	while (a % b != 0)
	{	
		res = b;
		b = a % b;
		a = res;
		if(a % b == 0)
			return b;
	}
	
	return 0;
}


int mmc (int a, int b)
{
	if((a == 0) || (b == 0))
		return 0;
	return (a*b) / mdc(a,b);
}

struct racional simplifica_r (struct racional r)
{
	int mdcs;
	struct racional simp;
	simp.valido = 0;
	if(valido_r(r) == 1)
	{
		mdcs = mdc(r.num,r.den);
		simp.num = r.num / mdcs;
		simp.den = r.den / mdcs;
		simp.valido=valido_r(simp);
	}
	
	return simp;
}

struct racional cria_r (int numerador, int denominador)
{

	//Cria struct que receberá num e den
	struct racional rac;
	
	rac.num = numerador;
	rac.den = denominador;
	rac.valido = valido_r(rac);
	
	return rac;
}

struct racional sorteia_r (int n)
{
	struct racional sort;
	
	int denum = aleat(0,n);
	int numer = aleat(0,n);
	sort = cria_r(denum,numer);
	return sort;
}

void imprime_r (struct racional r)
{
	if(valido_r(r) == 0)
	{
		printf("INVALIDO ");
		return ;
	}

		
	if(r.num == 0)
	{
		printf("0 ");
		return ;
	}
	r = simplifica_r(r);
		
	if(r.den == 1)
	{
		printf("%d ", r.num);
		return ;
	}

	if(r.den == r.num)
	{
		printf("1 ");
		return ;	
	}
		
	if(r.den < 0)
	{
		r.den = r.den * -1;
		r = simplifica_r(r);
		printf("-%d/%d ",r.num,r.den);
		return ;	

	}
	
	if((r.num < 0) && (r.den < 0))
	{
		r.num = r.num * -1;
		r.den = r.den * -1;
		r = simplifica_r(r);
		printf("%d/%d ", r.num,r.den);
		return ;
	}

	if(valido_r(r) == 1)
	{
		r = simplifica_r(r);
		printf("%d/%d ", r.num,r.den);
	}
	return ;
	
}

int valido_r (struct racional r)
{
	if(r.den != 0)
		return 1;
	return 0;
}

struct racional soma_r (struct racional r1, struct racional r2)
{
	struct racional soma;
	
	if((valido_r(r1) == 1) && (valido_r(r2) == 1))
	{
		soma.den = r1.den*r2.den;
		soma.num = (soma.den / r1.den * r1.num) + (soma.den / r2.den * r2.num);
		soma.valido = valido_r(soma);
	}
	
	return soma;
}

struct racional subtrai_r (struct racional r1, struct racional r2)
{
	struct racional subt;
	if((valido_r(r1) == 1) && (valido_r(r2) == 1))
	{
		subt.den = r1.den*r2.den;
		subt.num = (subt.den / r1.den * r1.num) - (subt.den / r2.den * r2.num);
		subt.valido = valido_r(subt);
	}
	
	return subt;
}

struct racional multiplica_r (struct racional r1, struct racional r2)
{
	struct racional mult;
	if((valido_r(r1) == 1) && (valido_r(r2) == 1))
	{
		mult.den = r1.den * r2.den;
		mult.num = r1.num * r2.num;
		mult.valido = valido_r(mult);
	}
	
	return mult;
}

struct racional divide_r (struct racional r1, struct racional r2)
{
	struct racional divi;
	if((valido_r(r1) == 1) && (valido_r(r2) == 1))
	{
		divi.num= r1.num * r2.den;
		divi.den= r1.den * r2.num;
	}

	return divi;
}

/* 
 * Implemente aqui as funcoes definidas no racionais.h 
 * caso queira, você pode definir neste arquivo funcoes
 * adicionais que serao internas e so podem ser usadas
 * aqui.
*/
