/*  
    CLASE EMPLEADO
    Andrea Piñeiro A01705681
    (Base de datos para un gimnasio)

    En este archivo cree la segunda clase de empleado. La cual
    es la clase padre de la que heredan entrenadores y administrativos.
    Los atributos que comparten ambas clases heredadas son: Nombre, 
    Edad, horas por semana y sueldo por hora. 
    Métodos: incluí getters y setters para los atributos.
    Otro métodos es el de aumentar la edad, y calcula
    el pago mensual del empleado.
*/

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Empleado{
	protected:
		//En la parte privada incluí todos los atributos.
		  string nombre;
    	int edad;
    	int horas_x_sem;
      float sueldo_x_hora;

    public:
    	Empleado();
    	Empleado(string n, int e, int horas, float s);


    	/* Cree getters para cada uno de los atributos, ya que 
         son importantes para que funcionen como base de datos. */
    	string get_nombre()const;
    	int get_edad() ;
    	int get_horasxsem();
      float get_sueldoxhora();

    	/* Cree setters para los valores que pueden ser modificados
         por ejemplo, las horas por semana y el sueldo por hora.*/ 
    	void set_horasxsem(int nuevas_horas_x_sem);
      void set_sueldoxshora(float nuevo_sueldo);

    	/* La función aumentar edad calcula la edad del entrenador 
         apartir de la edad inicial y el tiempo transcurrido 
         desde que ingresó al gimnasio. 
         La función pago establece cuánto se le debe pagar
         al entrenador. */
    	int aumentar_edad(int tiempo);
//    	 Esta función calcula el pago mensaul a los empleados.
      float pago_mensual();

};

//Constructor prestablecido
Empleado::Empleado(){
	nombre= "";
	edad=0;
	horas_x_sem=0;
  sueldo_x_hora=0;
}

//Constructor que recibe los datos desde el main
Empleado::Empleado(string n, int e, int horas, float s){
	nombre=n;
	edad=e;
	horas_x_sem=horas;
  sueldo_x_hora= s;
}

//En esta parte del programa se crean todos los getters
string Empleado::get_nombre()const{
	return nombre;
}

int Empleado::get_edad(){
	return edad;
}

int Empleado::get_horasxsem(){
	return horas_x_sem;
}

float Empleado::get_sueldoxhora(){
  return sueldo_x_hora;
}

//Aquí se crean los setters, para los datos que 
//podrían ser modificados después de crear el objeto.
void Empleado::set_horasxsem(int nuevas_horas_x_sem){
	horas_x_sem = nuevas_horas_x_sem;
}

void Empleado::set_sueldoxshora(float nuevo_sueldo){
  sueldo_x_hora = nuevo_sueldo;
}

// Esta función aumenta la edad del empleado, apartir del tiempo.
int Empleado::aumentar_edad(int tiempo){
  edad=edad+tiempo;
  return edad;
}

// Esta función calcula el pago mensual de los empleados.
float Empleado::pago_mensual(){
    float pago_mensual;
    pago_mensual=horas_x_sem*4*sueldo_x_hora;
    return pago_mensual;
}


/* Aquí se crea la clase Entrenador, que hereda de Empleado, 
esta tiene los mismos atributos que la anterior, pero también
tiene como atributos la especialidad y los certificados
*/
class Entrenador: public Empleado{
    private:
      string especialidad;
      bool certificados;

    public:
      Entrenador();
      Entrenador(string n, int e, int horas, string esp, bool cer);

      string get_especialidad();
      bool get_certificado();

      void set_especialidad(string nueva_especialidad);
      void set_certificado(bool nuevo_certificado);

      string cadena();
      
};

//Constructor prestablecido
Entrenador::Entrenador():Empleado(){
  especialidad= "";
  certificados= false;
}

//Constructor que recibe los datos desde el main
Entrenador::Entrenador(string n, int e, int horas, string esp, bool cer): Empleado(n, e, horas, 100){
  especialidad= esp;
  certificados=cer;
}

//En esta parte de la clase se crean todos los getters para 
//especialidad y certificado
string Entrenador::get_especialidad(){
  return especialidad;
}

bool Entrenador::get_certificado(){
  return certificados;
}

//Aquí se crean los setters, para los datos que 
//podrían ser modificados después de crear el objeto.
void Entrenador::set_especialidad(string nueva_especialidad){
  especialidad= especialidad+" , "+nueva_especialidad;
}

void Entrenador::set_certificado(bool nuevo_certificado){
  certificados=nuevo_certificado;
}

//Esta función crea una cadena que imprime el nombre, el salario
//y la especialidad del entrenador, que es lo que queremos imprimir. 
string Entrenador::cadena(){
  stringstream aux;
  aux << "Su nombre es " << nombre << " su salario mensual es " << pago_mensual() << " su especialidad es " << especialidad << "\n";
  return aux.str();
}

//Aquí se crea la clase Administrativo que hereda de empleado,
//el único atributo diferente es el de qué labor desempeña.
class Administrativo: public Empleado{
    private:
      string labor;

    public:
      Administrativo();
      Administrativo(string n, int e, int horas, string lab);

      string get_labor();

      void set_labor(string nueva_labor);
      string cadena();

};

//Constructor prestablecido
Administrativo::Administrativo():Empleado(){
  labor= "";
}

//Constructor que recibe los datos desde el main
Administrativo::Administrativo(string n, int e, int horas, string lab): Empleado(n, e, horas, 40){
    labor=lab;
}

//Aquí se crea el get de labor
string Administrativo::get_labor(){
  return labor;
}

//Aquí se crea el set de labor, para modificarlo
void Administrativo::set_labor(string nueva_labor){
  labor= nueva_labor;
}

//Esta función crea una cadena que imprime el nombre, el salario
//y la labor del administrativo. 
string Administrativo::cadena(){
  stringstream aux;
  aux << "Su nombre es " << nombre << " su salario mensual " << pago_mensual() << " su labor es " << labor << "\n";
  return aux.str();
}

#endif
