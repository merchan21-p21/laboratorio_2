
/*JUAN PABLO MERCHAN PUENTES, primer punto del laboratorio 2.
se realiza un algorimo el cual mediante dos puntos x y y va a relaizar el proceso de 
una ecuacion lineal*/
#include <stdio.h>
#include <stdlib.h>
#define CAN_PUNTO 2

struct point
{
	float x;
	float y;
};
//Funciones prototipo
void request_data( struct point *points, char *flag);
void pending(struct point *points, char *result, char flag);
void cut_y(struct point *points,char flag, char *cut, char result);
void equation(struct point *points, char flag, char result);

int main(void)
{
	//struct punto result[CAN_PUNTO];
	struct point points[CAN_PUNTO];
	char result, flag, cut = 0;
	int option = 0;
	
	do{
		
		printf("\n\n\t\t\t\tMENU:\n");
		printf("\t\t\t1. Ingresar puntos.\n");
		printf("\t\t\t2. Mostrar pendiente.\n");
		printf("\t\t\t3. Mostrar cruce con el eje y.\n");
		printf("\t\t\t4. Mostrar ecuacion.\n");
		printf("\t\t\t5. Salir.\n");
		printf("\t\t\tOpcion a escoger: ");
		scanf("\t\t\t%d", &option);
		switch(option)
		{
			case 1:
			request_data( points, &flag);//funcion de pedir datos
			break;
			case 2:
			pending(points,&result, flag);//funcion de la mendiente
			break;
			case 3:
			cut_y(points, flag, &cut, result);//funcion conter con el eje y
			break;
			case 4:
			equation(points, flag, result);
			break;
			case 5:
			break;
			default:
			printf("\n\nla opcion que ingreso es incorrecta\n");
			//getch();
			break;
		}
		
	}while(option != 5);
	return 0;	
}

void request_data(struct point *points, char *flag)
{
	*flag = 1;
	printf("\nIngrese el primer numero: ");
	printf("\nIngrese la coordenada x1: ");
	scanf("%f", &points[0].x);
	printf("Ingrese la coordenada y1: ");
	scanf("%f", &points[0].y);
	printf("\nIngrese el segundo numero: ");
	printf("\nIngrese la coordenada x2: ");
	scanf("%f", &points[1].x);
	printf("Ingrese la coordenada y2: ");
	scanf("%f", &points[1].y);
}
void pending(struct point *points, char *result, char flag)
{
	if(flag == 1)
	{
		float m = 0; // la letra 'm' simboliza la pendiente
		*result = m;
		m = ((points[1].y - points[0].y)/(points[1].x - points[0].x));
		printf("\n%s%f\n\n","el resultado de la pendiente es m = ",m);
		
		
	}
	else{
		printf("\nLo siento, no ha ingresado los puntos.\n");
		printf("por favor ingreselos en la opcion '1'.\n\n");
	}
	
}
void cut_y(struct point *points,char flag, char *cut, char result)
{
	float m, result_f, b= 0;
	if(flag == 1)
	{
		m = ((points[1].y - points[0].y)/(points[1].x - points[0].x));
		result_f= (-1*(m * points[0].x));
		b =result_f + points[0].y;
		
		printf("\n%s%f","El corte con el eje y es = ",b);
	}
	else
	{
		printf("\nLo siento, no ha ingresado los puntos.\n");
		printf("por favor ingreselos en la opcion '1'.\n\n");
	}
}
void equation(struct point *points, char flag, char result)
{
	
	if(flag == 1 )
	{
		float result_f,m, b = 0;
		m =((points[1].y - points[0].y)/(points[1].x - points[0].x));
		result_f= (-1*(m * points[0].x));
		b =result_f + points[0].y;
		if(b >= 0)
		{
			printf("%s%f%s%f","y =",m," x + ",b);
		}
		else
		{
			printf("%s%f%s%f","y =",m," x ",b);
		}
	}

	else
	{
		printf("\nLo siento, no ha ingresado los puntos.\n");
		printf("por favor ingreselos en la opcion '1'.\n\n");	
	}
}
