/*  
    CLASE GIMNASIO
    Andrea Piñeiro A01705681
    (Base de datos para un gimnasio)

    En este archivo cree la clase de gimasio. Dentro de esta clase se 
    crean objetos de la clase de empleado, cliente y servicios,
    ya que son objetos que componen el gimnasio
    
*/

#ifndef GIMNASIO_H_
#define GIMNASIO_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "clase_cliente.h"
#include "clase_empleado.h"
#include "clase_servicios.h"


/* Los atributos de la clase Gimnasio es que contiene a los 
objetos de cliente, entrenador, administrativo y servicios; 
también cuenta con contadores que van a contabilizar el 
número de objetos ya creados de cada clase.
Y tiene muchas funciones esta clase, mostrar las otras clases,
agregar un objeto a las otras clases, así como mostrar la 
ganancia del gimnasio en el mes
*/
class Gimnasio{
	private:
		Cliente clien[100];
		Servicios serv[100];
		Entrenador entre[100];
		Administrativo admin[100];
		int iclien;
		int iserv;
		int ientre;
		int iadmin;

	public:
		Gimnasio();

		void muestra_clientes();
		void muestra_servicios();
		void muestra_entrenadores();
		void muestra_administrativos();
		float pago_servicios();
		float pago_entrenadores();
		float pago_administrativos();
		float egreso_total();
		float ingreso_clientes();
		void clientes_morosos();
		float ganancia();
		void agrega_cliente(string nombre,char genero, int edad, float peso, double altura, bool pago);
		void agrega_entrenador(string n, int e, int horas, string esp, bool cer);
		void agrega_administrativo(string n, int e, int horas, string lab);
		void agrega_servicio(string tipo, float costo, int veces, long tel);
};

//Constructor prestablecido
Gimnasio::Gimnasio(){

	iclien=0;
	iserv=0;
	ientre=0;
	iadmin=0;
}

//Esta función muestra a los clientes, imprime la cadena con
//nombre y número de cliente. Esto lo hace imprimiendo cada
//elemento dentro de la lista de clientes
void Gimnasio::muestra_clientes(){
	cout << "CLIENTES:\n";
	for(int i=0; i<iclien;i++){
		cout << "\t\t" << clien[i].cadena();
	}
	cout << "\n\n";
}

//Esta función muestra a los servicios, imprime la cadena con
//el servicio y el gasto mensual. Esto lo hace imprimiendo cada
//elemento dentro de la lista de servicios
void Gimnasio::muestra_servicios(){
	cout << "SERVICIOS:\n";
	for(int i=0; i<iserv;i++){
		cout << "\t\t" << serv[i].cadena();
	}
	cout << "\n\n";
}

//Esta función muestra a los entrenadores, imprime la cadena con
//nombre, salario y especialidad. Esto lo hace imprimiendo cada
//elemento dentro de la lista entrenadores
void Gimnasio::muestra_entrenadores(){
	cout << "ENTRENADORES:\n";
	for (int i=0; i<ientre;i++){
		cout << "\t\t" << entre[i].cadena();
	}
	cout << "\n\n";
}

//Esta función muestra a los administradores, imprime la cadena con
//nombre, salario y labor. Esto lo hace imprimiendo cada
//elemento dentro de la lista de administrativos.
void Gimnasio::muestra_administrativos(){
	for(int i=0; i<iadmin;i++){
		cout << admin[i].cadena();
	}
}

//Esta función calcula el total del pago de todos los servicios
//del gimnasio, esto lo hace mandando llamar la función gasto_total
//de la clase servicios, que calcula el costo del servicio al mes.
//En esta función, va sumando el gasto mensual de todos los objetos
//dentro de la lista de servicios.
float Gimnasio::pago_servicios(){
	int total_serv=0;
	for (int i=0; i<iserv;i++){
		total_serv=total_serv+ serv[i].gasto_total();
	}
	return total_serv;
}

