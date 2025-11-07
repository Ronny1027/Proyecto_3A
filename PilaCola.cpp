// Pila_Cola.cpp: define el punto de entrada de la aplicación de consola.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;
//******************************************
typedef struct TArticulo//Se define la estructura del articulo.
{
	int Codigo;
	char Nombre[20];
	int Disponible;
	float Precio;
	TArticulo* Siguiente;
}*PtrTArticulo;


//******************************************

int i;  //parametro global


void InicializarInventario(PtrTArticulo& Lista)
{
	Lista = NULL;//La estructura inicia apuntando a NULL.
}
void DestruirInventario(PtrTArticulo& Lista)
{
	PtrTArticulo Aux;//Se crea Aux de tipo PtrTArticulo.
	Aux = Lista;//Aux toma el valor de la lista.
	while (Aux != NULL)//Mientras que no se llegue al final de la lista.
	{
		Lista = Lista->Siguiente;//Lista toma otra dirección.
		delete(Aux);//Se borra el contenido que hay en la dirección de Aux.
		Aux = Lista;//Aux toma una nueva dirección.
	}
}
PtrTArticulo CrearArticulo(int NCodigo, int NDisponible, float NPrecio)
{
	PtrTArticulo Pieza = new(TArticulo);
	char buffer[5];

	Pieza->Codigo = NCodigo;
	Pieza->Disponible = NDisponible;
	Pieza->Precio = NPrecio;//Los parametros se asignan a los campos de la estructura.

	strcpy_s(Pieza->Nombre, "Pieza");
	_itoa_s(NCodigo, buffer, 10);
	strcat_s(Pieza->Nombre, buffer);

	Pieza->Siguiente = NULL;
	return Pieza;//Devuelve la dirección del nuevo articulo.
}
void AgregarInicioInventario(PtrTArticulo& Lista, PtrTArticulo& Nuevo)
{
	Nuevo->Siguiente = Lista;//El nuevo elemento apunta al antiguo primer elemento.
	Lista = Nuevo;//Lista ahora es el nuevo elemento.
}
void AgregarFinalInventario(PtrTArticulo& Lista, PtrTArticulo& Nuevo)
{
	PtrTArticulo Aux;
	Aux = Lista;//Toma el valor de la lista.
	if (Aux != NULL)
	{
		while (Aux->Siguiente != NULL)//Para antes de llegar al final de la lista.
		{
			Aux = Aux->Siguiente;//Para poder seguir avanzando en la lista.
		}

		Aux->Siguiente = Nuevo;//El ultimo elemento ahora apunta al nuevo elemento.
	}
	else
	{
		Lista = Nuevo;
	}


}
void ListarInventario(PtrTArticulo& Lista)
{
	int Contador = 1;
	PtrTArticulo Aux;
	Aux = Lista;
	while (Aux != NULL)//Eecorre toda la lista y por cada elemento imprime sus datos.
	{
		printf(" %d ", Contador);
		printf("%d ", Aux->Codigo);
		printf("%s ", Aux->Nombre);
		printf(" %d ", Aux->Disponible);
		printf(" %f\n ", Aux->Precio);
		Aux = Aux->Siguiente;//Para poder continuar en la lista.
		Contador++;
	}
}
PtrTArticulo BuscarArticulo(PtrTArticulo& Lista, int cual)
{
	return Lista;
}


