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


//validar se tem 4 digitos e se são de 1-6//
void validarPalpite (int palpite) {
string d4 = to_string(palpite);

  if (d4.length() != 4) { //4 algarismos//
    cout << "Senha invalida (deve ter somente 4 digitos)\n";
    return;
  }
  for (int i = 0; i < 4; i++) {
    string digito = d4.substr(i, 1); //separar digitos na string//

    if (digito < "0" || digito > "9") {
      cout << "Valor invalido (deve ter somente numeros)\n"; //se o palpite tiver letras ou outros caracteres//
      return;
    }
  }
  }


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

  //4 dígitos e 1-6//
  validarPalpite(palpite); 
  
  //chamar quebrar a senha//
  //chamar funcao verificar tentativas//

  return 0;
  
}