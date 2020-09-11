/*juan pablo merchan puentes, laboratorio numero 2.
Este programa consiste en la elaboracion de un menu, mediante el cual se van a ingresar
tres cadenas de caracteres y se se realizaran una serie de procesos.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAN_PUNTO 15

// funciones prottotipo para el menu
void request_data (char *vect1, char *vect2, char *vect3, char *flag);
void compare_words (char *vect1, char *vect2, char *vect3, char flag);
void upside_down (char *vect1, char *vect2, char *vect3, char flag);
void concatenate(char *vect1,char *vect2,char *vect3,char flag);
void size (char *vect1, char *vect2, char *vect3, char flag);
void decimal(char *vect1, char *vect2, char *vect3, char flag);

//funcion principal main
int main(void)
{

	char vect1[CAN_PUNTO];
	char vect2[CAN_PUNTO];
	char vect3[CAN_PUNTO], flag = 0;
	int option = 0;
	
	do{//estructura do while para la elaboracion de las opciones del menu
		
		printf("\n\n\t\t\t\tMENU:\n");
		printf("\t\t\t1. Ingresar palabras, con un tamaño menor a 15 caracteres.\n");
		printf("\t\t\t2. Comparar palabras.\n");
		printf("\t\t\t3. Mostrar palabras al reves.\n");
		printf("\t\t\t4. Concatenar las palabras.\n");
		printf("\t\t\t5. Longitud de cada palabra.\n");
		printf("\t\t\t6. mostrar la suma decimal de los caracteres de cada palabra.\n");
		printf("\t\t\t7. Salir.\n");
		printf("\t\t\tOpcion a escoger: ");
		scanf("\t\t\t%d", &option);
		switch(option)
		{
			case 1:
			request_data ( vect1, vect2, vect3, &flag);//funcion de pedir datos
			break;
			case 2:
			compare_words(vect1, vect2, vect3, flag);
			break;
			case 3:
			upside_down(vect1, vect2, vect3, flag);
			break;
			case 4:
			concatenate(vect1, vect2, vect3, flag);
			break;
			case 5:
			size(vect1, vect2, vect3, flag);
			break;
			case 6:
			decimal(vect1, vect2, vect3, flag);
			break;
			case 7:
			break;
			default:
			printf("\n\nla opcion que ingreso es incorrecta\n");
			
			break;
		}
		
	}while(option != 7);
	return 0;	
}

void request_data (char *vect1, char *vect2, char *vect3, char *flag)
{
	*flag = 1;
	char character1, character2, character3, i = 0;
	printf("\nIngrese la primera palabra: ");
	scanf("%s", &(*vect1));
	printf("ingrese la segunda palabra: ");
	scanf("%s", &(*vect2));
	printf("Ingrese la tercera palabra: ");
	scanf("\n%s", &(*vect3));
	
	
}

void  compare_words(char *vect1, char *vect2, char *vect3, char flag)
{
	if(flag == 1)
	{
		if (*vect1 == *vect2 && *vect1 != *vect3 && *vect2 != *vect3)
		{
			 printf("\nla primera palabra es igual a la segunda."); 
		}
		else if(*vect1 == *vect3 && *vect1 != *vect2 && *vect2 != *vect3)
		{
			printf("\nla primera palabra es igual a la tercera.");
		}
		else if(*vect2 == *vect3 && *vect1 != *vect2 && *vect1 != *vect3)
		{
			printf("\nla segunda palabra es igual a la tercera.");
		}
		else if (*vect2 == *vect3 && *vect1 == *vect2 && *vect3 == *vect1) 
		{
			printf("\nlas tres palabras son iguales.");
		}
		else 
		{
			printf("\nLas tres palabras son diferentes.");
		}
	}
	else
	{
		printf("\nError no ha ingresado las palabras.");
	}
}

void upside_down (char *vect1, char *vect2, char *vect3, char flag)
{
	int tam1, tam2, tam3;
	
	if(flag == 1)
	{
		tam1 = strlen(vect1);
		tam2 = strlen(vect2);
		tam3 = strlen(vect3);
		char word1[tam1],word2[tam2],word3[tam3];
	    
		printf("La primera palabra al reves es : ");
		for(int i = tam1; i>0; i--)
		{
			printf("\t%c",vect1[i-1]);
			
		}
		printf("\nLa segunda palabra al reves es : ");
		for(int i = tam2; i>0; i--)
		{
			printf("\t%c",vect2[i-1]);
			
		}
		printf("\nLa tercera palabra al reves es : ");
		for(int i = tam3; i>0; i--)
		{
			printf("\t%c",vect3[i-1]);
			
		}
	}
	else
	{
		printf("\nError no ha ingresado las palabras.");
	}
}
void concatenate(char *vect1,char *vect2,char *vect3,char flag)
{
	int tam1, tam2, tam3, tam_t;
	
	if(flag == 1)
	{
		tam1 = strlen(vect1);
		tam2 = strlen(vect2);
		tam3 = strlen(vect3);
		tam_t = tam1 + tam2 + tam3;
		char conca[tam_t];
		printf("\nla concatenacion es : ");
		stpcpy(conca, vect1);
	    strcat(conca, " ");
	    strcat(conca, vect2);
		strcat(conca, " ");
	    strcat(conca, vect3);
		printf("%s",conca);
		
	}
	else
	{
		printf("\nError no ha ingresado las palabras.");
	}
	
}
void size (char *vect1, char *vect2, char *vect3, char flag)
{
	int tam1, tam2, tam3;
	
	if(flag == 1)
	{
		tam1 = strlen(vect1);
		tam2 = strlen(vect2);
		tam3 = strlen(vect3);		
		printf("%s%d\n%s%d\n%s%d","La longitud de la primera palabra es : ",tam1,"La longitud de la segunda palabra es : ",tam2,"La longitud de la tercera palabra es : ",tam3);
		
	}
	else
	{
		printf("\nError no ha ingresado las palabras.");
	}
}

void decimal(char *vect1, char *vect2, char *vect3, char flag)
{
	int tam1, tam2, tam3, tam_t,v1t=0,v2t=0, v3t=0,suma= 0;
		
	if(flag == 1)

	{
		tam1 = strlen(vect1);
		tam2 = strlen(vect2);
		tam3 = strlen(vect3);	
		
		for(int n = 0; n <tam1; n++)
		{
			v1t = v1t + vect1[n];
			
		}			
        
		
		
		for(int j = 0; j <tam2; j++)
		{
			v2t = v2t + vect2[j];
			
		}			
        
		
		
		for(int k = 0; k <tam3; k++)
		{
			v3t = v3t + vect3[k];
			
		}			
        
		
		suma = v1t + v2t + v3t;
		printf("\n%d", suma);
		

		 
		
	}
	else
	{
		printf("\nError no ha ingresado las palabras.");
	}
	
}
