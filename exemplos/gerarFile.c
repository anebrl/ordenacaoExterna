/*
 * Autor; Willian Alves
 * Data: 16/04/2016
 * Arquivo sendo gerado com numeros aleatorios
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int contadorNumeros, qtdeNumeros, *vetor = NULL;
	FILE *arquivo;

	if( argc < 2)
	{
		printf("\ntente novamente agora coloque o nome do arquivo de saida\nexemplo: ./bin saida\n");
		system("sleep 3");
		system("clear");
		exit(1);
	}

	printf("\nInforme a qtde de numeros aleatorios que teu arquivo vai ter: ");
	scanf("%d", &qtdeNumeros);

	if ( !(arquivo = fopen (argv[1], "w") ) )
	{
		printf ("\nFalha ao abrir o arquivo.");
		system ("sleep 3");
		system ("clear");
		exit (1);
	}

	srand ( (unsigned)time(NULL) ); /* aqui pego o relogio do pc em segundos para ser a semente, para não termos os mesmo numeros toda vez que executarmos esse programa */

	for (contadorNumeros = 1; contadorNumeros <= qtdeNumeros; contadorNumeros++)
	{
		fprintf (arquivo, "%d\n", ( rand() % qtdeNumeros ));
//		fprintf (arquivo, "\n");
	}
	fclose (arquivo);
	system ("clear");
	return 0;
}