void GuardarInventario(PtrTArticulo Lista) {//Guarda la información en un archivo de texto.
	FILE* archivo;
	fopen_s(&archivo, "ARCHIVO.txt", "w+");//Abre el archivo en modo escritura.
	if (NULL == archivo) {//En caso de que el archivo no exista.
		printf("No se pudo abrir el archivo.");
	}
	else {
		PtrTArticulo AUX = Lista;
		while (AUX != NULL) {
			fprintf(archivo, "%i\n", AUX->Codigo);
			fprintf(archivo, "%s\n", AUX->Nombre);
			fprintf(archivo, "%i\n", AUX->Disponible);
			fprintf(archivo, "%f\n", AUX->Precio);
			AUX = AUX->Siguiente;
		}


	}
	fclose(archivo);//cierra el archivo
}
void CargarInventario(PtrTArticulo& Lista) {
	PtrTArticulo Nuevo;
	FILE* archivo;
	fopen_s(&archivo, "ARCHIVO.txt", "r");//Abre el archivo en modo lectura
	if (NULL == archivo) {
		printf("No se pudo abrir el archivo");
	}
	else {


		while (!feof(archivo)) {//antes de llegar al final del archivo.
			Nuevo = new(TArticulo);
			char Cadena[20];
			fscanf_s(archivo, "%i\n", &Nuevo->Codigo);
			fscanf_s(archivo, "%s\n", Cadena, 20);
			fscanf_s(archivo, "%i\n", &Nuevo->Disponible);
			fscanf_s(archivo, "%f\n", &Nuevo->Precio);
			strcpy_s(Nuevo->Nombre, Cadena);
			Nuevo->Siguiente = NULL;
			AgregarFinalInventario(Lista, Nuevo);//guarda los datos en el programa.

		}
	}
	fclose(archivo);//cierra el archivo.
}

void Push(PtrTArticulo& Lista, PtrTArticulo Nuevo) {//Operación push de la pila
	AgregarInicioInventario(Lista, Nuevo);/*
	Utiliza la operación agregar inicio ya que se esta trabajando con pilas
	y los elementos se agregan al principio.*/
	//
}
PtrTArticulo Top(PtrTArticulo& Lista) {
	return Lista;//Devuelve el valor que hay en la dirección lista
}
PtrTArticulo Pop(PtrTArticulo& Lista) {
	PtrTArticulo Aux = Lista;//Apunta al valor primer valor actual.
	Lista = Lista->Siguiente;//Lista ahora apunta al nuevo primer elemento.
	Aux->Siguiente = NULL;//El elemento extraido es desenlazado de la lista.
	return Aux;//Devuelve el elemento que fue extraido.
}
void Encolar(PtrTArticulo& Lista, PtrTArticulo Nuevo) {
	AgregarFinalInventario(Lista, Nuevo);/*Muy parecido al push pero aqui
	se agrega al final ya que es una operación de cola*/
}

PtrTArticulo Primero(PtrTArticulo& Lista) {//Misma operación del top pero aplicado a Cola
	return Lista;
}
PtrTArticulo Descolar(PtrTArticulo& Lista) {
	PtrTArticulo Aux = Lista;//Apunta al valor primer valor actual.
	Lista = Lista->Siguiente;//Lista ahora apunta al nuevo primer elemento.
	Aux->Siguiente = NULL;//El elemento extraido es desenlazado de la lista.
	return Aux;//Devuelve el elemento que fue extraido.
}







