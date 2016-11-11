/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
	free(arr1);
	free(arr2);
	arr1 = NULL;	//Nomas por si acaso
	arr2 = NULL;	
	
    return 0;
}

// función que compara dos enteros
int cmp_int(const void *a, const void *b){
	int *acom = (int*) a, *bcom = (int *) b;
	return (*acom < *bcom ? -1 : (*acom > *bcom));
}

// función que compara dos doubles
int cmp_double(const void *a, const void *b) {
	double *acom = (double*) a, *bcom = (double *) b;
	return (*acom < *bcom ? -1 : (*acom > *bcom));
}

// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num) {
	int i;
	for(i = 0; i < num;)
		printf("%d ", arreglo[i++]);
	printf("\n");
}
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num) {
	int i;
	for(i = 0; i < num;)
		printf("%.3lf ", arreglo[i++]);
	printf("\n");
}
