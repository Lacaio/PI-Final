#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "fileio.h"
#include <conio.h>


int Ordenar(char NomeF[100])
{
	setlocale(LC_ALL, "Portuguese");
	int digito, loop;
	t_dataOrdenar var;
	digito = 0;
	loop = 1;
	

	while (loop > 0)
	{

		printf("\n\n----------LISTAR-----------\n\n1 listar tudo \n2 listar resistências \n3 listar fontes \n4 voltar ao menu \n");
		while (getchar() != '\n');
		scanf("%d", &digito);

		var = LerOrdenar(NomeF, digito);

		if (digito == 1)
		{
			printf("\nO circuito com nome\n%stem estes elementos:\n\n", var.NomeC);

			for (int i = 1; i <= var.Qv; i++)
			{
				printf("V Fonte_%d %d\n", var.f[i][1], var.f[i][2]);
			}

			for (int i = 1; i <= var.Qr; i++)
			{
				printf("R Resistencia_%d %d\n", var.r[i][1], var.r[i][2]);
			}
		}

		else if (digito == 2)
		{
			printf("\nO circuito com nome\n%stem estas resistencias:\n\n", var.NomeC);

			for (int i = 1; i <= var.Qr; i++)
			{
				printf("R Resistencia_%d %d\n", var.r[i][1], var.r[i][2]);
			}

		}

		else if (digito == 3)
		{
			printf("\nO circuito com nome\n%stem estas fontes:\n\n", var.NomeC);

			for (int i = 1; i <= var.Qv; i++)
			{
				printf("V Fonte_%d %d\n", var.f[i][1], var.f[i][2]);
			}


		}

		else if (digito == 4)
		{
			break;
		}

	}
}

int Pesquisar(char NomeF[100])
{
	setlocale(LC_ALL, "Portuguese");
	int digito, loop;
	

	digito = 0;
	loop = 1;
	while(loop > 0)
	{
		printf("\n\n----------PESQUISAR-----------\n\n1 pesquisar por um elemento com o Nome do Elemento \n2 pesquisar por um elemento por Nós de conexão \n3 voltar ao menu\n");
		while (getchar() != '\n');
		scanf("%d", &digito);
		t_dataPesquisar var;
		if (digito == 1)
		{
			var = LerPesquisar(NomeF, digito);
			if ((var.leitura == 'V') || (var.leitura == 'v'))
			{
				printf("\nV %s %d", var.NomeE, var.valor);
			}
			else if ((var.leitura == 'R') || (var.leitura == 'r'))
			{
				printf("\nR %s %d", var.NomeE, var.valor);
			}
		}

		else if (digito == 2)
		{
			var = LerPesquisar(NomeF, digito);
			if ((var.leitura == 'V') || (var.leitura == 'v'))
			{
				printf("\n%c %s %d",var.leitura, var.NomeE, var.valor);
			}
			else if ((var.leitura == 'R') || (var.leitura == 'r'))
			{
				printf("\n%c %s %d",var.leitura, var.NomeE, var.valor);
			}
		}

		else if (digito == 3)
		{
			break;
		}
	}
}

int Analisar(char NomeF[100])
{
	char NomeOut[100];
	int Req2, Req3;
	float Rtot, somaT,soma2, soma3;
	t_dataAnalisar var;
	
	var = LerAnalisar(NomeF);
	
	Req2 = var.RValor[2] + var.RValor[3];
	Req3 = var.RValor[4] + var.RValor[5] + var.RValor[6];
	soma2 = 1 / (float)Req2;
	soma3 = 1 / (float)Req3;
	somaT = soma2 + soma3;
	Rtot = 1 / somaT;
	Rtot = Rtot + var.RValor[1];
	var.A[1] = (float)var.FValor / Rtot;
	soma2 = Req2 + Req3;
	soma3 = (float)Req3 / soma2;
	var.A[2] = var.A[1] * soma3;
	soma3 = (float)Req2 / soma2;
	var.A[3] = var.A[1] * soma3;
    
	var.U[1] = var.A[1] * (float)var.RValor[1];
	var.U[2] = var.A[2] * (float)var.RValor[2];
	var.U[3] = var.A[2] * (float)var.RValor[2];
	var.U[4] = var.A[3] * (float)var.RValor[4];
	var.U[5] = var.A[3] * (float)var.RValor[5];
	var.U[6] = var.A[3] * (float)var.RValor[6];
	
	printf("\n\n---TENSÃO---\nU_bc %.10fV\nU_ad %.10fV\nU_cd %.10fV\nU_ef %.10fV\nU_ae %.10fV\nU_cf %.10fV", var.U[1], var.U[2], var.U[3], var.U[4], var.U[5], var.U[6]);
	printf("\n\n---CORRENTE---\nA_1 %.10fA\nA_2 %.10fA\nA_3 %.10fA", var.A[1], var.A[2], var.A[3]);

	EscreverAnalisar(var);
}