void main(int argc, char* argv[])
{
	//************************************************************************
	PtrTArticulo Pila_Llantas;
	PtrTArticulo Cola_Pasajeros; // de Bus
	PtrTArticulo Nuevo;
	int i;
	//Creación de variables para hacer las pruebas
	//************************************************************************	


	InicializarInventario(Pila_Llantas);//Se inicia la pila
	InicializarInventario(Cola_Pasajeros);//Se inicia la cola
	int opc;
	bool menu = true;
	while (menu) {
		system("CLS");
		cout << " ********* Menu de pila *********" << endl << endl;
		cout << "  1. Usar Pila" << endl;
		cout << "  2. Usar cola" << endl;
		cout << "  3. Salir" << endl;
		cout << endl << "	Digite la opcion: ";
		cin >> opc;
		switch (opc) {
		case 1: {
			int opc;
			bool menu = true;
			while (menu) {
				system("CLS");
				cout << " ********* Submenu de pila *********" << endl << endl;
				cout << "  1. Push de 100 elementos" << endl;
				cout << "  2. Top" << endl;
				cout << "  3. Pop" << endl;
				cout << "  4. Salir" << endl;
				cout << endl << "	Digite la opcion: ";
				cin >> opc;
				switch (opc) {
				case 1: {// INSERTANDO CON PUSH
					system("CLS");
					cout << "Haciendo Push de 100 elementos" << endl;

					for (i = 1; i <= 100; i++)
					{
						Nuevo = CrearArticulo(i, i, i);
						Push(Pila_Llantas, Nuevo);//Se llama a push con la lista y la direccion del nuevo elemento.
						cout << "Se acaba de hacer PUSH, el Top de la Pila ahora es: " << endl << Top(Pila_Llantas)->Codigo << endl;
					}//Se imprime el nuevo valor agregado
					system("pause");
					break;
				}
				case 2: {// PREGUNTANDO POR EL TOP
					system("CLS");
					if (Top(Pila_Llantas) != NULL)//en caso de que la pila este vacia
						cout << "El Top de la Pila es: " << endl << Top(Pila_Llantas)->Codigo << endl;
					else
						cout << "El Top de la Pila es: NULO " << endl;

					system("pause");
					break;
				}
				case 3: { //SACANDO CON POP
					system("CLS");
					PtrTArticulo Aux = Pop(Pila_Llantas);//Se obtiene el valor del Pop para imprimirlo
					if (Top(Pila_Llantas) != NULL)
						cout << "Se acaba de hacer POP, el Top de la Pila ahora es: " << endl << Top(Pila_Llantas)->Codigo << endl;
					else
						cout << "Se acaba de hacer POP, el Top de la Pila ahora es:  NULO " << endl;

					system("pause");
					break;
				}
				case 4: {// SALIENDO Y DEVOLVIENDO MEMORIA DINAMICA
					system("CLS");
					menu = false;
					system("CLS");
					cout << "Liberando memoria ... " << endl << endl << endl;
					DestruirInventario(Pila_Llantas);//se borra la memoria utilizada
					system("Pause");
					break;
				}
				}
			}
			system("pause");
			break;
		}
		case 2: {
			int opc;
			bool menu = true;
			while (menu) {
				system("CLS");
				cout << " ********* Submenu de cola *********" << endl << endl;
				cout << "  1. Encolar" << endl;
				cout << "  2. Primero" << endl;
				cout << "  3. Descolar" << endl;
				cout << "  4. Salir" << endl;
				cout << endl << "	Digite la opcion: ";
				cin >> opc;
				switch (opc) {
				case 1: {// ENCOLAR
					system("CLS");
					cout << "Haciendo Encolar de 50 elementos" << endl;

					for (i = 1; i <= 50; i++)
					{
						Nuevo = CrearArticulo(i, i, i);
						Encolar(Cola_Pasajeros, Nuevo);
						cout << "Se acaba de hacer ENCOLAR al final de la Cola de : " << Nuevo->Codigo << endl;
					}

					system("pause");
					break;
				}
				case 2: {// PRIMERO
					system("CLS");
					cout << "El primero que va a ser atendido de la cola es : " << Primero(Cola_Pasajeros)->Codigo << endl;
					system("pause");
					break;
				}
				case 3: {// DESCOLAR
					system("CLS");

					PtrTArticulo Aux = Descolar(Cola_Pasajeros);

					if (Primero(Cola_Pasajeros) != NULL)
						cout << "Se acaba de hacer DESCOLAR, el nuevo primero  de la Cola ahora es: " << endl << Primero(Cola_Pasajeros)->Codigo << endl;
					else
						cout << "Se acaba de hacer DESCOLAR, el primero de la Cola ahora es:  NULO " << endl;

					system("pause");
					break;
				}
				case 4: {// SALIENDO Y DEVOLVIENDO MEMORIA DINAMICA
					menu = false;
					system("CLS");
					cout << "Liberando memoria ... " << endl << endl << endl;
					DestruirInventario(Cola_Pasajeros);
					system("Pause");
					break;
				}
				}
			}
			system("pause");
			break;
		}
		case 3: {
			menu = false;
			system("CLS");
			cout << "Opcion 5: saliendo . . ." << endl << endl << endl;
			cout << "ADIOS!!!" << endl;
			system("Pause");
			break;
		}
		}
	}
}

/*Resultados:
 ********* Menu de pila *********

  1. Usar Pila
  2. Usar cola
  3. Salir

		Digite la opcion:
Primero se muestra el menu, aqui se selecciona que tipo de lista enlazada se quiere usar
*/
/*Al seleccionar la opción 1 se muestra el siguiente submenu:
 ********* Submenu de pila *********

  1. Push de 100 elementos
  2. Top
  3. Pop
  4. Salir

		Digite la opcion:
		Aquí se pueden ejecutar las funciones basicas de una pila*/
