#include <string.h>
#include <stdlib.h>
#include "b_sort.h"

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/
void bsort(void* base, size_t num, size_t size,
            int (*compar)(const void*, const void*)) {
	int i, change;
	void *tmp = malloc(size);	//hacemos espacio para guardar datos temporales
	num *= size;
	do {
		change = 0;
		for(i = 0; i < num; i+=size) {
			if( compar(base+i, base+i-size) == -1 ) {
				memcpy(tmp, base+i-size, size);		//copiamos en espacio temporal
				memcpy(base+i-size, base+i, size);	//cambiamos de
				memcpy(base+i, tmp, size);
				change = 1;
			}
		}	
		num -= size;
	}while(change);
}
