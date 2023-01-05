#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h> 
#include "utils.h"


int FicheiroCheck(char NomeF[100])
{
	char NomeC[100], leitura;
	FILE* NF;

	NF = fopen(NomeF, "r");
	
	if (NF != NULL)
	{
		fgets(NomeC, 100, NF);

		printf("Ficheiro %s existe\n\n", NomeF);
		printf("O nome do Circuito é:\n%s", NomeC);
		printf("\n\nConteudo do ficheiro: \n\n");

		while (fscanf(NF, "%c", &leitura) != EOF)
		{
			printf("%c", leitura);
		}
	}
	
	else
	{
		printf("\nFicheiro %s não existe", NomeF);
		return 1;
	}
}

t_dataOrdenar LerOrdenar(char NomeF[100], int digito)
{
 	setlocale(LC_ALL, "Portuguese");
	FILE* NF;
	int  valor, x;
	char leitura, NomeE[14];
	t_dataOrdenar var;

	NF = fopen(NomeF, "r");

	fgets(var.NomeC, 100, NF);
	var.Qr = 0;
	var.Qv = 0;

	while (fscanf(NF, "%c", &leitura) != EOF)
	{
	

		if ((leitura == 'R') || (leitura == 'r'))
		{

			var.Qr = var.Qr + 1;
			fscanf(NF, " %*s %*s %*s %*d");
		}

		else if ((leitura == 'V') || (leitura == 'v'))
		{
			var.Qv = var.Qv + 1;
			fscanf(NF, "%*s %*s %*s %*d");
		}
		else if (leitura == '.')
			break;

		else continue;
	}
	fclose(NF);


	if (digito == 1)
	{
		NF = fopen(NomeF, "r");

		fgets(var.NomeC, 100, NF);

		while (fscanf(NF, "%c", &leitura) != EOF)
		{

			if ((leitura == 'V') || (leitura == 'v'))
			{
				fscanf(NF, "%*7c %d", &valor);
				x = valor;

				for (int i = 0; i != x; i++)
				{

					if ((i + 1) == valor)
					{
						var.f[i + 1][1] = valor;
						fscanf(NF, "%*5c %d", &valor);
						var.f[i + 1][2] = valor;
					}
					else continue;
				}

				fscanf(NF, "%c", &leitura);
			}


			else if ((leitura == 'R') || (leitura == 'r'))
			{

				fscanf(NF, "%s", &NomeE);
				sscanf(NomeE, "%*12c %d", &valor);
				x = valor;

				for (int i = 0; i != x; i++)
				{

					if ((i + 1) == valor)
					{
						var.r[i + 1][1] = valor;
						fscanf(NF, "%*5c %d", &valor);
						var.r[i + 1][2] = valor;
					}
				}

				fscanf(NF, "%c", &leitura);

			}

			else if (leitura == '.') break;

			else
			{
				printf("ERRO NO FORMATO DO FICHEIRO!");
				fclose(NF);
			}



		}
		fclose(NF);
		return (var);
	}

	else if (digito == 2)
	{
		NF = fopen(NomeF, "r");

		fgets(var.NomeC, 100, NF);

		while (fscanf(NF, "%c", &leitura) != EOF)
		{

			if ((leitura == 'V') || (leitura == 'v'))
			{
				fscanf(NF, "%*s %*s %*s %*d");
				fscanf(NF, "%c", &leitura);
			}


			else if ((leitura == 'R') || (leitura == 'r'))
			{

				fscanf(NF, "%s", &NomeE);
				sscanf(NomeE, "%*12c %d", &valor);
				x = valor;

				for (int i = 0; i != x; i++)
				{

					if ((i + 1) == valor)
					{
						var.r[i + 1][1] = valor;
						fscanf(NF, "%*5c %d", &valor);
						var.r[i + 1][2] = valor;
					}
				}

				fscanf(NF, "%c", &leitura);

			}

			else if (leitura == '.') break;

			else
			{
				printf("ERRO NO FORMATO DO FICHEIRO!");
				fclose(NF);
			}



		}
		fclose(NF);
		return (var);
	}

	else if (digito == 3)
    {
		NF = fopen(NomeF, "r");

		fgets(var.NomeC, 100, NF);

		while (fscanf(NF, "%c", &leitura) != EOF)
		{

			if ((leitura == 'V') || (leitura == 'v'))
			{
				fscanf(NF, "%*7c %d", &valor);
				x = valor;

				for (int i = 0; i != x; i++)
				{

					if ((i + 1) == valor)
					{
						var.f[i + 1][1] = valor;
						fscanf(NF, "%*5c %d", &valor);
						var.f[i + 1][2] = valor;
					}
					else continue;
				}

				fscanf(NF, "%c", &leitura);
			}


			else if ((leitura == 'R') || (leitura == 'r'))
			{

				fscanf(NF, "%s", &NomeE);
				sscanf(NomeE, "%*12c %d", &valor);
				x = valor;

				for (int i = 0; i != x; i++)
				{

					if ((i + 1) == valor)
					{
						var.r[i + 1][1] = valor;
						fscanf(NF, "%*5c %d", &valor);
						var.r[i + 1][2] = valor;
					}
				}

				fscanf(NF, "%c", &leitura);

			}

			else if (leitura == '.') break;

			else
			{
				printf("ERRO NO FORMATO DO FICHEIRO!");
				fclose(NF);
			}



		}
		fclose(NF);
		return (var);
	}

	else return (var);
}

