#include <iostream>
#include <conio.h>
using namespace std;
int AreaRectangulo(int base, int altura) {//Creación de función tipo int para calcular el área.
	int area = base * altura;//Se hace el calculo del área del rectángulo con los parametros.
	return area;//Se devuelve el resultado del área.
	// otra forma: return base*altura;
}
void main()//Creación de la funcion principal. Los parentesis son para los parametros.
{// Forma de delimitar la función(inicio).
	//A continuación se llaman las funciones
	//Primera funcion
	int Area = AreaRectangulo(2, 6);//Se llama la función y se le dan los valores de base y altura.
	cout << "Area: " << Area << endl;//Se imprime el resultado del proceso.
	system("pause");
}
/*Resultado del código:
* Area: 12
Presione una tecla para continuar . . .
*/
/*Descripción:
El código calcula el area de un rectangulo aplicando la formula en una funcion aparte*/