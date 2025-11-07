// EstructuraEstatica.cpp : Defines the entry point for the console application.
//

//importa las librerias
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;

/*esta es la estructura de los datos q poseen los Productos*/
typedef struct T_Producto {
	int Codigo;
	char Descripcion[50];
	float Precio;
	int Disponible;
	bool Activo;
} X;

const int Max = 5677;//Constante que define el maximo de elementos que puede tener la coleccion.
//El maximo que aguanta la coleccion es 5677 elementos.
int Ultimo = 0;// Variable que indica el ultimo elemento insertado en la coleccion.

void CargaAutomaticaDatosProducto(int NCodigo, int NDescripcion, float NPrecio, int NDisponible, T_Producto& Pieza)
{
	cout << "insertando ... ";
	char descrip[50];//Se declara la variable para almacenar la descripcion.
	char texto[20] = "Producto_";//Variable para concatenar el texto con la descripcion.

	Pieza.Codigo = NCodigo;//Cada valor se asigna con la posicion en la que fue guardado.

	_itoa_s(NDescripcion, descrip, 50, 10);//Convierte el numero de descripcion a str y lo guarda en descrip.
	strcat_s(texto, descrip);// Concatena el texto con la descripcion.
	strcpy_s(Pieza.Descripcion, 50, texto);//Copia el texto de en Pieza.Descripcion.

	Pieza.Precio = NPrecio;
	Pieza.Disponible = NDisponible;
	Pieza.Activo = true;

}

void Listar(T_Producto Inventario[Max]) {//Función para mostrar los elementos de la estructura.
	//Se usa el MAX para definir el maximo.
	system("CLS");
	int conta = 1;//Variable para controlar la cantidad de elementos al listar.
	cout << "Listado de  Productos" << endl;
	for (int i = 1; i < Ultimo; i++) {//Se recorre la estructura de datos.
		if (Inventario[i].Activo) {//Muestra el elemento si esta activo.
			cout << Inventario[i].Codigo << " " << Inventario[i].Descripcion << " " << Inventario[i].Precio << " "
				<< Inventario[i].Disponible << " " << endl;
			conta++;//Incrementa la variable cada vez que se muestra un elemento activo.
			if (conta == 7) {//Si se han mostrado 7 elementos, se pausa la pantalla.
				cout << "-----------------------------------" << endl;
				cout << "Presione cualquier tecla para continuar..." << endl;
				system("pause");
				system("CLS");

				conta = 1;//conta se reinicia
			}
		}
	}
	system("pause");
}



int BuscarElemento(T_Producto Inventario[Max], int Cual)/*Función para
buscar un elemento en la estructura junto a su información.*/
{
	bool Encontro = false;//Variable para controlar si se encontro el elemento.
	int Cont = 0;//Variable para recorrer la estructura.

	while ((!Encontro) && (Cont < Ultimo))/*Ciclo que termina cuando se encuentra el elemento
		o cuando se termina toda la estructura.*/
	{
		if ((Inventario[Cont].Activo == true) && (Inventario[Cont].Codigo == Cual))
			Encontro = true;//Se encontro el elemento y esta activo por lo que ahora es True.
		else
			Cont++;//Se sigue sumando hasta que se encuentre el elemento o se termine la estructura.
	}

	if (Encontro == true)
		return Cont;//Se devuelve la ubicación del elemento encontrado.
	else
		return -1;//Si no se encuentra el elemento, se devuelve -1.

}
void InsertarElemento(T_Producto Inventario[Max], T_Producto Unidad)/*Función para 
agregar el elemento a la estructura*/
{
	Inventario[Ultimo] = Unidad;//Se agrega con el indice(ultimo).
	cout << Inventario[Ultimo].Codigo << "   -   " << Inventario[Ultimo].Descripcion << endl;/*
	Cada vez que se inserta la información esta se muestra en la pantalla, se accede a la información a traves
	de los indices(variable Ultimo)*/
	Ultimo++;//se le suma un valor a la posición.
}

void BorrarElemento(T_Producto Inventario[Max], int Cual)/*Función para borrar un elemento.
*/
{
	int PorBorrar;//Para poder verificar si el elemento existe o no.
	PorBorrar = BuscarElemento(Inventario, Cual);

	if (PorBorrar != -1)//Se determina si el producto existe o no.
		Inventario[PorBorrar].Activo = false;//Se desactiva el producto.

}


void main() {//Función principal del programa. Muestra el menú.

	T_Producto PiezasFerreteria[Max];
	T_Producto Elemento;
	int opcion = 0;

	while (opcion < 4) {//Mientras la opcion sea menor a 4, se muestra el menu.

		system("cls");//limpia la pantalla
		cout << "******Menu principal******" << endl;
		cout << "1. Insertar Pieza" << endl;
		cout << "2. Listar Piezas " << endl;
		cout << "3. Borrar Piezas " << endl;
		cout << "4. Salir " << endl;//Opciones de la interfaz.
		cin >> opcion;//captura el numero introducido

		switch (opcion) {

		case 1:
			system("cls");
			Ultimo = 0;
			for (int contador = 0; contador < 51; contador++) {//La función se ejecuta 51 veces.
				CargaAutomaticaDatosProducto(contador, contador, contador, contador, Elemento);/*
				El elemento se guarda con la posicion en la que fue guardado*/
				InsertarElemento(PiezasFerreteria, Elemento);//Se llama a la función para insertar el elemento.
			}
			system("PAUSE");
			break;


		case 2:
			system("cls");
			Listar(PiezasFerreteria);//Llama a la función para listar los elementos.
			break;
		case 3:
			system("CLS");
			int CodigoEscogido;
			cout << "Digite el codigo del Producto a Borrar" << endl;
			cout << "" << endl;
			cout << "CodidoProducto:" << endl;
			cin >> CodigoEscogido;//Se guarda el codigo del producto a borrar.
			BorrarElemento(PiezasFerreteria, CodigoEscogido);
			break;
			//Cada opción llama su respectiva función y hace un break para volver a iniciar.
		}
	}
}
/*Resultados:
* Opción 1- Insertar Pieza:
insertando ... 0   -   Producto_0
insertando ... 1   -   Producto_1
insertando ... 2   -   Producto_2
insertando ... 3   -   Producto_3
insertando ... 4   -   Producto_4
insertando ... 5   -   Producto_5
insertando ... 6   -   Producto_6
insertando ... 7   -   Producto_7
insertando ... 8   -   Producto_8
insertando ... 9   -   Producto_9
insertando ... 10   -   Producto_10
insertando ... 11   -   Producto_11
(con los 51 valores)
* Opción 2- Listar Piezas:
Listado de  Productos
1 Producto_1 1 1
2 Producto_2 2 2
3 Producto_3 3 3
4 Producto_4 4 4
5 Producto_5 5 5
6 Producto_6 6 6
-----------------------------------
Presione cualquier tecla para continuar...
Presione una tecla para continuar . . .
*Opción 3- Borrar Piezas:
* Digite el codigo del Producto a Borrar

CodidoProducto:
3
Listado de  Productos
1 Producto_1 1 1
2 Producto_2 2 2
4 Producto_4 4 4
*/
