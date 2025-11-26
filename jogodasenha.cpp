#include <iostream>
#include <random>
using namespace std;

int main (){
    int inicializacao;

  cout << "JOGO DA SENHA" << endl;
  cout << "\nSeja bem vindo!";
  cout << "\nVoce tem 10 tentativas para acertar a senha de 4 digitos";
  cout << "\nDigite 0 para iniciar";

  cin >> inicializacao;
  
if (inicializacao == 0)
  cout << "Boa sorte!";
else
  cout << "Número inválido";


  return 0;
  
}