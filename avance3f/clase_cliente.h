/*  
    CLASE CLIENTE
    Andrea Piñeiro A01705681
    (Base de datos para un gimnasio)

    En este archivo cree la primer clase de clientes.
    Atributos: Nombre, Género, Edad, Peso, Altura y si
    esta inscrito o no.
    Métodos: incluí getters y setters para los atributos.
    Pero otros métodos son, aumenta la edad, y calcula
    si el usuario tiene deuda o no. 
*/
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Cliente{
  //En la parte privada incluí todos los atributos.
  private:
    string nombre;
    int id;
    char genero;
    int edad;
    float peso;
    double altura;
    bool pago;
    
  public:
    Cliente();
    Cliente(string n,int i, char gen, int e, float p, double a, bool pag);
  
    /* Cree getters para cada uno de los atributos, ya que 
       son importantes para saber los cambios que hay en cada
       uno de los clientes. */
    string get_nombre() const;
    int get_id() const;
    char get_genero() const;
    int get_edad();
    float get_peso();
    double get_altura();
    bool get_pago();

    /* Cree setters para los valores que pueden ser modificados
       por ejemplo, el peso, la altura o si deciden no inscriberse.
       Estos valores pueden cambiar, a diferencia del nombre 
       género que se mantienen iguales.*/ 
    void set_peso(float nuevo_peso);
    void set_altura(double nueva_altura);
    void set_pago(bool nuevo_pago);

    /* La función aumentar edad calcula la edad del usuario 
       apartir de la edad inicial y el tiempo transcurrido 
       desde que el usuario entró al gimnasio. 
       Y la función deuda establece si el cliente debe pagos */
    int aumentar_edad(int tiempo);
    virtual float deuda();
    virtual float pago_cant();

    string cadena();
    
};

//Constructor prestablecido
Cliente::Cliente(){
  nombre= "";
  id=0;
  genero= ' ';
  edad=0;
  peso=0;
  altura=0;
  pago=false;
}

//Constructos que recibe los datos desde el main
Cliente::Cliente(string n,int i,char gen, int e, float p, double a, bool pag){
  nombre=n;
  id=i;
  genero=gen;
  edad=e;
  peso=p;
  altura=a;
  pago=pag;
}

//En esta parte del programa se crean todos los getters

string Cliente::get_nombre()const{
  return nombre;
}

int Cliente::get_id()const {
  return id;
}

char Cliente::get_genero()const{
  return genero;
}

int Cliente::get_edad(){
  return edad;
}

float Cliente::get_peso(){
  return peso;
}

double Cliente::get_altura(){
  return altura;
}

bool Cliente::get_pago(){
  return pago;
}

//Aquí se crean los setters, para los valores que 
//necesitarían ser modificados.

void Cliente::set_peso(float nuevo_peso){
  peso=nuevo_peso;
}

void Cliente::set_altura(double nueva_altura){
  altura=nueva_altura;
}

void Cliente::set_pago(bool nuevo_pago){
  pago=nuevo_pago;
}

//Esta función aumenta la edad del usuario, apartir del tiempo.
int Cliente::aumentar_edad(int tiempo){
  edad=edad+tiempo;
  return edad;
}

//Esta función indica si el usuario debe la mensualidad del
//mes dependiendo si ya hizo el pago o no. 
float Cliente::pago_cant(){
  float pago_cant;
  if (pago==false){
    pago_cant=0;
  } else {
    pago_cant=800;
  }
  return pago_cant;
}

float Cliente::deuda(){
  float deuda;
  deuda=0;
  if (pago==false){
    deuda=deuda+850.0;
  } else {
    deuda=deuda;
  }
  return deuda;
}

string Cliente::cadena(){
  stringstream aux;
  aux << "Su nombre es " << nombre << ", el id es " << id << "\n";
  return aux.str();
}

#endif