#include <iostream>
#include <conio.h>
using namespace std;

void PerimetroRectangulo(int largo, int ancho, int& Perimetro) {/*Función secundaria
	para obtener el perimetro de un rectangulo*/
	Perimetro = (2 * largo) + (2 * ancho);// Cálculo del perímetro
}

void main()//Función principal
{
	int Perim = 0;//Se declara la variable del perímetro con un valor de 0 y tipo int.
	PerimetroRectangulo(2, 6, Perim);//Se llama a la función y se le pasan los datos necesarios.
	cout << "Perimetro: " << Perim << endl << endl;/*Se muestra el resultado del proceso
	y hay un doble salto de linea*/
	system("pause");
}
/*Resultado del código:
Perimetro: 16

Presione una tecla para continuar . . .
*/
/*Descripción:
El código calcula el perimetro de un rectangulo aplicando la formula en una funcion aparte.

*/