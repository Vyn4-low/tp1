/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "racionais.h"

int main ()
{
	struct racional sorteado1;
	struct racional sorteado2;
	struct racional soma;
	struct racional subtracao;
	struct racional multiplicacao;
	struct racional divisao;
	int i;
	int n;
	int max;
	scanf("%d", &n);
	scanf("%d", &max);
	if(n > 100)
		n=100;
	if(n < 0)
		n=0;
	if(max > 30)
		max= 30;
	if(max < 0)
		max=0;
	
	

    /* coloque seu codido aqui */
	

	srand(time(NULL));
	for (i=1;i <= n; i++)
	{
		printf("%d: ", i);
		sorteado1= sorteia_r(max);
		sorteado2= sorteia_r(max);
		imprime_r(sorteado1);
		imprime_r(sorteado2);
		if(sorteado1.valido != 1)
		//valido_r(sorteado1) != 1
		{
			printf("NUMERO INVALIDO\n");
			return 1;
		}
		if(sorteado2.valido != 1)
		{
			printf("NUMERO INVALIDO\n");
			return 1;
		}
		
		soma= soma_r(sorteado1,sorteado2);
		subtracao= subtrai_r(sorteado1,sorteado2);
		multiplicacao= multiplica_r(sorteado1,sorteado2);
		divisao= divide_r(sorteado1,sorteado2);
		if(valido_r(divisao) == 0)
		{
			printf("DIVISAO INVALIDA\n");
			return 1;
		}
		imprime_r(soma);
		imprime_r(subtracao);
		imprime_r(multiplicacao);
		imprime_r(divisao);
		printf("\n");
	}
    return 0;
}
