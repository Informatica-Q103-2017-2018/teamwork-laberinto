#include <stdio.h>
#include <stdlib.h>
char laberinto [6][40][60];
int juego (int, int, int, int);
void estadisticas ();
void intestadisticas (int, int);

void main ()
{
	int seleccion, correcto,i,n,j[6],k[6],l, resultado,w, movimientos;
	
	do
	{
		FILE *pf;
		pf =fopen ("laberintos.txt", "r");
		if (pf == NULL)
		{
			printf ("Problema al abrir el archivo\n");
			system ("pause");
		}
		else
		{
			for (i=0; i<5;i++)
			{
				fscanf (pf, "%d %d", &j[i], &k[i]);
				for (n=0;n<k[i];n++)
				{
					fscanf ( pf, "%s", laberinto[i][n]);
					for (l=0;l<j[i];l++)
					{
						if (laberinto [i][n][l] == 122 ||laberinto [i][n][l] == 90 )
							laberinto [i][n][l] = 32;
					}
				}
			}
			fclose (pf);
		}
		
		do
		{
			printf ("Bienvenido al juego mas guay de laberintos de la historia;\nselecciona un nivel:\n\t1- Laberinto nivel 1\n\t2- Laberinto nivel 2\n\t3- Laberinto nivel 3\n\t4- Laberinto nivel 4\n\t5- Laberinto nivel 5\n\t6- Salir del juego\n\t7- Cargar laberinto\n\t8-Estadisticas Labaerintos\nDespues de hacer su seleccion pulse intro:");
			scanf ("%d", &seleccion);
			seleccion = seleccion-1;
		}
		while(seleccion < 0 || seleccion > 7);
		if (seleccion < 5)
		{
			resultado = juego (seleccion, j[seleccion], k[seleccion], 0);
		}
		else if (seleccion == 5)
			return;
		else if (seleccion == 7)
			estadisticas();
		for (w=0;w<150;w++)
			printf ("\n");
		if (seleccion == 6)
		{
			FILE *pf2;
			pf2 = fopen ("glaberintos.txt", "r");
			if (pf2 == NULL)
			{
				printf ("No hay ninguna partida guardada\n");
			}
			else
			{
				fscanf (pf2, "%d %d", &j[5], &k[5]);
				for (n=0;n<k[5];n++)
				{
					fscanf ( pf2, "%s", laberinto[5][n]);
				}
				fscanf ( pf2, "%d", &movimientos);
				fclose (pf2);
				resultado = juego (seleccion-1, j[5], k[5], movimientos);
			}
		}
	}while (1);
} 

int juego (int numero, int xmax, int ymax, int movimientos)
{
	int n,x,y, cordx, cordy,i,j;
	char movimiento;
	while (1)
	{
		fflush (stdin);
		for (x=0;x<xmax;x++)
		{
			for (y=0;y<ymax;y++)
			{
				if (laberinto [numero] [y] [x] == 80 )
				{
					cordx = x;
					cordy = y;
					laberinto [numero] [y] [x] = 42;
				}
				else if (laberinto [numero] [y] [x] == 42)
				{
					cordx = x;
					cordy = y;
				}
				else if (laberinto [numero] [y] [x] == 122)
					laberinto [numero] [y] [x] =32;
			}
		}
		for (n=0;n<ymax;n++)
		{
			for (i=0; i<xmax; i++)
			{
				printf ("%c", laberinto [numero][n] [i]);
			}
			printf ("\n");
		}
		printf ("Movimientos: %d\tX:%d\tY:%d\nPara guardar, pulse P(borrara cualquier laberinto guardado anteriormente)\nPara salir sin guardar, pulse Q\nSeleccione movimineto con WASD y pulse intro: ", movimientos,cordx+1,ymax-(cordy+1));
		scanf ("%c" , &movimiento);
		fflush (stdin);
		if (movimiento == 97 || movimiento == 65 ) //a
		{
			if ( laberinto [numero] [cordy] [cordx-1] == 35)
			{
				printf ("Movimiento no valido\n");
				movimientos++;
				continue;
			}
			else if ( laberinto [numero] [cordy] [cordx-1] == 64)
			{
				movimientos++;
				
				printf ("Enhorabuena, laberinto solucionado en %d movimientos\n", movimientos);
				intestadisticas (numero, movimientos);
				system ("pause");
				return movimientos;
					}
			else if ( laberinto [numero] [cordy] [cordx-1] == 32)
			{
				laberinto [numero] [cordy] [cordx-1] = 42;
				laberinto [numero] [cordy] [cordx] = 32;
				movimientos++;
				continue;
			}
		}
		
		else if (movimiento == 115 || movimiento == 83 ) //s
		{
			if ( laberinto [numero] [cordy+1] [cordx] == 35)
			{
				printf ("Movimiento no valido\n");
				movimientos++;
				continue;
			}
			else if ( laberinto [numero] [cordy+1] [cordx] == 64)
			{
				movimientos++;
				printf ("Enhorabuena, laberinto solucionado en %d movimientos\n", movimientos);
				intestadisticas (numero, movimientos);
				system ("pause");
				return movimientos;
						}
			else if (laberinto [numero] [cordy+1] [cordx] == 32)
			{
				laberinto [numero] [cordy+1] [cordx] = 42;
				laberinto [numero] [cordy] [cordx] = 32;
				movimientos++;
				continue;
			}
		}
		else if (movimiento == 100 || movimiento == 68 ) //d
		{
			if ( laberinto [numero] [cordy] [cordx+1] == 35)
			{
				printf ("Movimiento no valido\n");
				movimientos++;
				continue;
			}
			else if ( laberinto [numero] [cordy] [cordx+1] == 64)
			{
				movimientos++;
				printf ("Enhorabuena, laberinto solucionado en %d movimientos\n", movimientos);
				intestadisticas (numero, movimientos);
				system ("pause");
				return movimientos;
				 
			}
			else if ( laberinto [numero] [cordy] [cordx+1] == 32)
			{
				laberinto [numero] [cordy] [cordx+1] = 42;
				laberinto [numero] [cordy] [cordx] = 32;
				movimientos++;
				continue;
			}
		}
		else if (movimiento == 119 || movimiento == 87 ) //w
		{
			if ( laberinto [numero] [cordy-1] [cordx] == 35)
			{
				printf ("Movimiento no valido\n");
				movimientos++;
				continue;
			}
			else if ( laberinto [numero] [cordy-1] [cordx] == 64)
			{
				movimientos++;
				printf ("Enhorabuena, laberinto solucionado en %d movimientos\n\n", movimientos);
				intestadisticas (numero, movimientos);
					system ("pause");
				return movimientos;
						}
			else  if ( laberinto [numero] [cordy-1] [cordx] == 32)
			{
				laberinto [numero] [cordy-1] [cordx] = 42;
				laberinto [numero] [cordy] [cordx] = 32;
				movimientos++;
				continue;
			}
		}
		else if (movimiento == 80 || movimiento == 112) //p
		{
			FILE *pf2;
			pf2 = fopen ("glaberintos.txt", "w");
			fprintf (pf2, "%d %d\n", xmax, ymax);
			for (i=0; i<ymax; i++)
			{
				for (n=0; n<xmax;n++)
				{
					if (laberinto [numero] [i] [n] == 42)
					{
						laberinto [numero] [i] [n] = 80;
					}
					else if (laberinto [numero] [i] [n] == 32)
					{
						laberinto [numero] [i] [n] = 122;
					}
				}
				fprintf (pf2, "%s\n", laberinto [numero] [i]); 
			}
			fprintf (pf2, "%d", movimientos);
			fclose (pf2);
			printf ("Laberinto guardado correctamente\n");
			intestadisticas (numero, movimientos);
			return movimientos;
		}
		else if (movimiento == 81 || movimiento == 113)
		{
			intestadisticas (numero, movimientos);
			return movimientos;
		}
	}
} 

