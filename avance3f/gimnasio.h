#ifndef GIMNASIO_H_
#define GIMNASIO_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "clase_cliente.h"
#include "clase_empleado.h"
#include "clase_servicios.h"

const int MAX=100;

class Gimnasio{
	private:
		Cliente clien[MAX];
		Servicios serv[MAX];
		Entrenador entre[MAX];
		Administrativo admin[MAX];
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

Gimnasio::Gimnasio(){

	iclien=0;
	iserv=0;
	ientre=0;
	iadmin=0;
}

void Gimnasio::muestra_clientes(){
	cout << "CLIENTES:\n";
	for(int i=0; i<iclien;i++){
		cout << "\t\t" << clien[i].cadena();
	}
	cout << "\n\n";
}

void Gimnasio::muestra_servicios(){
	cout << "SERVICIOS:\n";
	for(int i=0; i<iserv;i++){
		cout << "\t\t" << serv[i].cadena();
	}
	cout << "\n\n";
}

void Gimnasio::muestra_entrenadores(){
	cout << "ENTRENADORES:\n";
	for (int i=0; i<ientre;i++){
		cout << "\t\t" << entre[i].cadena();
	}
	cout << "\n\n";
}

void Gimnasio::muestra_administrativos(){
	for(int i=0; i<iadmin;i++){
		cout << admin[i].cadena();
	}
}

float Gimnasio::pago_servicios(){
	int total_serv=0;
	for (int i=0; i<iserv;i++){
		total_serv=total_serv+ serv[i].gasto_total();
	}
	return total_serv;
}

float Gimnasio::pago_entrenadores(){
	int total_entre=0;
	for (int i=0; i<ientre;i++){
		total_entre=total_entre+ entre[i].pago_mensual();
	}
	return total_entre;
}

float Gimnasio::pago_administrativos(){
	int total_admin=0;
	for(int i=0;i<iadmin;i++){
		total_admin=total_admin+ admin[i].pago_mensual();
	}
	return total_admin;
}

float Gimnasio::egreso_total(){
	float egreso;
	egreso= pago_administrativos() + pago_entrenadores() + pago_servicios();
	return egreso;
}

float Gimnasio::ingreso_clientes(){
	int total_clien=0;
	for(int i=0; i<iclien;i++){
		total_clien=total_clien + clien[i].pago_cant();
	}
	return total_clien;
	
}

void Gimnasio::clientes_morosos(){
	cout << "DEUDORES:\n";
	for (int i=0;i<iclien;i++){
		if (clien[i].deuda()!=0){
			cout << "\t\t" << clien[i].cadena() << "\t\t debe:" << clien[i].deuda();
		}
	}
	cout << "\n";
}

float Gimnasio::ganancia(){
	float ganancia;
	ganancia = ingreso_clientes() - egreso_total();
	return ganancia;
}

void Gimnasio::agrega_cliente(string nombre,char genero, int edad, float peso, double altura, bool pago){
	Cliente aux(nombre, iclien+1, genero, edad, peso, altura, pago);
	clien[iclien]= aux;
	iclien += 1;
}

void Gimnasio::Gimnasio::agrega_entrenador(string nombre, int edad, int horas_x_sem, string especialidad, bool certificados){
	Entrenador aux(nombre, edad, horas_x_sem,  especialidad,  certificados);
	entre[ientre]=aux;
	ientre +=1;
}

void Gimnasio::agrega_administrativo(string nombre, int edad, int horas_x_sem, string labor){
	Administrativo aux( nombre,  edad,  horas_x_sem,  labor);
	admin[iadmin]=aux;
	iadmin +=1;
}

void Gimnasio::agrega_servicio(string tipo, float costo, int veces, long tel){
	Servicios aux(tipo,costo, veces, tel);
	serv[iserv]=aux;
	iserv +=1;
}


#endif