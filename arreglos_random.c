#include "arreglos_random.h"

/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max) {
	srand(time(NULL));	//usamos el tiempo para cambiar los valores de rand()
	int i, *arr = (int*) calloc(num, sizeof(int));
	for(i = 0; i < num; i++)
		arr[i] = min + rand()%max;
	return arr;
}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max) {
	srand(time(NULL));		//usamos el tiempo para cambiar los valores de rand()
	double *arr = (double*) calloc(num, sizeof(double));
	int i;
	for(i = 0; i < num; i++)
		arr[i] = (rand()/(double)RAND_MAX)*(max-min) + min;	//hago los rand() dobles
	return arr;
}
