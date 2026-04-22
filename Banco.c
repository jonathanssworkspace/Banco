/* ING.Jonathan
Banco.
22/8/25 
*/

/**
 * char: 8 bits, %c.
 * int: 16 bits, %i.
 * float: 32 bits, %f.
 */
#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Se implementara la libreria stdio para poder utilizar las siguientes funciones:
 * -printf(" "); -> imprimir en consola.
 * -scanf("%i", &variable); -> para guardar los datos introducidos desde la consola.
 */

 // Banco con 2 usuarios autorizados, ciclico y hacer uso de los 4 tipos de funciones.

/* to do variables */
char usu[10];
char con[5];
int accesoConcedido = 0;
float DineroInicial = 1562.59;

const char* Usuarios[] = {
    "Jonathan",
    "Profesor"
};

const char* Contrasenas[] = {
    "1234",
    "4321"
};
/* to do functions */

//funcion sin parametro de entrada y con retorno de datos.
bool validacion(){
    for (int i = 0; i < 2; i++) {
        if (strcmp(usu, Usuarios[i]) == 0 && 
            strcmp(con, Contrasenas[i]) == 0) {
            return true;
        }
    }
    return false;
}
/*strcmp = string compare: devuelve 0 si son exactamente iguales las cadenas que compara en orden (cadena1, cadena2) 
Devuelve un valor negativo si cadena1 va antes que cadena2 alfabéticamente.
Devuelve un valor positivo si cadena1 va después que cadena2.
ejemplo:
strcmp("hola", "hola")     → 0          // Son iguales
strcmp("abc", "abd")       → negativo   // 'c' < 'd'
strcmp("perro", "gato")    → positivo   // 'p' > 'g'
strcmp("Hola", "hola")     → negativo   // 'H' < 'h' en ASCII
strcmp("hola", "holas")    → negativo   // "hola" es más corta
*/ 

//funcion con parametro de entrada y sin retorno de datos.
void Deposito(float d){
    DineroInicial = DineroInicial + d;
    printf("Tu saldo es de %.2f\n", (DineroInicial));
}

//funcion con parametro de entrada y con retorno de datos.
float Retirar(float r){
    DineroInicial = DineroInicial - r;
    return DineroInicial;
}

//funcion sin parametro de entrada y sin retorno de datos.
void Consulta(){
    printf("Tu saldo es de %.2f\n", DineroInicial);
}

//funcion sin parametro de entrada y sin retorno de datos.
void main(){
    do
    {
        int op;
        printf("Usuario: \n");
        scanf("%9s", usu);
        printf("contrasena: \n");
        scanf("%4s", con); //si se pasa del buffer lo guarda y se usa en la siguiente entrada de dato.
        accesoConcedido = validacion();
        if (accesoConcedido) {
            printf("Acceso concedido\n");
            do{
                printf("-----Menu-----\n");
                printf("1) Depositar\n");
                printf("2) Retirar\n");
                /*printf("3) Consulta de saldo\n");*/
                printf("4) Salir\n");
                scanf("%i", &op);
                system("cls");
                switch (op)
                {
                    float dep, ret;
                    case 1:
                        printf("Ingrese la cantidad que desea depositar:\n");
                        scanf("%f", &dep);
                        Deposito(dep);
                        break;
                    case 2:
                        printf("Ingrese la cantidad que desea retirar:\n");
                        scanf("%f", &ret);
                        if(ret > DineroInicial || ret == 0){
                            printf("No se puede retirar mas de lo que tienes en la cuenta o 0\n");
                        }else{
                            printf("Tu saldo es de %.2f\n", Retirar(ret));
                        }
                        break;
                    case 3:
                        Consulta();
                        break;
                    case 4:
                        printf("Sesion cerrada\n");
                        break;         
                    default:
                        printf("opcion no valida\n");
                        break;
                }
            } while (op != 4);
        } else {
            printf("Acceso denegado\n");
        }
    } while (1);
    
}