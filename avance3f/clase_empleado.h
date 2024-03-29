/*  
    CLASE EMPLEADO
    Andrea Piñeiro A01705681
    (Base de datos para un gimnasio)

    En este archivo cree la segunda clase de empleados. Que
    sería principalmente para los entrenadores del gimnasio.
    Atributos: Nombre, Edad, Especialidad (clase/s que imparte),
    si tiene certificados, y las Horas por semana.
    Métodos: incluí getters y setters para los atributos.
    Otro métodos es el de aumentar la edad, y calcula
    cuánto se le debe pagar al entrenador.
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
           por ejemplo, las especialidades (si se agrega alguna),
           si tiene certificados, y las horas por semana.*/ 
    	void set_horasxsem(int nuevas_horas_x_sem);
      void set_sueldoxshora(float nuevo_sueldo);

    	/* La función aumentar edad calcula la edad del entrenador 
           apartir de la edad inicial y el tiempo transcurrido 
           desde que ingresó al gimnasio. 
           La función pago establece cuánto se le debe pagar
           al entrenador. */
    	int aumentar_edad(int tiempo);
//    	int pago();
      float pago_mensual();

};

//Constructor prestablecido
Empleado::Empleado(){
	nombre= "";
	edad=0;
	horas_x_sem=0;
  sueldo_x_hora=0;
}

//Constructos que recibe los datos desde el main
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

//Para especialidad, lo que hace es que agrega nuevas 
//especialidades que vaya adquiriendo el entrenador.

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

float Empleado::pago_mensual(){
    float pago_mensual;
    pago_mensual=horas_x_sem*4*sueldo_x_hora;
    return pago_mensual;
}



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

Entrenador::Entrenador():Empleado(){
  especialidad= "";
  certificados= false;
}


Entrenador::Entrenador(string n, int e, int horas, string esp, bool cer): Empleado(n, e, horas, 100){
  especialidad= esp;
  certificados=cer;
}

string Entrenador::get_especialidad(){
  return especialidad;
}

bool Entrenador::get_certificado(){
  return certificados;
}

void Entrenador::set_especialidad(string nueva_especialidad){
  especialidad= especialidad+" , "+nueva_especialidad;
}

void Entrenador::set_certificado(bool nuevo_certificado){
  certificados=nuevo_certificado;
}

string Entrenador::cadena(){
  stringstream aux;
  aux << "Su nombre es " << nombre << " su salario mensual es " << pago_mensual() << " su especialidad es " << especialidad << "\n";
  return aux.str();
}



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

Administrativo::Administrativo():Empleado(){
  labor= "";
}

Administrativo::Administrativo(string n, int e, int horas, string lab): Empleado(n, e, horas, 40){
    labor=lab;
}

string Administrativo::get_labor(){
  return labor;
}

void Administrativo::set_labor(string nueva_labor){
  labor= nueva_labor;
}

string Administrativo::cadena(){
  stringstream aux;
  aux << "Su nombre es " << nombre << " su salario mensual " << pago_mensual() << " su labor es " << labor << "\n";
  return aux.str();
}

#endif
