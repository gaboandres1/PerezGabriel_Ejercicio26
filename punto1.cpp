#include <iostream>

int factorial(int);
void calcularFactorialPosicion(int *punteroArreglo, int);

int main(){

    std::cout << "Escriba un número entero positivo." << std::endl;
    int n;
    std::cin >> n;
    
    int* arreglo = NULL;
    arreglo = new int[n];
    

    return 0;
}

void calcularFactorialPosicion(int *punteroArreglo, int dimension){
    for(int i=0; i<dimension;i++){
        *(punteroArreglo+i) = factorial(i);
    }
}



/*
Calcula el factorial de un número n. Función sacada de cplusplus.com.
*/
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}