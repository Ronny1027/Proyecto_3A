#include <conio.h>
#include <iostream> 
using namespace std;
//IMPLEMENTACION DE RUTINAS
/*
PARAMETROS FORMALES por Valor : Son las variables y sus tipos especificadas entre parentesis en el planteamiento de un método o subrutina. En este caso n y m se ven como "variables locales" y constituyen una copia de las variables que se le pasen como parámetros reales
*/
int RutinaConParametrosxValor(int n, int m) {//El parametro es formal, pasa directamente los valores.
    n = n + 5;
    m = m - 5;
    return n + m;
}

/*
PARAMETROS FORMALES por Referencia: Son las variables y sus tipos especificadas entre paréntesis en el planteamiento de un método o subrutina.  En este caso el "&" denota que n y m se van a comportar como "alias" de las variables que se le pasen como parámetros reales, es decir usaran la misma memoria
*/
int RutinaConParametrosxReferencia(int& n, int& m) {/*El parametro es por referencia,
    pasa la direccion*/
    n = n + 5;
    m = m - 5;
    return n + m;//Proceso de la función.
}

//PROGRAMA PRINCIPAL 
int main() {
    //EJEMPLO 1                                       
    /*
    Empezamos haciendo a = 10 y b = 20, después llamamos a la función "funcion" con las variables a y b como parámetros. Dentro de "funcion" los parametros se llaman n y m, y cambiamos sus valores, sin embargo al retornar a "main", a y b conservan sus valores originales, esto sucede porque lo que pasamos no son las variables a y b, sino que copiamos sus valores a las variables n y m.
    en el ejemplo, la segunda llamada a "funcion". Los valores de los parametros no pueden cambiar al retornar de "funcion", ya que son constantes.
    */
    cout << "**************Ejemplo 1**************" << endl;
    int a, b;
    a = 10;
	b = 20;//Para estos casos, las variables a y b se definen anteriormente a la función.

    //PARAMETROS REALES : Son las variables o valores pasadas en el llamado a la subrutina 
    cout << "Valor de a,b antes del llamado a la rutina por valor->" << a << ", " << b << endl;
    cout << "RutinaConParametrosxValor(a,b) ->" << RutinaConParametrosxValor(a, b) << endl;
    cout << "Valor de a,b luego del llamado a la rutina por valor ->" << a << ", " << b << endl;
    cout << "RutinaConParametrosxValor(10,20) ->" << RutinaConParametrosxValor(10, 20) << endl;


    //EJEMPLO 2                       
    //En este caso, las variables "d" y "e" tendran valores distintos despuis de llamar a la funcisn. Cualquier cambio que realicemos en los parametros dentro de la funcisn, se hara tambiin en las variables referenciadas. Esto quiere decir que no podremos llamar a la funcisn con parametros constantes.    
    cout << "**************Ejemplo 2**************" << endl;
    int d, e;
    d = 10; e = 20;

    //PARAMETROS REALES : Son las variables o valores pasadas en el llamado a la subrutina 
    cout << "Valor de d,e antes del llamado a la rutina por referencia->" << d << ", " << e << endl;
    cout << "d,e ->" << d << ", " << e << endl;
    cout << "RutinaConParametrosxReferencia(d,e) ->" << RutinaConParametrosxReferencia(d, e) << endl;
    cout << "Valor de d,e despues del llamado a la rutina por referencia->" << d << ", " << e << endl;
    /* cout << "funcion(10,20) ->" << funcion(10, 20) << endl;
    es ilegal pasar constantes como parametros cuando estos son referencias */
}
/*Resultado del código:
***************Ejemplo 1**************
Valor de a,b antes del llamado a la rutina por valor->10, 20
RutinaConParametrosxValor(a,b) ->30
Valor de a,b luego del llamado a la rutina por valor ->10, 20
RutinaConParametrosxValor(10,20) ->30
**************Ejemplo 2**************
Valor de d,e antes del llamado a la rutina por referencia->10, 20
d,e ->10, 20
RutinaConParametrosxReferencia(d,e) ->30
Valor de d,e despues del llamado a la rutina por referencia->15, 15

Analisis de casos: En el ejemplo 1 la función es por xValor
, por lo que los valores de las variables a y b no cambian al retornar de la función.
Es como enviar una copia de los valores por lo que estas van a seguir igual.
Luego en el ejemplo 2, la función es por xReferencia, por lo que el valor 
de las variables d y e cambian al retornar de la función debido a que se esta accediendo
a estas atraves del espacio de memoria que ocupan, es decir, se esta accediendo a la misma variable.
*/
