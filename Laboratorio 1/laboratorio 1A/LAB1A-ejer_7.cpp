#include <iostream>
#include <conio.h>
using namespace std;

struct alumno {  //definiendo el tipo de dato 
	int carnet;//Se definen las variables que tendrá la estructura.
	char nombre[50];
	char carrera[5];//Los [] representan la cantidad de caracteres que se pueden almacenar.
	bool activo;
};

void main()//Función principal.
{
	const char* carreraq = "IMT";//Las ubicaciones de los datos se definen.
	const char* Nombreq = "Jose";//Las ubicaciones de los datos se definen.
	alumno Alumno100;     //Definiendo la variable como una estructura
	Alumno100.activo = 1;//Se definen las variables de la estructura.
	Alumno100.carnet = 201563645;//Se definen las variables de la estructura.
	strcpy_s(Alumno100.carrera, carreraq);//se lee el texto y se copia en la estructura.
	strcpy_s(Alumno100.nombre, Nombreq);//se lee el texto y se copia en la estructura.
	cout << "El alumno " << Alumno100.nombre << " fue resgistrado con el numero de carnet " << Alumno100.carnet << endl;
	cout << "en la carrera " << Alumno100.carrera << "." << endl;//Se imprime el nombre, carnet y carrera del alumno.
	system("pause");
}
/*Resultado:
El alumno Jose fue resgistrado con el numero de carnet 201563645
en la carrera IMT.
Presione una tecla para continuar . . .*/
/*Descripción:
El codigo crea una estructura donde se almacenan los datos de un estudiante de diferentes formas
unos de forma directa y otros con la ubicación del texto, de esta forma se muestra la información
respectiva.*/

