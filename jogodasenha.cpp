#include <iostream>
#include <random>
using namespace std;

//função que cria a senha//
int criarSenha() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 6);
    int senha = 0;
    
    for(int i = 0; i < 4; i++) {
        int digito = dist(gen);
        senha = senha * 10 + digito; 
    }
    return senha;
}

//quebrar senha termo por termo//
//jogador digitou 1 a 6 e se tem 4 dígitos//
//fazer funcao para verificar tentativas//


int main (){
  //armazenar senha//
    int senha = criarSenha();
    int palpite; 

  cout << "JOGO DA SENHA" << endl;
  cout << "\nSeja bem vindo!";
  cout << "\nVoce tem 10 tentativas para acertar a senha de 4 digitos" << endl;
  cout << "Digite a senha: ";
  cin >> palpite;

  
  //chamar quebrar a senha//
  //jogador digitou 1 a 6 e se tem 4 dígitos//
  //chamar funcao verificar tentativas//

  return 0;
  
}