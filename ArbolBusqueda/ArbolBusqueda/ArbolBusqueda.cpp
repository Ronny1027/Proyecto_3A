// Raizbb.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include <stdio.h>


typedef struct NodoBB
{
	int llave;
	NodoBB* HijoIzquierdo;
	NodoBB* HijoDerecho;
}X;


bool Insertar(NodoBB*& Raiz, int cualllave)
{
	if (Raiz == NULL)
	{
		Raiz = new(NodoBB);
		Raiz->llave = cualllave;
		Raiz->HijoIzquierdo = NULL;
		Raiz->HijoDerecho = NULL;
		return true;
	}
	else
	{
		if (cualllave == Raiz->llave) return false;
		else
			if (cualllave < Raiz->llave) return Insertar(Raiz->HijoIzquierdo, cualllave);
			else return Insertar(Raiz->HijoDerecho, cualllave);
	}
}



void PodarHojas(NodoBB*& Raiz)
{
	if (Raiz != NULL)
	{
		PodarHojas(Raiz->HijoIzquierdo);
		PodarHojas(Raiz->HijoDerecho);
		printf("Borro : %i \n", Raiz->llave);
		delete(Raiz); Raiz = NULL;
	}
}

NodoBB* Buscar(NodoBB* Raiz, int cualllave)
{
	if (Raiz == NULL)
	{
		return NULL;
	}
	else
	{
		if (cualllave == Raiz->llave) return Raiz;
		else
			if (cualllave < Raiz->llave) return Buscar(Raiz->HijoIzquierdo, cualllave);
			else return Buscar(Raiz->HijoDerecho, cualllave);
	}
}

void PreOrdenRID(NodoBB* Raiz)
{
	if (Raiz != NULL)
	{
		printf("%i  ", Raiz->llave);
		PreOrdenRID(Raiz->HijoIzquierdo);
		PreOrdenRID(Raiz->HijoDerecho);
	}
}

void EnOrdenIRD(NodoBB* Raiz)
{
	if (Raiz != NULL)
	{
		EnOrdenIRD(Raiz->HijoIzquierdo);
		printf("%i  ", Raiz->llave);
		EnOrdenIRD(Raiz->HijoDerecho);
	}
}
void PosOrdenIDR(NodoBB* Raiz)
{
	if (Raiz != NULL)
	{
		PosOrdenIDR(Raiz->HijoIzquierdo);
		PosOrdenIDR(Raiz->HijoDerecho);
		printf("%i  ", Raiz->llave);
	}
}

void main(int argc, char* argv[])
{
	NodoBB* ArbolEnteros = NULL;

	printf("\nINSERTANDO la secuencia de Elementos : 9, 6, 16, 3, 13, 8, 18 ");
	Insertar(ArbolEnteros, 65);
	Insertar(ArbolEnteros, 50);
	Insertar(ArbolEnteros, 23);
	Insertar(ArbolEnteros, 70);
	Insertar(ArbolEnteros, 82);
	Insertar(ArbolEnteros, 68);
	Insertar(ArbolEnteros, 39);

	printf("\n\nRECORIENDO: ");
	printf("\nElementos en recorrido PreOrden : ");
	PreOrdenRID(ArbolEnteros);

	printf("\nElementos en recorrido EnOrden : ");
	EnOrdenIRD(ArbolEnteros);

	printf("\nElementos en recorrido PosOrden : ");
	PosOrdenIDR(ArbolEnteros);

	printf("\n\nBUSCANDO 1 x 1 : ");
	NodoBB* Aux;
	if ((Aux = Buscar(ArbolEnteros, 18)) != NULL) printf("\nBusco %i y encontro %i ", 18, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros, 8)) != NULL) printf("\nBusco %i y encontro %i ", 8, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros, 13)) != NULL) printf("\nBusco %i y encontro %i ", 13, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros, 3)) != NULL) printf("\nBusco %i y encontro %i ", 3, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros, 16)) != NULL) printf("\nBusco %i y encontro %i ", 16, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros, 6)) != NULL) printf("\nBusco %i y encontro %i ", 6, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros, 9)) != NULL) printf("\nBusco %i y encontro %i ", 9, Aux->llave);

	printf("\n\nBORRANDO TODO ... de las hojas a la Raiz:\n");
	PodarHojas(ArbolEnteros);
	system("pause");
}
