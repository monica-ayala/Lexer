#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
string s="1234567890";
string a="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
string u="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890_";
void lexerAritmetico(string archivo) {

  cout<<"Token                                  |Type"<<endl<<
"--------------------------------------------------------------------------------"<<endl;
  
  for(std::string::size_type i = 0; i < archivo.size();i++){

//OPERADORES
  // SUMA
    if(archivo[i]== '+'){
      cout << archivo[i] << string(38, ' ') << "|SUMA" <<endl<<"--------------------------------------------------------------------------------"<<endl;   
    }
  // RESTA
    if(archivo[i]== '-'){
      cout << archivo[i] << string(38, ' ') << "|SUBSTRACTION" <<endl<<"--------------------------------------------------------------------------------"<<endl;   
    }
  // MULTIPLICACIÓN
    if(archivo[i]== '*'){
      cout << archivo[i] << string(38, ' ') << "|MULTIPLICATION" <<endl<<"--------------------------------------------------------------------------------"<<endl;    
    }
  // DIVISIÓN
    if(archivo[i]== '/'){
      string aux;
      if(archivo[i+1]=='/'){
        aux = aux + archivo[i]+archivo[i+1];
        i++;
        while(archivo[i+1] != '\n'){
          aux = aux + archivo[i+1];
          i++;
        }
        i++;
        //Si se quiere mostrar el comentario como token, usar sig codigo
          // int len = 39 - aux.length();
          // if(len >= 0){
          // cout << aux << string(len, ' ') << "|COMMENT" <<endl<<"--------------------------------------------------------------------------------"<<endl;
          // } else { cout<<aux<< " |COMMENT"<<endl<<"--------------------------------------------------------------------------------"<<endl;} 
      }
      else{
         cout << archivo[i] << string(38, ' ') << "|DIVISION" <<endl<<"--------------------------------------------------------------------------------"<<endl;      
      }
     
    }
  // POTENCIA
    if(archivo[i]== '^'){
      cout << archivo[i] << string(38, ' ') << "|POWER" <<endl<<"--------------------------------------------------------------------------------"<<endl;      
    }
  // ASIGNACIÓN 
    if(archivo[i]== '='){
      cout << archivo[i] << string(38, ' ') << "|ASSIGNMENT" <<endl<<"--------------------------------------------------------------------------------"<<endl;    
    }

//PARÉNTESIS
  // QUE ABREN
    if(archivo[i]== '('){
      cout << archivo[i] << string(38, ' ') << "|LEFT PARENTHESIS" <<endl<<"--------------------------------------------------------------------------------"<<endl;     
    }
  // QUE CIERRAN
    if(archivo[i]== ')'){
      cout << archivo[i] << string(38, ' ') << "|RIGHT PARENTHESIS" <<endl<<"--------------------------------------------------------------------------------"<<endl;    
    }
    
//VARIABLE
  if(a.find(archivo[i])<a.length()){
    string aux;
    aux = aux + archivo[i];
    while(u.find(archivo[i+1])<u.length()){
      aux = aux + archivo[i+1];
      i++;
    }
    int len = 39 - aux.length();
    if(len >= 0){
    cout << aux << string(len, ' ') << "|VARIABLE" <<endl<<"--------------------------------------------------------------------------------"<<endl;
    } else { cout<<aux<< " |VARIABLE"<<endl<<"--------------------------------------------------------------------------------"<<endl;} 
  }
    
//NÚMERO
    
  //ENTERO
    //inicia con digito o con -
    if(s.find(archivo[i])<s.length() || (archivo[i]=='-' && (s.find(archivo[i+1])<s.length()))){
      string aux; aux += archivo[i];
      while(s.find(archivo[i+1])<s.length()){
        aux = aux + archivo[i+1];
        i++;}
      
  //REAL 
    //puede tener un punto 
      if(archivo[i+1]=='.' && (s.find(archivo[i+2])<s.length()))      {
        aux = aux + archivo[i+1];
        i++;
        while(s.find(archivo[i+1])<s.length()){
          aux = aux + archivo[i+1];
          i++;
        }
    //puede tener un exponencial
        if((archivo[i+1]=='e' || archivo[i+1]== 'E') && ( (s.find(archivo[i+2])<s.length()) || (archivo[i+2] == '-') )){
          aux = aux + archivo[i+1];
          i++;
          if(archivo[i+1] == '-'){
            aux = aux + archivo[i+1];
            i++;
          }
          while(s.find(archivo[i+1])<s.length()){
            aux = aux + archivo[i+1];
            i++;
          }
        }
        int len = 39 - aux.length();
        if(len >= 0){
    cout << aux << string(len, ' ') << "|REAL" <<endl<<"--------------------------------------------------------------------------------"<<endl;
    } else { cout<<aux<< " |REAL"<<endl<<"--------------------------------------------------------------------------------"<<endl;} //END STATE
      }
      else{
        int len = 39 - aux.length();
        if(len >= 0){
    cout << aux << string(len, ' ') << "|INTERGER" <<endl<<"--------------------------------------------------------------------------------"<<endl;
    } else { cout<<aux<< " |INTERGER"<<endl<<"--------------------------------------------------------------------------------"<<endl;}
      }
    }
  }
}


string readFileToVector(const std::string& filename)
{
    std::ifstream source;
    source.open(filename);
    std::string line, str;
    while (std::getline(source, line))
    {
        str = str + line +"\n";
    }
  return str;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "usage: " << argv[0] << " pathname\n";
    return -1;
  }
  cout<<argv[1]<<endl;
  string filename(argv[1]);
  lexerAritmetico(readFileToVector(filename));

  return 0;
}

