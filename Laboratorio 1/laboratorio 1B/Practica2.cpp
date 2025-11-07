// Lab 2 2012.cpp: define el punto de entrada de la aplicaci&#65533;n de consola.
//
#include <iostream>
#include <conio.h>
#include "milibreria.h"
using namespace std;


void main()/*El menú funciona como una forma en la que el usuario pueda seleccionar la opción que
desea llevar a cabo, dependiendo de la opción que se digite se llevara a cabo una funcion que se
encuentran antes en el código, esto se logra a traves de una variable que almacena el número de opción
y termina cuando el usuario selecciona el número 5, cuando haga esto el valor booleano cambiara y terminara
el ciclo. Cuando se selecciona una operación se borra el menu y se hace la función, luego el usuario
podra volver a usar el menu.*/
{
	int opc;//valor que almacena la opción del menú.
	bool menu = true;//el valor booleano se usa para controlar el ciclo del menú.
	while (menu) {
		system("CLS");//Comando para limpiar la pantalla.
		cout << " ********* Menu semana 1 *********" << endl << endl;
		cout << "  1. AreaRectangulo(base,altura)" << endl;//Se muestran las opciones del menú.
		cout << "  2. PerimetroRectangulo(largo,ancho,Perim)" << endl;
		cout << "  3. VolumenRectangulo(largo,alto,ancho)" << endl;
		cout << "  4. Cierto=EsCuadrado(base, altura)" << endl;
		cout << "  6. Suma de valores" << endl;
		cout << "  5. Salir" << endl;
		cout << endl << "	Digite la opcion: ";//Espacio para que el usuario ingrese la opción.
		cin >> opc;//Se almacena la opción en la variable opc.
		switch (opc) {
		case 1: {
			system("CLS");
			cout << "Opcion 1" << endl << endl << endl;//Se muestra la opción seleccionada.
			//Primera funcion
			int base = 0;
			int altura = 2;
			cout << "Ingrese la base: " << endl;
			cin >> base;
			cout << "Ingrese la altura: " << endl;//Se solicitan los datos necesarios.
			cin >> base;
			int Area = AreaRectangulo(base, altura);//Se llama a la función.
			cout << "Area: " << Area << endl;
			system("pause");
			break;
		}
		case 2: {
			system("CLS");
			cout << "Opcion 2" << endl << endl << endl;
			//Segunda Funcion
			int Perim = 0;
			int largo = 0;
			int ancho = 2;
			cout << "Ingrese el largo: " << endl;
			cin >> largo;
			cout << "Ingrese el ancho: " << endl;
			cin >> ancho;
			PerimetroRectangulo(largo, ancho, Perim);
			cout << "Perimetro: " << Perim << endl << endl;
			system("pause");
			break;
		}
		case 3: {
			system("CLS");
			cout << "Opcion 3" << endl << endl << endl;
			int alto = 0;
			int largo = 0;
			int ancho = 2;
			cout << "Ingrese el largo: " << endl;
			cin >> largo;
			cout << "Ingrese el ancho: " << endl;
			cin >> ancho;
			cout << "Ingrese la altura: " << endl;
			cin >> alto;
			//Tercera Funcion
			VolumenRectangulo(largo, ancho, alto);
			system("pause");
			break;
		}
		case 4: {
			system("CLS");
			cout << "Opcion 4" << endl << endl << endl;
			//Cuarta funcion
			int base = 0;
			int altura = 2;
			cout << "Ingrese la base: " << endl;
			cin >> base;
			printf("Ingrese la altura: ");
			scanf_s("%i", &altura);
			bool Cierto = EsCuadrado(base, altura);
			cout << Cierto << endl;
			system("pause");
			break;
		}
		case 5: {
			menu = false;//El valor booleano cambia y termina el ciclo.
			system("CLS");
			cout << "Opcion 5: salir" << endl << endl << endl;
			cout << "Viva e TEC" << endl;
			system("Pause");
			break;
		}
		case 6: {
			system("CLS");
			cout << "Opcion 6" << endl << endl << endl;
			//Función original. 
			int valo1 = 0;
			int valo2 = 0;
			int resul = 0;
			cout << "Ingrese el valor 1: " << endl;
			cin >> valo1;
			cout << "Ingrese el valor 2: " << endl;
			cin >> valo2;
			sumaValos(valo1, valo2, resul);
			cout << "Resultado de la suma: " << resul << endl << endl;
			system("pause");
			break;//Termina la opción.
		}
		}
	}
	}

