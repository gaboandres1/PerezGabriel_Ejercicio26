#include <fstream>
#include <iostream>
using namespace std;
 
void leerTxt(double *punteroArreglo, string filename);
void escribirTxt(double *punteroArreglo, string filename);
const int LINES = 20;

int main () {
    
  //Se lee el archivo valores_x.txt y se almacena su contenido en arreglo_x
  string filename;
  filename = "valores_x.txt";
  double arreglo_x[LINES];
  double *px = arreglo_x;
  leerTxt(px,filename);
    
  //Se lee el archivo valores_y.txt y se almacena su contenido en arreglo_y
  filename = "valores_y.txt";
  double arreglo_y[LINES];
  double *py = arreglo_y;
  leerTxt(py,filename);
    
  //Se crea un arreglo con nombre arreglo_final para guardar la multiplicación
  //de arreglo_x y arreglo_y
  double arreglo_final[LINES];
  for(int i=0; i<LINES; i++){
      arreglo_final[i] = arreglo_x[i] * arreglo_y[i];
  }
    
  //Se escribe en un archivo llamado multiplicacion.txt el contenido de arrego_final
  filename = "multiplicacion.txt";
  double *pf = arreglo_final;
  escribirTxt(pf, filename);
    
    
  //delete arreglos
  delete []arreglo_x;
  delete []arreglo_y;
  delete []arreglo_final;
  return 0;
}


/*
Lee un archivo de texto de nombre filename y escribe su contenido
en el arreglo cuya primer elemento tiene dirección punteroArreglo
*/
void leerTxt(double *punteroArreglo,string filename){
  ifstream infile; 
  string line;
  infile.open(filename); 
  
  getline(infile, line);
  int i = 0;
  while(infile){
    *(punteroArreglo+i) = atof(line.c_str());
    i++;
    getline(infile, line);
  }

  infile.close();
}


/*
Escribe el contenido de un arreglo cuya primera posición es
apuntada por punteroArreglo. El nombre del archivo será especificado 
por el parámetro filename.
*/
void escribirTxt(double *punteroArreglo, string filename){
  ofstream outfile;
  outfile.open(filename);

  for (int i=0; i < LINES; i++){
    outfile << *(punteroArreglo+i) << endl;
  }
  outfile.close(); 
}