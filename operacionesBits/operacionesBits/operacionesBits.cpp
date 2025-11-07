// Bits_funciones
/*Integrantes:
-Daniel Alejandro Arrieta Víquez
-Ronny Espinoza Cordero
-Cristhofer Herrera
*/


#include <stdio.h>
#include <math.h>
using namespace std;

//Verifica si el bit en la posición "cual" está encendido (es 1)
bool BitEncendido(int Simbolo, int cual)
{
	int Mascara = 1; //Se inicializa la máscara

	Mascara = Mascara << cual; //Se corre la máscara "cual" posiciones a la izquierda
	if ((Simbolo & Mascara) == 0)
		return false;    //Da 0 lo que significa que la posicion cual estaba en 0
	else return true;	//Da <>0 lo que significa que la posicion cual estaba en 1

}

//Verifica si el bit en la posición "cual" está apagado (es 0)
bool BitApagado(int Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	if ((Simbolo & Mascara) == 0)
		return true; //Da 0 lo que significa que la posicion cual estaba en 0
	else return false;	// Da <>0 lo que significa que la posicion cual estaba en 1

}

//Enciende el bit en la posición "cual" del símbolo
void EncenderBit(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual; //Se corre la máscara "cual" posiciones a la izquierda
	Simbolo = Simbolo | Mascara; //Se aplica OR para encender el bit
}

//Apaga el bit en la posición "cual" del símbolo
void ApagarBit(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual; //Desplaza la máscara a la posición a apagar
	Mascara = ~Mascara; //Se niega la máscara para tener 0 en la posición deseada
	Simbolo = Simbolo & Mascara; //Se aplica AND para apagar el bit
}

//Imprime los bits del símbolo de forma visual, de izquierda a derecha
void PinteBits(int Simbolo)
{
	int Uno = 1;
	int Cero = 0;
	for (int i = 7; i >= 0; --i) //Recorre desde el bit más significativo al menos
	{
		if (BitEncendido(Simbolo, i))
			printf("%d ", Uno); //Imprime 1 si el bit está encendido
		else
			printf("%d ", Cero); //Imprime 0 si el bit está apagado
	}

	printf("\n");
}


//Invertir_x_Posicion
void Invertir_x_Posicion(int& Numero)
{
	int Resultado = 0;
	for (int i = 0; i < 8; i++)
	{
		if (BitEncendido(Numero, i)) //Si el bit i está encendido
		{

			EncenderBit(Resultado, 7 - i); //Enciende su opuesto
		}
	}
	Numero = Resultado; //Reemplaza el número original
}
//Invertirxvalor
void Invertirxvalor(int& Numero)
{
	Numero = ~Numero;
}

//Listar a pantalla el valor binario y su conversión a decimal calculada "a pie"
int BytetoInteger(int Byte)
{
	printf("--- Listado de Conversión a Decimal 'a pie' ---\n");
	printf("--------------------------------------------------\n");
	printf("Decimal | Binario  | Calculo Manual -> Resultado\n");
	printf("--------------------------------------------------\n");

	long sumaDecimal = 0;
	printf("%-8d| ", Byte); //Imprime el número decimal
	PinteBits(Byte);       //Imprime la representación en bits
	printf(" | ");

	//Calcula el valor "a pie"
	for (int j = 0; j < 8; ++j)
	{
		if (BitEncendido(Byte, j))
		{
			long potencia = static_cast<long>(pow(2, j));
			sumaDecimal += potencia;
			printf("(1*%ld)", potencia);
		}
		else
		{
			//No se suma nada si el bit es 0
		}
		if (j < 7 && BitEncendido(Byte, j + 1)) {
			//Solo imprime el '+' si no es el último bit y el siguiente bit sumará algo
			bool hayMasBits = false;
			for (int k = j + 1; k < 8; ++k) {
				if (BitEncendido(Byte, k)) {
					hayMasBits = true;
					break;
				}
			}
			if (hayMasBits) printf(" + ");
		}
	}
	printf(" -> %ld\n", sumaDecimal);

	printf("--------------------------------------------------\n\n");
	return sumaDecimal;
}


//Programa principal:
int main(int argc, char* argv[])
{
	int Prueba = 0;
	int j;

	//Prueba de encender y apagar cada bit individualmente
	for (j = 0; j <= 7; j++)
	{
		printf("%s \n", "------------------");
		EncenderBit(Prueba, j);       // Enciende el Bit en la posicion "j"
		printf("%d :", Prueba); PinteBits(Prueba);
		ApagarBit(Prueba, j);		// Apaga el Bit en la posicion "j"
		printf("%d :", Prueba); PinteBits(Prueba);//Queda en 0 porque apago el Bit encendido.
	}

	for (j = 0; j <= 255; j++)
	{
		printf("Numero %d : ", j);
		PinteBits(j);
	}

	//Invertir_x_Posicion:
	printf("---Invertir-x-Posicion---\n");

	int Numero = 100;
	printf("Numero original (%d): ", Numero);
	PinteBits(Numero);

	Invertir_x_Posicion(Numero); //Llama la función que invierte los bits por posición

	printf("Numero Invertido (%d): ", Numero);
	PinteBits(Numero);

	//Invertir_x_valor:
	printf("---Invertir-x-valor---\n");
	int PruebaInver = 219;

	printf("Valor inicial\n");
	PinteBits(PruebaInver);

	Invertirxvalor(PruebaInver);
	printf("Valor invertido\n");
	PinteBits(PruebaInver);

	//Listar a pantalla el valor binario y su conversión a decimal calculada "a pie"
	int PruebaDeci = 150;

	BytetoInteger(PruebaDeci);

	return 0;


}
