/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
  /* implemente aqui */

  /* Retorna um numero aleatorio entre min e max */
	return (min + (rand() % (max+1-min)));
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
  /* implemente aqui */

  	long res = 0;
	
	/* Transforma negativos em positivos */
	if(a < 0)
		a = a * -1;
	if(b < 0)
		b = b * -1;
		
	/* Verifica se a eh maior que b */
	if(b > a)
	{
		long temp = b;
		b = a;
		a = temp;
	}
	/* Retorna 0 se a ou b forem 0 */
	if((a == 0) || (b == 0))
		return 0;
	/* Caso base */
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

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  /* implemente aqui */

/* Realiza minimo multiplo comum pelo metodo de Euclides */
	if((a == 0) || (b == 0))
		return 0;
	return (a*b) / mdc(a,b);
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  /* implemente aqui */

  /* Verifica se o racional eh valido, se for
	 * recebe o num/den dividido pelo mdc
	 */

	long mdcs;
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

/* implemente as demais funções aqui */

struct racional cria_r (long numerador, long denominador)
{
  /* Cria struct que receberá num e den */
	struct racional rac;
	
	rac.num = numerador;
	rac.den = denominador;
	rac.valido = valido_r(rac);
	return rac;
}
int valido_r (struct racional r)
{
  /* Verifica se o racional eh valido, ele so eh se
	 * o denominador for diferente de 0, retorna 1 se for valido e 0 caso contrario
	 */

	if(r.den != 0)
		return 1;
	return 0;
}
struct racional sorteia_r (long min, long max)
{
  /* Num/den recebem um numero aleatorio entre "0" e "n"
	 * e cria um novo racional com os numeros
	 */

	struct racional sort;
	
	long denum = aleat(0,n);
	long numer = aleat(0,n);
	sort = cria_r(denum,numer);
	return sort;
}
void imprime_r (struct racional r)
{
  /* Verifica se eh invalido, se for, imprime "INVALIDO" */
	if(valido_r(r) == 0)
	{
		printf("INVALIDO ");
		return ;
	}
	/* Se o numerador for "0" imprime ele */
	if(r.num == 0)
	{
		printf("0 ");
		return ;
	}
	r = simplifica_r(r);
	
	/* Se o denominador for "1" imprime o numerador */
	if(r.den == 1)
	{
		printf("%ld ", r.num);
		return ;
	}
	/* Se o denominador eh igual ao numerador imprime "1" */
	if(r.den == r.num)
	{
		printf("1 ");
		return ;	
	}
	/* Se o denominador eh negativo ele recebe ele mesmo positivo
	 * simplifica e imprime
	 */

	if(r.den < 0)
	{
		r.den = r.den * -1;
		r = simplifica_r(r);
		printf("-%ld/%ld ",r.num,r.den);
		return ;	
	}
	/* Se o numerador e o denominador sao negativos
	 * num/den recebem eles mesmos positivos, simplificam e imprimem
	 */

	if((r.num < 0) && (r.den < 0))
	{
		r.num = r.num * -1;
		r.den = r.den * -1;
		r = simplifica_r(r);
		printf("%ld/%ld ", r.num,r.den);
		return ;
	}
	/* Se o racional eh valido, simplifica e imprime */
	if(valido_r(r) == 1)
	{
		r = simplifica_r(r);
		printf("%ld/%ld ", r.num,r.den);
	}
	return ;
}
struct racional soma_r (struct racional r1, struct racional r2)
{
  /* O denominador de r3 recebe o denominador de r1 vezes o denominador de r2,
	 * o numerador de r3 recebe o seu denominador dividido pelo produto
	 * do denominador e numerador de r1 mais a mesma operacao mas com r2,
	 * verifica se r3 eh valido e retorna
	 */

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
  /* O denominador de r3 recebe denominador de r1 vezes o de r2,
	 * o numerador de r3 recebe o seu denominador dividido pelo produto
	 * do denominador e numerador de r1 menos a mesma operacao mas com r2,
	 * verifica se r3 eh valido e retorna r3
	 */

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
  /* Denominador de r3 recebe denominador de r1 vezes denominador de r2,
	 * o numerador faz a mesma coisa mas com numeradores, verifica se r3 eh valido
	 * e retorna r3
	 */

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
  /* Numerador de r3 recebe o produto do numerador de r1 com denominador r2,
	 * o denominador recebe o produto do denominador de r1 com numerador de r2,
	 * verifica se r3 eh valido e retorna r3
	 */
  
	struct racional divi;
	if((valido_r(r1) == 1) && (valido_r(r2) == 1))
	{
		divi.num= r1.num * r2.den;
		divi.den= r1.den * r2.num;
	}
	return divi;
}
