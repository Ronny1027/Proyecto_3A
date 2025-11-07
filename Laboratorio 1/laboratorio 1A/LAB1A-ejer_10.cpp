#include <iostream>
#include <conio.h>
using namespace std;
struct alumno {
	int carnet;
	char nombre[50];
	char carrera[5];
	bool activo;
};
void main()
{
	const char* carreraq = "IMT";
	const char* Nombreq = "Jose";
	alumno Alumno100[1000];//El arreglo ahora es de 1000 elementos.
	Alumno100[1].activo = 1;//Las variables se deben definir con el número del elemento del arreglo.
	Alumno100[1].carnet = 201563645;
	strcpy_s(Alumno100[1].carrera, carreraq);
	strcpy_s(Alumno100[1].nombre, Nombreq);
	cout << "El alumno " << Alumno100[1].nombre << " fue resgistrado con el numero de carnet " << Alumno100[1].carnet << endl;
	cout << "en la carrera " << Alumno100[1].carrera << "." << endl;/*Se muestra la información del [1]
	ya que ahi es donde esta la información*/
	system("pause");
}
/*Resultado:
El alumno Jose fue resgistrado con el numero de carnet 201563645
en la carrera IMT.
Presione una tecla para continuar . . .*
/*Descripción:
El codigo crea una estructura donde se almacenan los datos de un estudiante de diferentes formas
unos de forma directa y otros con la ubicación del texto, de esta forma se muestra la información
respectiva.En este caso el arreglo esta hecho para poder almacenar 1000 datos de estudiante por
lo que se debe especificar en cual numero de alumno se va a guardar la información y cual
numero de alumno se va a mostrar.*/
