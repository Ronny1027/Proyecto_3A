// El #include es para poder incluir bibliotecas/librerias con ciertas funciones.
#include <iostream>//Biblioteca que incluye la instrucción cout.
#include <conio.h>//Biblioteca para manipular entrada/salida por consola.
using namespace std;/*Es para saltarse la parte del "std" en muchas lineas del codigo
esto es necesario para muchos elementos del codigo*/
void main()//Creación de la funcion principal. Los parentesis son para los parametros.
{// Forma de delimitar la función(inicio).
	printf("Hola a Todos \n");//Se escribe un mensaje en la pantalla. El \n es para un salto de línea.
	cout << "Hola Mundo" << endl;/*Funciona igual que el printf pero con sintaxis diferente.
		endl funciona como \n.*/
	system("pause");/*Es para inducir una pausa en el codigo.
	Se muestra en el codigo como "Presione una tecla para continuar . . ."*/
}// Forma de delimitar la función(fin).

/*Resultado del codigo:
Hola a Todos
Hola Mundo
Presione una tecla para continuar . . .
*/
/*Descripción:
El código muestra 2 mensajes en la pantalla*/