//Esta función calcula el total del pago de nómina a los 
// entrenadores del gimnasio, esto lo hace mandando llamar la 
//función pago_mensual de la clase entrenadores, que calcula
//el pago mensual de cada entrenador.
//En esta función, va sumando el pago mensual de todos los objetos
//dentro de la lista de entrenadores.
float Gimnasio::pago_entrenadores(){
	int total_entre=0;
	for (int i=0; i<ientre;i++){
		total_entre=total_entre+ entre[i].pago_mensual();
	}
	return total_entre;
}

//Esta función calcula el total del pago de nómina a los 
// administrativos del gimnasio, esto lo hace mandando llamar la 
//función pago_mensual de la clase administrativos, que calcula
//el pago mensual de cada administrativo.
//En esta función, va sumando el pago mensual de todos los objetos
//dentro de la lista de administrativos.
float Gimnasio::pago_administrativos(){
	int total_admin=0;
	for(int i=0;i<iadmin;i++){
		total_admin=total_admin+ admin[i].pago_mensual();
	}
	return total_admin;
}

//Esta función calcula el gasto total mensual del gimnasio,
//sumando el pago de los servicios y el pago de nóminas.
float Gimnasio::egreso_total(){
	float egreso;
	egreso= pago_administrativos() + pago_entrenadores() + pago_servicios();
	return egreso;
}

//Esta función calcula el ingreso mensual del gimnasio, 
//esto a través del pago de las mensualidades de los clientes.
//Manda a llamar a la función pago_cant de la clase clientes,
//que calcula la cantidad que pago el cliente si realizó el pago
//o no. Para está función, va sumando el pago de todos los 
//objetos dentro de la clase clientes.
float Gimnasio::ingreso_clientes(){
	int total_clien=0;
	for(int i=0; i<iclien;i++){
		total_clien=total_clien + clien[i].pago_cant();
	}
	return total_clien;
	
}

//Esta función muestra a los clientes que tienen deuda, esto lo
//hace mandando llamando la función de deuda de la clase cliente
//si la deuda es diferente a 0, muestra el nombre y el número
//de cliente deudor, así como la cantidad que debe.
void Gimnasio::clientes_morosos(){
	cout << "DEUDORES:\n";
	for (int i=0;i<iclien;i++){
		if (clien[i].deuda()!=0){
			cout << "\t\t" << clien[i].cadena() << "\t\t debe:" << clien[i].deuda();
		}
	}
	cout << "\n";
}

//Esta función calcula la ganancia mensual del gimnasio,
//restando el total de gastos al ingreso mensual.
float Gimnasio::ganancia(){
	float ganancia;
	ganancia = ingreso_clientes() - egreso_total();
	return ganancia;
}

//Esta función crea objetos de la clase cliente, y los agrega
//en la lista clientes; se manda llamar el constructor para
//crear en está función al objeto directamente.
void Gimnasio::agrega_cliente(string nombre,char genero, int edad, float peso, double altura, bool pago){
	Cliente aux(nombre, iclien+1, genero, edad, peso, altura, pago);
	clien[iclien]= aux;
	iclien += 1;
}

//Esta función crea objetos de la clase entrenador, y los agrega
//en la lista entrenador; se manda llamar el constructor para
//crear en está función al objeto directamente.
void Gimnasio::Gimnasio::agrega_entrenador(string nombre, int edad, int horas_x_sem, string especialidad, bool certificados){
	Entrenador aux(nombre, edad, horas_x_sem,  especialidad,  certificados);
	entre[ientre]=aux;
	ientre +=1;
}

//Esta función crea objetos de la clase administrativo, y los agrega
//en la lista administrativos; se manda llamar el constructor para
//crear en está función al objeto directamente.
void Gimnasio::agrega_administrativo(string nombre, int edad, int horas_x_sem, string labor){
	Administrativo aux( nombre,  edad,  horas_x_sem,  labor);
	admin[iadmin]=aux;
	iadmin +=1;
}

//Esta función crea objetos de la clase servicio, y los agrega
//en la lista servicio; se manda llamar el constructor para
//crear en está función al objeto directamente.
void Gimnasio::agrega_servicio(string tipo, float costo, int veces, long tel){
	Servicios aux(tipo,costo, veces, tel);
	serv[iserv]=aux;
	iserv +=1;
}


#endif