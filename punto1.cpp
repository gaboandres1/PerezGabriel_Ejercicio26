#include <iostream>

int factorial(int);
void calcularFactorialPosicion(int *punteroArreglo, int);
void imprimirArreglo(int *punteroArreglo, int dimension);

int main(){

    std::cout << "Escriba un número entero positivo." << std::endl;
    int n;
    std::cin >> n;//Se ingresa por consola la dimensión del arreglo.
    
    
    int* arreglo = NULL;
    arreglo = new int[n];
    calcularFactorialPosicion(arreglo,n);
    imprimirArreglo(arreglo,n);
    
    delete []arreglo;
    return 0;
}

/*
Rellena un arreglo con el factorial de las posiciones de sus elementos.
*/
void calcularFactorialPosicion(int *punteroArreglo, int dimension){
    for(int i=0;i<dimension;i++){
        *(punteroArreglo+i) = factorial(i);
    }
}
/*
Imprime en consola el arreglo con dirección punteroArreglo.
*/
void imprimirArreglo(int *punteroArreglo, int dimension){
    std::cout<<"El arreglo es [";
    for(int i=0;i<dimension-1;i++){
        std::cout<<*(punteroArreglo+i)<<", ";
    }
    std::cout<<*(punteroArreglo+dimension-1)<<"]"<<std::endl;
}

/*
Calcula el factorial de un número n. Función sacada de cplusplus.com.
*/
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}