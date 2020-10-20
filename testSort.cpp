#include <string>
#include <vector>
#include <fstream>
#include <iostream>


#include "sorting.h"


using namespace std;


void display(vector<string> vect){            // Função de display para título de demonstração do funcionamento do código
  for (unsigned int i = 0; i < vect.size(); i++)
        cout << vect.at(i) << " ";
  cout<<endl;
}

/*
   * Aplicação do algoritmo de ordenação escolhido (radixSort), de ordem O(n+k) em que k representa a quantidade de repetições da rotina, portanto, a quantidade de elementos em um termo desse vector é 7 (quantidade de letras e números nas placas), foi escolhido por ser um algoritmo de ordem linear e estável, ou seja, no melhor caso ele tem o comportamento O(n+k) tal qual no pior e no caso médio.
*/

int main(){
  string myFile = "database.txt";             // Nome do arquivo a ser lido
  vector<string> pivVect;                     // Vector de strings que guardará os dados de database


  getFileArray(myFile, pivVect);              // Função que pega os dados de database.txt (mais explicações sobre funcionamento em sorting.cpp)

  cout<< "Lista antes de estar ordenada: " <<endl;
  display(pivVect);
  cout<< "Lista depois de estar ordenada: " <<endl;
  radixSort(pivVect);                         // Algoritmo de ordenação (mais explicações sobre funcionamento em sorting.cpp)
  display(pivVect);
  return 0;
}