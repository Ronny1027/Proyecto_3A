// practicamoralquiz3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



using namespace std;
//******************************************
typedef struct TArticulo
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
	Lista = NULL;//La dirrecion de la lista ahora es NULL.
}
void DestruirInventario(PtrTArticulo& Lista)
{
	PtrTArticulo Aux;
	Aux = Lista;//Se usa Aux con el valor de la lista.
	while (Aux != NULL)//Mientras Aux no sea NULL.
	{
		Lista = Lista->Siguiente;//Se guarda el valor del siguiente elemento en la lista.
		delete(Aux);
		Aux = Lista;//Aux ahora tiene el valor de la lista.
	}
}
PtrTArticulo CrearArticulo(int NCodigo, int NDisponible, float NPrecio)
{
	PtrTArticulo Pieza = new(TArticulo);
	char buffer[5];

	Pieza->Codigo = NCodigo;
	Pieza->Disponible = NDisponible;
	Pieza->Precio = NPrecio;//Se llenan los valores de la estructura.

	strcpy_s(Pieza->Nombre, "Pieza");
	_itoa_s(NCodigo, buffer, 10);
	strcat_s(Pieza->Nombre, buffer);

	Pieza->Siguiente = NULL;//Siguiente ahora apunta a NULL.
	return Pieza;//se devuelve la dirección del nuevo articulo.
}
void AgregarInicioInventario(PtrTArticulo& Lista, PtrTArticulo& Nuevo)
{
	Nuevo->Siguiente = Lista;//El puntero siguiente del nuevo elemento va a apuntar a la lista.
	Lista = Nuevo;//La lista ahora va a tener la direccion que tenia el nuevo elemento.
}
void AgregarFinalInventario(PtrTArticulo& Lista, PtrTArticulo& Nuevo)
{
	PtrTArticulo Aux;
	Aux = Lista;
	if (Aux != NULL)//Si la lista no esta vacia.
	{
		while (Aux->Siguiente != NULL)//Mientras el siguiente elemento no sea NULL.
		{
			Aux = Aux->Siguiente;//Aux cambia de valor
		}

		Aux->Siguiente = Nuevo;//El elemento se agrega y se guarda la dirrecion del nuevo elemento.
	}
	else//Si la lista esta vacia.
	{
		Lista = Nuevo;
	}


}
void ListarInventario(PtrTArticulo& Lista)
{
	int Contador = 1;//Para saber por cual número de articulo se esta pasando.
	PtrTArticulo Aux;//Se genera una variable aux de tipo puntero.
	Aux = Lista;//Aux va a tener la direccion de la lista.
	while (Aux != NULL)//Mientras aux no sea NULL.
	{
		printf(" %d ", Contador);
		printf("%d ", Aux->Codigo);
		printf("%s ", Aux->Nombre);
		printf(" %d ", Aux->Disponible);
		printf(" %f\n ", Aux->Precio);//Se imprimen los valores de la estructura.
		Aux = Aux->Siguiente;//Aux ahora es el valor que le sigue.
		Contador++;//El contador se incrementa en 1.
	}
}
PtrTArticulo BuscarArticulo(PtrTArticulo& Lista, int cual)
{
	bool encontro = false;
	PtrTArticulo Aux;
	Aux = Lista;

	while (!encontro == true && Aux != NULL)
	{
		if (Aux->Codigo == cual)
			encontro = true;
		else
			Aux = Aux->Siguiente;
	}
	return Aux;
}
void main(int argc, char* argv[])
{
	//************************************************************************
	PtrTArticulo Llantas;
	PtrTArticulo Abarrotes;
	PtrTArticulo Nuevo;
	PtrTArticulo Prueba;//Se declaran los 4 punteros.

	//************************************************************************	
	InicializarInventario(Abarrotes);//Abarrotes ahora apunta a NULL.
	int N = 2000;
	
	for (int i = 100; i <= 200; i++)//Cien iteraciones en incrementos de 1.
	{
		int value = rand() % (N + 1);
		Nuevo = CrearArticulo(value, value, value);//Se envia el contador en cada parametro.
		//Se guarda la direccion con el puntero Nuevo
		AgregarInicioInventario(Abarrotes, Nuevo);/*Los parametros son la lista que se va a modificar
		y el elemento que se le va agregar*/
	}
	ListarInventario(Abarrotes);;
}
