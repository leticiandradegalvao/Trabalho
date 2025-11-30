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
void quebraSenha (int palpite){
   int a = palpite/1000;
   int b = palpite%1000/100;
   int c = palpite%100/10;
   int d = palpite%10;
}

//validar se tem 4 digitos e se são de 1-6//
void validarPalpite (string palpite) {

  if (palpite.length() != 4) { //4 algarismos//
    cout << "Senha invalida (deve ter somente 4 digitos)\n";
    return;
  }
  for (int i = 0; i < 4; i++) {
    string digito = palpite.substr(i, 1); //separar digitos na string//

    if (digito < "0" || digito > "9") {
      cout << "Valor invalido (deve ter somente numeros)\n"; //se o palpite tiver letras ou outros caracteres//
      return;
    }

    if (digito < "1" || digito > "6") { //validar 1-6//
      cout << "O algarismo " << i + 1 << " esta invalido, digite outro valor.\n";
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

  for(int c = 0; c < 10; c++){//garantir as 10 tentativas
   cout << "Digite a senha: ";
   cin >> palpite;

   //4 dígitos e 1-6//
   validarPalpite(palpite); 
  
   quebraSenha(palpite);
   //chamar funcao verificar tentativas//
  }

  return 0;
  
}