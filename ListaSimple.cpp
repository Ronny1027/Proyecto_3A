
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



void GuardarInventario(PtrTArticulo Lista) {//Funcion para guardar el inventario en un archivo de texto.
	FILE* archivo;
	fopen_s(&archivo, "ARCHIVO.txt", "w+");//Se abre el archivo en modo escritura.
	if (NULL == archivo) {//Si no hay archivo.
		printf("No se pudo abrir el archivo.");
	}
	else {
		PtrTArticulo AUX = Lista;//Aux se genera con el valor de la lista.
		while (AUX != NULL) {//Hasta que AUX sea NULL.
			fprintf(archivo, "%i\n", AUX->Codigo);
			fprintf(archivo, "%s\n", AUX->Nombre);
			fprintf(archivo, "%i\n", AUX->Disponible);
			fprintf(archivo, "%f\n", AUX->Precio);
			AUX = AUX->Siguiente;//Para que AUX tome el valor del siguiente elemento.
		}


	}
	fclose(archivo);
}
void CargarInventario(PtrTArticulo& Lista) {//Carga el documento en modo lectura.
	PtrTArticulo Nuevo;
	FILE* archivo;
	fopen_s(&archivo, "ARCHIVO.txt", "r");
	if (NULL == archivo) {
		printf("No se pudo abrir el archivo");//Si no hay archivo.
	}
	else {


		while (!feof(archivo)) {//Hasta que se llegue al final del archivo.
			Nuevo = new(TArticulo);
			char Cadena[20];
			fscanf_s(archivo, "%i\n", &Nuevo->Codigo);
			fscanf_s(archivo, "%s\n", Cadena, 20);
			fscanf_s(archivo, "%i\n", &Nuevo->Disponible);
			fscanf_s(archivo, "%f\n", &Nuevo->Precio);
			strcpy_s(Nuevo->Nombre, Cadena);
			Nuevo->Siguiente = NULL;
			AgregarFinalInventario(Lista, Nuevo);//Se agrega el nuevo elemento al final de la lista.

		}
	}
	fclose(archivo);
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

	for (int i = 100; i <= 200; i++)//Cien iteraciones en incrementos de 1.
	{
		Nuevo = CrearArticulo(i, i, i);//Se envia el contador en cada parametro.
		//Se guarda la direccion con el puntero Nuevo
		AgregarInicioInventario(Abarrotes, Nuevo);/*Los parametros son la lista que se va a modificar
		y el elemento que se le va agregar*/
	}
	GuardarInventario(Abarrotes);
	ListarInventario(Abarrotes);
	Prueba = BuscarArticulo(Abarrotes, 150);//Función agregada para buscar un articulo.

	if (Prueba != NULL)//Si existe el articulo.
		printf("%i", Prueba->Disponible);//Se imprime el elemento que se busca.
	else
		printf("no encontrado !!");//Si no existe el articulo.


	Prueba = BuscarArticulo(Abarrotes, 300);
	if (Prueba != NULL)
		printf("%i", Prueba->Disponible);
	else
		printf("no encontrado !!");
	DestruirInventario(Abarrotes);
	system("cls");
	//*************************PRUEBA DE CARGAR********************************
	InicializarInventario(Prueba);
	CargarInventario(Prueba);
	ListarInventario(Prueba);
	system("pause");
	DestruirInventario(Prueba);
	//************************************************************************
	InicializarInventario(Abarrotes);
	for (i = 200; i <= 300; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarFinalInventario(Abarrotes, Nuevo);
	}
	ListarInventario(Abarrotes);
	DestruirInventario(Abarrotes);




	//************************************************************************	
	InicializarInventario(Llantas);
	for (i = 100; i <= 200; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarInicioInventario(Llantas, Nuevo);
	}
	ListarInventario(Llantas);
	DestruirInventario(Llantas);

	//************************************************************************
	InicializarInventario(Llantas);
	for (i = 200; i <= 300; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarFinalInventario(Llantas, Nuevo);
	}
	ListarInventario(Llantas);
	DestruirInventario(Llantas);


}

/*Resultados:
  81 120 Pieza120  120  120.000000
  82 119 Pieza119  119  119.000000
  83 118 Pieza118  118  118.000000
  84 117 Pieza117  117  117.000000
  85 116 Pieza116  116  116.000000
  86 115 Pieza115  115  115.000000
  87 114 Pieza114  114  114.000000
  88 113 Pieza113  113  113.000000
  89 112 Pieza112  112  112.000000
  90 111 Pieza111  111  111.000000
  91 110 Pieza110  110  110.000000
  92 109 Pieza109  109  109.000000
  93 108 Pieza108  108  108.000000
  94 107 Pieza107  107  107.000000
  95 106 Pieza106  106  106.000000
  96 105 Pieza105  105  105.000000
  97 104 Pieza104  104  104.000000
  98 103 Pieza103  103  103.000000
  99 102 Pieza102  102  102.000000
  100 101 Pieza101  101  101.000000
  101 100 Pieza100  100  100.000000*/
/*Prueba de que se uso la función BuscarArticulo:
150no encontrado !!*/
