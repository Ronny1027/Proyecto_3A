#include <iostream>
#include <conio.h>
using namespace std;
void VolumenRectangulo(float largo, float ancho, float alto) {//Función secundaria para hacer el calculo.
	float Volumen = largo * ancho * alto;//Calculo del volumen del rectangulo
	cout << "El volumen del rectangulo es: " << Volumen << endl;//La respuesta se entrega desde la función secundaria
}
void main()
{
	VolumenRectangulo(2, 4, 6);//Llamado de la función
	system("pause");
}
/*Resultado del codigo:
El volumen del rectangulo es: 48
Presione una tecla para continuar . . .*/
/*Descripción:
El codigo calcula el volumen de un rectangulo haciendo el calculo desde una función secundaria 
y retornando la respuesta desde esa misma función*/