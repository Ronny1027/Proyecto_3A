#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
	int ArregloDeCienEnteros[100];//Se declara la variable, un arreglo de 100 enteros.
	for (int i = 0; i < 100; i++) {/*inicio del ciclo for con las tres partes del ciclo.
		1. El ciclo inicia en 1. 2. El ciclo es hasta llegar a 100. 3. Cada vez el dato i aumenta 1*/
		ArregloDeCienEnteros[i] = i;//Se asigna el valor de i.
		cout << "Fue agregado el numero " << ArregloDeCienEnteros[i] << " en el Arreglo." << endl;
		//Se imprime el valor de i y sigue el ciclo.
	}

	system("pause");
}
/*Resultado:
* Fue agregado el numero 0 en el Arreglo.
Fue agregado el numero 1 en el Arreglo.
Fue agregado el numero 2 en el Arreglo.
Fue agregado el numero 3 en el Arreglo.
Fue agregado el numero 4 en el Arreglo.
Fue agregado el numero 5 en el Arreglo.
Fue agregado el numero 6 en el Arreglo.
Fue agregado el numero 7 en el Arreglo.
Fue agregado el numero 8 en el Arreglo.
Fue agregado el numero 9 en el Arreglo.
Fue agregado el numero 10 en el Arreglo.
Fue agregado el numero 11 en el Arreglo.
Fue agregado el numero 12 en el Arreglo.
Fue agregado el numero 13 en el Arreglo.
Fue agregado el numero 14 en el Arreglo.
Fue agregado el numero 15 en el Arreglo.
Fue agregado el numero 16 en el Arreglo.
Fue agregado el numero 17 en el Arreglo.
Fue agregado el numero 18 en el Arreglo.
Fue agregado el numero 19 en el Arreglo.
Fue agregado el numero 20 en el Arreglo.
Fue agregado el numero 21 en el Arreglo.
Fue agregado el numero 22 en el Arreglo.
Fue agregado el numero 23 en el Arreglo.
Fue agregado el numero 24 en el Arreglo.
*/
/*Descripción:El codigo es un ciclo para mostrar un arreglo de 100 enteros, de forma que
se accede a la ubicación de ese entero y de ahi se obtiene el número para mostrarlo
y luego seguir con el ciclo.*/