/*Al seleccionar la opción 1 se muestra el siguiente resultado:
Se acaba de hacer PUSH, el Top de la Pila ahora es:
93
Se acaba de hacer PUSH, el Top de la Pila ahora es:
94
Se acaba de hacer PUSH, el Top de la Pila ahora es:
95
Se acaba de hacer PUSH, el Top de la Pila ahora es:
96
Se acaba de hacer PUSH, el Top de la Pila ahora es:
97
Se acaba de hacer PUSH, el Top de la Pila ahora es:
98
Se acaba de hacer PUSH, el Top de la Pila ahora es:
99
Se acaba de hacer PUSH, el Top de la Pila ahora es:
100
Presione una tecla para continuar . . .
Esto demuestra que se hizo un push de 100 elementos desde 1 hasta 100*/
/*Al seleccionar la opción 2 se muestra el siguiente resultado:
*El Top de la Pila es:
100
Presione una tecla para continuar . . .
Aqui se imprime el valor del top de la pila*/
/*Al seleccionar la opción 3 se muestra el siguiente resultado:
* Se acaba de hacer POP, el Top de la Pila ahora es:
99
Presione una tecla para continuar . . .
Aquí se hace un pop y para demostrar que se hizo se imprime el nuevo valor del top
Liberando memoria ...Al seleccionar esta opción


Presione una tecla para continuar . . .
En este parte se libera la memoria utilizada por la pila  */
/*Despues de esto se muestra de nuevo el menu principal y ahora al seleccionar la opcion
2, la opcion de cola se muestra lo siguiente:
 ********* Submenu de cola *********

  1. Encolar
  2. Primero
  3. Descolar
  4. Salir

		Digite la opcion:*/
/*Al seleccionar la opción 1 se muestra el siguiente resultado:
Se acaba de hacer ENCOLAR al final de la Cola de : 34
Se acaba de hacer ENCOLAR al final de la Cola de : 35
Se acaba de hacer ENCOLAR al final de la Cola de : 36
Se acaba de hacer ENCOLAR al final de la Cola de : 37
Se acaba de hacer ENCOLAR al final de la Cola de : 38
Se acaba de hacer ENCOLAR al final de la Cola de : 39
Se acaba de hacer ENCOLAR al final de la Cola de : 40
Se acaba de hacer ENCOLAR al final de la Cola de : 41
Se acaba de hacer ENCOLAR al final de la Cola de : 42
Se acaba de hacer ENCOLAR al final de la Cola de : 43
Se acaba de hacer ENCOLAR al final de la Cola de : 44
Se acaba de hacer ENCOLAR al final de la Cola de : 45
Se acaba de hacer ENCOLAR al final de la Cola de : 46
Se acaba de hacer ENCOLAR al final de la Cola de : 47
Se acaba de hacer ENCOLAR al final de la Cola de : 48
Se acaba de hacer ENCOLAR al final de la Cola de : 49
Se acaba de hacer ENCOLAR al final de la Cola de : 50
Aqui los elementos se agregan haciendo un encolar, y lo que se muestra corresponde 
al final de la cola*/
/*Al seleccionar la opción 2 se muestra el siguiente resultado:
* El primero que va a ser atendido de la cola es : 1
Presione una tecla para continuar . . .
Aquí se puede ver que el elemento primero no corresponde a al ultimo que fue agregado
como es el caso de la pila*/
/*Al seleccionar la opción 3 se muestra el siguiente resultado:
* Se acaba de hacer DESCOLAR, el nuevo primero  de la Cola ahora es:
2
Presione una tecla para continuar . . .
Aquí se puede observar que con descolar el nuevo primer elemento es el 2, que es el
siguiente al que fue desenlazado*/
/*Al seleccionar la opción 4 se muestra el siguiente resultado:
* Liberando memoria ...


Presione una tecla para continuar . . .
Aquí de igual forma se libera la memoria utilizada por la cola*/
