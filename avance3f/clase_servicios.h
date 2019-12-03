/*  
    CLASE SERVICIOS
    Andrea Piñeiro A01705681
    (Base de datos para un gimnasio)

    En este archivo cree la tercer clase de servicios. Que 
    serviría como una base de datos para todos los gastos 
    y servicios necesarios.
    Atributos: Tipo de servicio, Costo, Veces por mes y
    número de teléfono.
    Métodos: incluí getters y setters para los atributos.
    Y también incluí un método que calcula el gasto total
    por mes de cada servicio.
*/
#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Servicios{
	private:
		//En la parte privada incluí todos los atributos.
		string tipo;
		float costo;
		int veces_x_mes;
		int no_tel;
	public:
		Servicios();
		Servicios(string t, float c, int veces, long tel);

		/* Cree getters para cada uno de los atributos, para
		que se cree una base de datos. */
		string get_tipo()const ;
		float get_costo();
		int get_veces_x_mes();
		long get_no_tel();

		/* Cree setters para los valores que pueden ser modificados
           por ejemplo el costo, las veces por semana y 
           el número de teléfono. */
		void set_costo(float nuevo_costo);
		void set_veces_x_mes(int nuevas_veces);
		void set_no_tel(long nuevo_tel);

		// Este método calcula el gasto total de cada servicio 
		virtual int gasto_total();
		string cadena();
};

//Constructor prestablecido
Servicios::Servicios(){
	tipo="";
	costo=0;
	veces_x_mes=0;
	no_tel=0;
}

//Constructos que recibe los datos desde el main
Servicios::Servicios(string t, float c, int veces, long tel){
	tipo=t;
	costo=c;
	veces_x_mes=veces;
	no_tel=tel;
}

//En esta parte del programa se crean todos los getters

string Servicios::get_tipo()const{
	return tipo;
}

float Servicios::get_costo(){
	return costo;
}

int Servicios::get_veces_x_mes(){
	return veces_x_mes;
}

long Servicios::get_no_tel(){
	return no_tel;
}

//Aquí se crean los setters, para los datos que 
//podrían ser modificados después de crear el objeto.

void Servicios::set_costo(float nuevo_costo){
	costo=nuevo_costo;
}

void Servicios::set_veces_x_mes(int nuevas_veces){
	veces_x_mes=nuevas_veces;
}

void Servicios::set_no_tel(long nuevo_tel){
	no_tel=nuevo_tel;
}

/* Esta función calcula el gasto total del servicio, mandando
   llamar las funciones de get_costo y get_veces_x_meses, y
   multiplica las veces por el costo
 */
int Servicios::gasto_total(){
	float gasto_total;
	float precio;
	int veces;
	precio=get_costo();
	veces=get_veces_x_mes();
	gasto_total= precio*veces;
	return gasto_total;
}

string Servicios::cadena(){
	stringstream aux;
	aux << "El servicio es " << tipo << ", el gasto mensual es " << gasto_total() << "\n";
	return aux.str();
}


#endif