#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

string getFileArray(string fileName, (vector<string> pivList){
  string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    int i = 0;
    string teste="test";
    while ( getline (myfile,line) )
    {
      pivList.push_back(line);
      cout << line << " " << i++ << '\n';
    }
    myfile.close();
    return pivList;
  }
  else
  {
    cout<<
          "Arquivo não abriu"
                             <<endl;
    return NULL;
  }
}//pega valores do arquivo database com todas as placas
int main(){
  string myFile = "database.txt";
  vector<string> pivList = getFileArray(myFile, (vector<string>) pivList);


  /*
   * Aplicação do radixSort!!
   */
  return 0;
}