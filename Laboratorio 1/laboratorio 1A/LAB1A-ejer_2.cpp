#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
	int a = 2;// Se declara una variable tipo int y se le asigna el valor 2.
	float b = 3.5;// Se declara una variable tipo float y se le asigna el valor 3.5.
	float c = a + b;// Se declara una variable tipo float y se le asigna el valor de la suma de a y b.
	cout << "El valor de a+b es: " << c << " centimetros." << endl;/*Imprime el resultado
	de la suma. Sintaxis propia de cout*/
	printf("el valor de a+b es: %f \n", c);/*También imprime el resultado de la suma. El %f es
	para indicar en que parte de texto va la variable es "%f"porque es float*/
	system("pause");
}
/*Resultado del codigo:
El valor de a+b es: 5.5 centimetros.
el valor de a+b es: 5.500000
Presione una tecla para continuar . . .*/
/*El código hace la suma de dos valores, 2 y 3.5. Luego los muestra en la pantalla*/

