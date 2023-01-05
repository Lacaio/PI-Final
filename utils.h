#ifndef MY_HEADERFILE
#define MY_HEADERFILE

	int Ordenar(char NomeF[100]);

    typedef struct s_dataO
	{
		int Qv, Qr, f[10][10], r[10][10];
		char NomeC[100]; 
		
	} t_dataOrdenar;

	int Pesquisar(char NomeF[100]);

	typedef struct s_dataP
	{
		int valor;
		char  NomeE[16], leitura;

	}t_dataPesquisar;


	int Analisar(char NomeF[100]);

	typedef struct s_dataA
	{
		int  RValor[7], FValor;
		float A[4], U[7];

	}t_dataAnalisar;

#endif