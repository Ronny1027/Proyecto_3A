
#include <iostream>
#include <conio.h>
using namespace std;
bool EsCuadrado(int base, int altura) {//Función secundaria, ahora de tipo bool.
	if (base == altura) {//Se hace la verificación de si la base es igual a la altura.
		return true;// Si la base es igual a la altura, entonces es true.
	}
	else {
		return false;// Si no, entonces es false.
	}
}
void main()//Función principal.
{

	int base = 0;//Definción de variables.
	int altura = 2;
	cout << "Ingrese la base: " << endl;//Se pide la base. 
	cin >> base;//Guarda el valor dado de la base.
	printf("Ingrese la altura: ");//Mismo proceso pero con un printf y para la altura.
	scanf_s("%i", &altura);//Mismo proceso pero con scanf_s y para la altura.
	bool Cierto = EsCuadrado(base, altura);//el valor de la función se guarda en la variable Cierto.
	cout << Cierto << endl;//se devuelve el valor de la variable Cierto, 1 si es verdadero y 0 si es falso.
	system("pause");
}
/*Resultados del código:
* Caso 1:
* Ingrese la base:
5
Ingrese la altura: 2
0
Presione una tecla para continuar . . .
Caso 2:
Ingrese la base:
4
Ingrese la altura: 4
1
Presione una tecla para continuar . . .
*/
/*Descripción:
El código verifica si es cuadrado o no con la base y la altura, estos datos se solicitan
y luego se llama a una funcion para ver si son iguales o no(True o False) asignando este valor a una variable
luego se muestra el resultado, en el caso 1 es falso(se devuelve 0) y en el caso 2 es verdadero(se devuelve 1).
*/
