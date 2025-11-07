// SHELL SORT :

#include <stdio.h>

void shell_sort(int arr[], int n) {
	int gap, i, j, temp;//Variable para el intervalo, indices y valor temporal
	for (gap = n / 2; gap > 0; gap /= 2) {//Comenzar con un intervalo grande y reducirlo
		for (i = gap; i < n; i++) {//Realizar una inserción por cada elemento en el intervalo
			temp = arr[i];//Guardar el valor actual
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {//Desplazar los elementos del intervalo hacia la derecha
				arr[j] = arr[j - gap];//Mover el elemento mayor hacia la derecha
            }
			arr[j] = temp;//Colocar el valor temporal en su posición correcta
        }
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90, 15, 78, 43, 89, 3, 67, 99, 1, 55, 32, 77, 18, 29 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shell_sort(arr, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("El máximo del arreglo es %d\n", arr[n - 1]);

    return 0;
}

