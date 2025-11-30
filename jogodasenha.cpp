#include <iostream>
#include <random>
#include <string>
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

//validar se tem 4 digitos e se são de 1-6//
//essa funcao tem que ser bool
bool validarPalpite(int palpite) {
    
    string digitos = to_string(palpite);
    
    int d1, d2, d3, d4;
     d1 = palpite/1000;
     d2 = palpite%1000/100;
     d3 = palpite%100/10; 
     d4 = palpite%10;

    if (digitos.length() != 4) { //4 algarismos//
        cout << "Senha invalida (deve ter somente 4 digitos)\n";
        return false;
    }
    
    if (d1 < 1 || d1 > 6 || d2 < 1 || d2 > 6 || d3 < 1 || d3 > 6 || d4 < 1 || d4 > 6) { //verifica se esta no intervalo 1-6//
        cout << "Valor invalido. Digite algarismos do intervalo 1-6\n";
        return false;
    }
    return true;
}


//fazer funcao para verificar tentativas//
bool comparaSenhaPalpite(int senha, int palpite){
    int c = 0;
    int s1 = senha/1000;
    int s2 = senha%1000/100;
    int s3 = senha%100/10;
    int s4 = senha%10;
    
    int p1 = palpite/1000;
    int p2 = palpite%1000/100;
    int p3 = palpite%100/10;
    int p4 = palpite%10;
    
    if(p1 == s1){
        cout << "o";
        c++;
    } else {
        if(p1 == s2 || p1 == s3 || p1 == s4){
        cout << "x";
        } else {
        cout << "_"; 
        }
    }
    
    if(p2 == s2){
        cout << "o";
        c++;
    } else {
        if(p2 == s1 || p2 == s3 || p2 == s4){
        cout << "x";
        } else {
        cout << "_"; 
        }
    }
    
    if(p3 == s3){
        cout << "o";
        c++;
    } else {
        if(p3 == s1 || p3 == s2 || p3 == s4){
        cout << "x";
        } else {
        cout << "_"; 
        }
    }
    
    if(p4 == s4){
        cout << "o \n";
        c++;
    } else {
        if(p4 == s1 || p4 == s2 || p4 == s2){
        cout << "x \n";
        } else {
        cout << "_ \n"; 
        }
    }

    if (c == 4){
        return true;
    }else{
        return false;
    }
}

int main (){
  //armazenar senha//
    int senha = criarSenha();

    int palpite;

    bool resultado = false;
    bool validacao = false;

  cout << "JOGO DA SENHA" << endl;
  cout << "\nSeja bem vindo!";
  cout << "\nVoce tem 10 tentativas para acertar a senha de 4 digitos" << endl;

  for(int c = 0; c < 10; c++){//garantir as 10 tentativas
   cout << "Digite o palpite: \n";
   cin >> palpite;

   //4 dígitos e 1-6//
   validacao = validarPalpite(palpite); 

    if(validacao == true){
      //chamar funcao verificar tentativas//
      resultado = comparaSenhaPalpite(senha, palpite);
      if(resultado == true){
          cout << "Parabens, voce ganhou!!";
          c = 10;
       }
       if (c == 9){
           cout << "Você perdeu.";
       }
    } else {
      c = c - 1; // isso aqui seria para caso se digitar errado nao contar tentativa, nao sei se conta ou nao
    }
  }

  return 0;
  
}