void estadisticas ()
{
	FILE *pf;
	int nivel [100], movimientos [100], contador=0,n,laberinto [5]= {0,0,0,0,0}, mlaberintos [5] = {0,0,0,0,0};
	bool total=0;
	pf =fopen ("Estadisticas.txt", "r");
	if (pf==NULL)
	{
		printf ("No hay estadisticas anteriores");
		fclose (pf);
		pf = fopen ("Estadisticas.txt", "w");
		fclose (pf);
		pf =fopen ("Estadisticas.txt", "r");
		printf ("No hay estadisticas anteriores\n");
		system ("pause");
		return;
	}
	while (fscanf (pf, "%d %d", &nivel[contador], &movimientos[contador]) != EOF)
	{
		if (contador >= 99)
		{
			contador = 0;
			total = 1;
		}
		else
			contador ++;
	}
	if (total == 1)
		contador = 100;
	else
		contador++;
	for (n=0;n<contador-1;n++)
	{
		laberinto [nivel[n]]++;
		mlaberintos[nivel[n]]+=movimientos [n];
	}
	printf ("Estadisticas mostradas en porcentaje\n");
	for (n=0;n<5;n++)
	{
		if (laberinto [n] == 0)
		{
			printf ("Usuarios que eligieron laberinto nivel %d: 0%\n", n+1);
		}
		else
		{
			printf ("Usuarios que eligieron laberinto nivel %d: %d\n\tMovimientos medios en el laberinto: %d\n",n+1, 100*laberinto [n]/contador, mlaberintos [n]/laberinto[n]);
		}
	}
	system ("pause");
}

void intestadisticas ( int nivel, int movimiento)
{
	int bnivel, bmovimiento;
	FILE *pf1, *pf2;
	pf1 =fopen ("Estadisticas.txt", "r");
	if (pf1 == NULL)
	{
		fclose (pf1);
		pf1 = fopen ("Estadisticas.txt", "w");
		fprintf (pf1, "%d %d", nivel, movimiento);
		fclose (pf1);
		printf ("Estadisticas guardadas\n");
		return;
	}
	pf2 = fopen ("BEstadisticas.txt.","w");
	while (fscanf (pf1, "%d %d", &bnivel, &bmovimiento)!= EOF)
	{
		fprintf ( pf2, "%d %d\n", bnivel, bmovimiento);
	}
	fprintf (pf2, "%d %d", nivel, movimiento);
	fclose (pf1);
	fclose (pf2);
	pf1 = fopen ( "Estadisticas.txt", "w");
	pf2 = fopen ( "BEstadisticas.txt", "r");
	while (fscanf (pf2, "%d %d", &bnivel, &bmovimiento)!= EOF)
	{
		fprintf (pf1, "%d %d\n", bnivel, bmovimiento);
	}
	fclose (pf1);
	fclose (pf2);
	printf ("Estadisticas guardadas\n");

}