t_dataPesquisar LerPesquisar(char NomeF[100], int digito)
{
	setlocale(LC_ALL, "Portuguese");
	FILE* NF;
	int  valor;
	char NomeInserido[16], NomeC[100], NoMaior[2], NoMenor[2], NoMaiorT[2], NoMenorT[2];
	t_dataPesquisar var;
	NF = fopen(NomeF, "r");

	if (digito == 1)
	{
		printf("\n\nDigite o nome do elemento: ");
		scanf("%s", &NomeInserido);
		fgets(NomeC, 100, NF);
		while (fscanf(NF, "%c %s", &var.leitura, &var.NomeE) != EOF)
		{
			if ((var.leitura == 'V') || (var.leitura == 'v'))
			{
				
				if (strcmp(var.NomeE, NomeInserido) != 0)
				{
					fscanf(NF, "%*5c %*d");
				}

				else if (strcmp(var.NomeE, NomeInserido) == 0)
				{
					fscanf(NF, "%*5c %d", &var.valor);
					break;
				}

				fscanf(NF, "%*c");
			}

			else if ((var.leitura == 'R') || (var.leitura == 'r'))
			{
				if (strcmp(var.NomeE, NomeInserido) != 0)
				{
					fscanf(NF, "%*5c %*d");
				}

				else if (strcmp(var.NomeE, NomeInserido) == 0)
				{
					fscanf(NF, "%*5c %d", &var.valor);
					break;
				}
				fscanf(NF, "%*c");
			}

			else printf("\nNome Incorreto");
		}

		fclose(NF);
		return(var);
	}

	else if (digito == 2)
	{
		printf("\nDigite o nó maior: ");
		scanf(" %s", NoMaior);


		printf("Digite o nó menor: ");
		scanf(" %s", NoMenor);

		int stop = 0;
		fgets(NomeC, 100, NF);
		while (fscanf(NF, "%c %s %s %s %d", &var.leitura, &var.NomeE, &NoMaiorT, &NoMenorT, &var.valor) != EOF)
		{

			if (strcmp(NoMaior, NoMaiorT) == 0 && strcmp(NoMenor, NoMenorT) == 0)
			{
				break;
			}
			
			fscanf(NF, "%*c");
		}
		fclose(NF);
		return(var);
	}

}

t_dataAnalisar LerAnalisar(char NomeF[100])
{
	char leitura, NomeC[100];
	int ValorE = 0;
	FILE* NF;
	t_dataAnalisar var;
	NF = fopen(NomeF, "r");
	
	fgets(NomeC, 100, NF);
	while(fscanf(NF,"%c",&leitura) != EOF)
	{
		if ((leitura == 'V') || (leitura == 'v'))
		{
			fscanf(NF, "%*s %*s %*s %d", &var.FValor);			
		}

		else if ((leitura == 'R') || (leitura == 'r'))
		{
			fscanf(NF, "%*13c %d", &ValorE);
			fscanf(NF, "%*5c %d", &var.RValor[ValorE]);		
		}

		else if (leitura == '\n') 
		{
			continue;
		}
	}

	fclose(NF);
	return(var);
}

int EscreverAnalisar(t_dataAnalisar var)
{
	FILE* NF;
	NF = fopen("Circuit.out", "w");

	fprintf(NF, "---TENSÃO---\nU_bc %.10fV\nU_ad %.10fV\nU_cd %.10fV\nU_ef %.10fV\nU_ae %.10fV\nU_cf %.10fV", var.U[1], var.U[2], var.U[3], var.U[4], var.U[5], var.U[6]);
	fprintf(NF, "\n\n---CORRENTE---\nA_1 %.10fA\nA_2 %.10fA\nA_3 %.10fA", var.A[1], var.A[2], var.A[3]);

	fclose(NF);

}