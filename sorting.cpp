#include <string>
#include <vector>
#include <fstream>
#include <iostream>


#include "sorting.h"


using namespace std;

/*
 * O radix sort funciona a partir da repetição de K vezes da agenda de um segundo algoritmo de ordenação, o counting sort, portanto, 
 * para entender o radix precisamos entender o counting sort primeiramente.
 * Trazendo a metáfora dos baldes, o counting sort consiste em pegar o indice de um elemento com somente um indice e colocar no "balde" em 
 * que ele é representado, por exemplo, se temos o array "2, 4, 3, 4, 5" colocamos, respectivamente o 2 no balde 2, o 4 no balde 4, 3 no 
 * balde 3 e por ai vai, depois de fazer isso, teremos cada número em seu balde, logo, devolvendo-os na mesma posição dos baldes, estarão
 * devidamente ordenados! 
 * Essa analogia pode ser feita também com letras do alfabeto, se considerarmos cada balde como sendo igualmente
 * ordenado, só que dessa vez do A até o Z em vez do 2 até o 5 como tínhamos previamente, a chave é pensar na quantidade que a quantidade
 * baldes é igual a quantidade de possibilidades que temos!  
 * Mas, e quando temos uma quantidade de termos maior que somente 1? quando temos um conjunto de números de 1 a 100, ou quando temos uma
 * palavra, quiçá uma frase, nessas horas precisamos do radix sort.
*/

void countingSort(vector<string> &input, int key) // Declaração da função que executará o countingSort
{ // a chave que a função counting sort irá receber é a chave correspondente ao algarismo a ser ordenado no dado ciclo, e o vector de input a lista a ser ordenada

  string output[input.size()]; // Vetor de output será um vetor auxiliar para quem passaremos os valores ordenados primeiro para depois passar ao vetor original       
  int counter[91] = { 0 };    // Agora temos nossos baldes! Serão 91 posições pois, como estamos tratando de tabela ascii e nosso "range" de possibilidades vai até o Z maiúsculo, posição 90, temos 90 baldes! 
    
    for (unsigned int i = 0; i < input.size(); i++){   
        counter[(int)(unsigned char)input[i][key]]++; // Aqui, contamos quantos elementos temos e distribuimos eles nos seus devidos baldes!
                                                      // observação de código: (int)(unsigned char) serve para transformar o valor do caracter em inteiro, para assim identificar em que posição adicionar o contador
    }

    for (unsigned int i = 1; i <91; i++){
        counter[i] += counter[i - 1];                 // Aqui, utilizamos do Prefix Sum, que nada mais é do que a soma do termo atual com o anterior, assim podemos ter na lista counter como devolver a posição do termo para a lista de output
    }

    for (int i = input.size() - 1; i >= 0; i--){
        output[counter[(int)(unsigned char)input[i][key]] - 1] = input[i]; // Primeiro, ele pega a posição do termo no counter, então digamos que seja Z será output[counter[90]-1] e digamos que no counter, com o prefix sum o valor da posição 90 seja 8, então diminuimos 1 dessa expressão, pois enquanto arrays trabalham com o zero, nossa notação pro counter não, precisamos então corrigir isso
        counter[(int)(unsigned char)input[i][key]]--; // diminui-se 1 do counter para corrigir o dimensionamento
    }

    for (unsigned int i = 0; i < input.size(); i++){
        input[i] = output[i];     // passa tudo da lista auxiliar para a principal!
    }

}

void radixSort(vector<string> &vect)//  Aqui temos o radix que organizará a agenda do counting sort
{
  for (unsigned int index = 6; index > 0; index--){// Repetirá 7 vezes, começando da ultima posição do termo de cada elemento (LSB) até a primeira (MSB)
        countingSort(vect, index - 1);
    }
}

void getFileArray(std::string fileName, vector<std::string> &pivList)
{  
  /* 
  *  Passando o vector por referência para poder alterá-lo diretamente e passando o nome do arquivo
  */
  string line;                      // String para guardar cada valor de cada linha do arquivo
  ifstream pivFile (fileName);      // Fetch do arquivo
  
  if (pivFile.is_open())            // Check para ver se ele foi de fato aberto
  {
    while ( getline (pivFile,line) )// Varredura das linhas
      pivList.push_back(line);      // Colocando cada valor de placa dentro do vector
    pivFile.close();                // Garantia de que o arquivo será fechado
  }
  else                              // Caso a função não consiga abrir o arquivo, exibir mensagem de erro
    cout<<
          "Arquivo não abriu, favor tente novamente"
                                                    <<endl;
}                                   // Pega valores do arquivo database com todas as placas