#include <stdio.h>
#include <stdlib.h>

//Realizar un programa que realize operaciones con matrices utilizando punteros y asignación de memoria dinamica.

int lecturaMatriz (int ***matrizCulera, int *numfilas, int *numcol)
{
	int i,j;
	int exito=1;
	int **matrizita;
	
	system ("cls");
	printf("Ingrese el numero de filas: \n");
	scanf("%d", numfilas);
	printf("Ingrese el numero de columnas: \n");
	scanf("%d", numcol);
	
	matrizita = (int **) calloc (*numfilas, sizeof(int*));
	
		if (matrizita == NULL)
	    {
		printf("No se pudo asignar ese numero de columnas, agrege numeros pequeños o llame a su asistente. \n");
		exito=0;
        }
      else
      {
      	for (i=0; i<(*numfilas); i++)
		{
			matrizita[i] = (int *) calloc (*numcol, sizeof(int));
			if (matrizita[i] == NULL)
			{
				printf ("Operación incorrecta");
				exito=0;
			}

		}
	*matrizCulera=matrizita;
	
	if(exito)
	{
			for (i=0; i<(*numfilas); i++)
			{
				for (j=0; j<(*numcol); j++)
				{
						printf ("Ingrese los elementos [%d,%d]: ",i,j);
					    scanf  ("%d",&matrizita[i][j]);
				}
			}
	}
   }
   
   return exito;
   }
   
int SumaMatriz (int **matrizA, int **matrizB, int ***matrizRes, int numfilas, int numcol)
{
	system ("cls");
	int i, j;
	int **matrizita;
	
	matrizita = (int **) calloc (numfilas, sizeof(int*));
	if (matrizita == NULL)
	{
	printf("No se pudo realizar la suma, ocurrio un error, llame a su asistente. \n");
    }
    
     else
      {
      	for (i=0; i<numfilas; i++)
		{
			matrizita[i] = (int *) calloc (numcol, sizeof(int));
			if (matrizita[i] == NULL)
			{
				printf ("Operación incorrecta. Ocurrio un error. Vuelva a intentarlo mas tarde.\n");
			}
			
			}
	}
	
	for (i=0; i<numfilas; i++)
	{
		for (j=0; j<numcol; j++)
		{
			matrizita[i][j]=matrizA[i][j]+matrizB[i][j];
		}
         }	
         
  	*matrizRes=matrizita;	
}


int MultiplicacionMatriz (int **matrizA, int **matrizB, int ***matrizRes, int numfilas, int numcol)
{
	system ("cls");
	int i, j, k, contador;
	int **matrizita;
	
	matrizita = (int **) calloc (numfilas, sizeof(int*));
	if (matrizita == NULL)
	{
	printf("No se pudo realizar la suma, ocurrio un error, llame a su asistente. \n");
    }
    
     else
      {
      	for (i=0; i<numfilas; i++)
		{
			matrizita[i] = (int *) calloc (numcol, sizeof(int));
			if (matrizita[i] == NULL)
			{
				printf ("Operación incorrecta. Ocurrio un error. Vuelva a intentarlo mas tarde.\n");
			}
			
			}
	}
	
	for (i=0; i<numfilas; i++)
	{
		for (j=0; j<numcol; j++)
		{
			for (contador=0, k=0; k<numcol; k++)
			{
				contador=contador+matrizA[i][k]*matrizB[k][j];
			}
			matrizita[i][j]=contador;
		}
	}
	
		*matrizRes=matrizita;	
}

int menu (int *opcion)

{
	system ("cls");
	printf ("Programa que hace calculos de matrices \n\n");
	printf ("Leer matriz A......................1\n");
	printf ("Leer Matriz B......................2\n");
	printf ("Suma de matrices...................3\n");
	printf ("Multiplicacion de matrices A*B.....4\n");
	printf ("Multiplicacion de matrices B*A.....5\n");
	printf ("Salir..............................6\n");
	scanf ("%d", opcion);
}

int main ()
{
	int **matrizA, **matrizB, **matrizC, opcion, n1, m1, n2, m2, exito, i, j, liberar; 
	
	do{
	menu (&opcion);
	switch(opcion)
	{
		case 1:  
    		exito = lecturaMatriz(&matrizA, &n1, &m1);
    		for(i=0; i<n1; i++)
		    for(j=0; j<m1; j++)
			printf("Elemento[%d][%d]=%d\n", i,j, matrizA[i][j]);
	        getch ();
    		break;
    		
    	case 2:  
    		exito = lecturaMatriz (&matrizB, &n2, &m2);
    		for(i=0; i<n2; i++)
		    for(j=0; j<m2; j++)
			printf("Elemento[%d][%d]=%d\n", i,j, matrizB[i][j]);
	        getch ();
    		break;
    	
		case 3:
    		if (n1==n2 && m1==m2)
    		{
    		SumaMatriz(matrizA, matrizB, &matrizC, n1, n2);
    		printf("La suma de las matrices es: \n\n");
    		for (i=0; i<n1; i++)
		    {
			printf ("\n|");
			for (j=0; j<m1; j++)
			{
			printf ("%d ",matrizC[i][j]);
			}
			printf ("|");
		    }
		    printf("\n");
		    liberar=1; 
		    }
		    else
		    {
			printf("La operacion no se pudo realizar\n");
		    }
		    getch ();
    		break;
    
    		case 4:
    		if (m1==n2)
    		{
    		MultiplicacionMatriz(matrizA, matrizB, &matrizC, n1, m2);
    		printf("La multiplicacion de las matrices es: \n\n");
			for (i=0; i<n1; i++)
		    {
			printf ("\n|");
			for (j=0; j<m2; j++)
			{
			printf ("%d ",matrizC[i][j]);
			}
			printf ("|");
		    }
		    printf("\n");
		    liberar=2;
		    }
		    else
		    {
			printf("La operacion no se pudo realizar\n");
		    }
		    getch ();
		    break;
	
		    case 5:
    		if (m2==n1)
    		{
    		MultiplicacionMatriz(matrizA, matrizB, &matrizC, n1, m2);
    		printf("La multiplicacion de las matrices es: \n\n");
			for (i=0; i<n1; i++)
		    {
			printf ("\n|");
			for (j=0; j<m2; j++)
			{
			printf ("%d ",matrizC[i][j]);
			}
			printf ("|");
		    }
		    printf("\n");
		    liberar=3;
		    }
		    else
		    {
			printf("La operacion no se pudo realizar\n");
		    }
		    getch ();
		    break;
		    }
     } while(opcion!=6);
     
     for (i=0; i<n1; i++)
	{
		free (matrizA[i]);
	}
	free (matrizA);
	
	for (i=0; i<n2; i++)
	{
		free (matrizB[i]);
	}
	free (matrizB);
	
	if (liberar==1 || liberar==2)
	{
		for (i=0; i<n1; i++)
		{
			free (matrizC[i]);
		}
		free (matrizC);
	}
	else
	{
		for (i=0; i<n2; i++)
		{
			free (matrizC[i]);
		}
		free (matrizC);
	}
}
