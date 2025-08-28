/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "racional.h"

/* programa principal */
int main ()
{
    /* Declara todas as variaveis e structs necessarias */
	struct racional sorteado1;
	struct racional sorteado2;
	struct racional soma;
	struct racional subtracao;
	struct racional multiplicacao;
	struct racional divisao;
	long i;
	long n;
	long max;
	/* Scaneia "n" e "max" */
	scanf("%ld %ld", &n, &max);
	/* Verifica se "n" eh maior que "100", se for recebe "100" */
	if(n > 100)
		n = 100;
	/* Verifica se "n" eh negativo, se for recebe "0" */
	if(n < 0)
		n = 0;
	/* Verifica se "max" eh maior que "30", se for recebe "30" */
	if(max > 30)
		max = 30;
	/* Verifica se "max" eh negativo, se for recebe "0" */
	if(max < 0)
		max = 0;

    srand (0); /* use assim, com zero */
    
    /* a completar! */

    /*Semente aleatoria 
	srand(time(NULL));*/

	for (i = 1;i <= n; i++)
	{	
		/* Imprime a iteração */
		printf("%ld: ", i);
		/* Sorteia dois racionais */
		sorteado1= sorteia_r(-max,max);
		sorteado2= sorteia_r(-max,max);
		/* Imprime os sorteados */
		imprime_r(sorteado1);
		imprime_r(sorteado2);
		/* Se algum dos sorteados for invalido, imprime que eh invalido */
		if(valido_r(sorteado1) != 1)
		{
			printf("NUMERO INVALIDO\n");
			return 1;
		}
		if(valido_r(sorteado2) != 1)
		{
			printf("NUMERO INVALIDO\n");
			return 1;
		}
		/* Operacoes com racionais, soma, multiplicacao etc */
		soma = soma_r(sorteado1,sorteado2);
		subtracao = subtrai_r(sorteado1,sorteado2);
		multiplicacao = multiplica_r(sorteado1,sorteado2);
		divisao = divide_r(sorteado1,sorteado2);
		/* Verifica se a divisao eh invalida, se for imprime que eh invalida */
		if(valido_r(divisao) == 0)
		{
			printf("DIVISAO INVALIDA\n");
			return 1;
		}
		/* Imprime todas os racionais operados e uma linha em branco */
		imprime_r(soma);
		imprime_r(subtracao);
		imprime_r(multiplicacao);
		imprime_r(divisao);
		printf("\n");
    }
    return (0) ;
}
