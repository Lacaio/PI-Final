#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "fileio.h"



int main(void)
{
	char NomeF[100];

	printf("\nNome do ficheiro: ");
	scanf("%s", &NomeF);
	menu(NomeF);
}

int menu(char NomeF [100])
{
	setlocale(LC_ALL, "Portuguese");
    int loop, input;

	loop = 1;
	FicheiroCheck(NomeF);
	while (loop > 0)
	{
         input = NULL;
		printf("\n\n\n-----------MENU------------\n\n\n1 para ordenar elementos \n2 para pesquisar por um elemento \n3 para analisar o circuito\n4 para fechar o programa\n");
		while (getchar() != '\n');
		scanf("%d", &input);


		if (input == 1)
		{

			Ordenar(NomeF);
		}

		else if (input == 2)
		{

			Pesquisar(NomeF);
		}

		else if (input == 3)
		{
			Analisar(NomeF);
		}

		else if (input == 4)
		{
			return main;
		}
	}
}