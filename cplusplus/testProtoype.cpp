
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Persona{

  private:

  public:
    string nombre;
    Persona(){};
    Persona(string nombre){
      this->nombre=nombre;
    }

    void getnombre(){
      cout<<"este es mi nombre ahora"<<this->nombre;
    }
    void setnom(string nombre){

      this->nombre=nombre;
    }
    string getnom(){
      return this->nombre;
    }

};




int main(){
  Persona obj("angel2");
 cout<<"este es el nombre del objeto 1"<<endl;
 cout<<obj.getnom();

cout<<endl;

  Persona obj2("");
//El constructor de copia por defecto (generado por el compilador) es invocado cuando se quiere
//inicializar un objeto a partir de otro. Por ejemplo:

//En las clases que poseen punteros o arreglos como campos miembro, el constructor de copia por defecto
//no funcionan como se espera ,pues los punteros se copian y los punteros del nuevo
//objeto quedan apuntando a los miembris  del primero
//Por que se debe esto? buscar mas imformacion ,en el nuevo objet o no es posible modificaion ?
copia por defecto no funciona como se espera, pues los punteros se copian y los punteros del nuevo

  obj2=obj;
  cout<<"este es el nombre del objeto 2 "<<endl;
  cout<<obj2.getnom();

cout<<endl;
  obj2.setnom("Ronal");//cambiando valor al objeto 2
  cout<<"El  nombre del objeto 1 ahora es  "<<endl;
  cout<<obj.getnom();
cout<<endl;


  // cout<<"este es el nombre"<<obj.nombre;








}
