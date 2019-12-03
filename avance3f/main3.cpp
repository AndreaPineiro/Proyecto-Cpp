#include <iostream>

#include "clase_cliente.h"
#include "clase_empleado.h"
#include "clase_servicios.h"
#include "gimnasio.h"


void opciones(){
	cout <<"\t\t\t Bienvenido a la base de datos para el gimnasio \n";
	cout << "\t\t\t Esta son las siguientes opciones \n";
	cout << "1. Muestra clientes. \n";
	cout << "2. Muestra servicios. \n";
	cout << "3. Muestra entrenadores. \n";
	cout << "4. Muestra administrativos. \n";
	cout << "5. Pago total de servicios por mes. \n";
	cout << "6. Total de salario de entrenadores. \n";
	cout << "7. Total de salario de administrativos. \n";
	cout << "8. Egreso total. \n";
	cout << "9. Ingreso total. \n";
	cout << "10. Muestra clientes con deuda. \n";
	cout << "11. Ganancia total del mes. \n";
	cout << "12. Agregar cliente. \n";
	cout << "13. Agregar entrenador. \n";
	cout << "14. Agregar administrativo. \n";
	cout << "15. Agregar servicio. \n";
}

int main(int argc, char* arg[]){
	Gimnasio gimnasio;

	int opcion=0, n_edad=0, n_horas=0, n_veces=0;
	string n_nombre="", n_especialidad="", n_labor="", n_tipo="";
	char n_genero= 'f';
	float n_peso=0, n_altura=0, n_costo;
	bool n_pago=false, n_certificados=false;
	long n_telefono=0;

	while (opcion <16 && opcion >-1){

		opciones();

		cin >> opcion;

		switch(opcion){
			case 1:
				gimnasio.muestra_clientes();
			break;

			case 2:
				gimnasio.muestra_servicios();
			break;

			case 3:
				gimnasio.muestra_entrenadores();
			break;

			case 4:
				gimnasio.muestra_administrativos();
			break;

			case 5:
				cout << "Gasto mensual en servicios\t" << gimnasio.pago_servicios() <<"\n\n";
			break;

			case 6:
				cout << "Nómina a entrenadores\t" << gimnasio.pago_entrenadores() <<"\n\n";
			break;

			case 7:
				cout << "Nómina a administradores\t" << gimnasio.pago_administrativos() <<"\n\n";
			break;

			case 8:
				cout << "Gastos mensuales totales\t" << gimnasio.egreso_total() <<"\n\n";
			break;

			case 9:
				cout << "Ingreso mensual:\t" << gimnasio.ingreso_clientes() << "\n\n";
			break;

			case 10:
				gimnasio.clientes_morosos();
			break;

			case 11:
				cout << "Ganancia mensual:\t" << gimnasio.ganancia() << "\n\n";
			break;

			case 12:
				cout << "Nombre :";
				cin >> n_nombre;
				cout << "Género :";
				cin >> n_genero;
				cout << "Edad :";
				cin >> n_edad;
				cout << "Peso :";
				cin >> n_peso;
				cout << "Altura :";
				cin >> n_altura;
				cout << "¿Pagó? :";
				cin >> n_pago;
				gimnasio.agrega_cliente(n_nombre, n_genero, n_edad, n_peso, n_altura, n_pago);
			break;

			case 13:
				cout << "Nombre :" ;
				cin >> n_nombre;
				cout << "Edad :";
				cin >> n_edad;
				cout << "Horas por semana :";
				cin >> n_horas;
				cout << "Especialidad :" ;
				cin >> n_especialidad;
				cout << "¿Tiene certificados? :" ;
				cin >> n_certificados;
				gimnasio.agrega_entrenador(n_nombre, n_edad, n_horas, n_especialidad, n_certificados);
			break;

			case 14:
				cout << "Nombre :" ;
				cin >> n_nombre;
				cout << "Edad :";
				cin >> n_edad;
				cout << "Horas por semana :";
				cin >> n_horas;
				cout << "Labor :" ;
				cin >> n_labor;
				gimnasio.agrega_administrativo(n_nombre, n_edad, n_horas, n_labor);
			break;

			case 15:
				cout << "Tipo :" ;
				cin >> n_tipo;
				cout << "Costo :";
				cin >> n_costo;
				cout << "Veces por semana :";
				cin >> n_veces;
				cout << "Teléfono :" ;
				cin >> n_telefono;
				gimnasio.agrega_servicio(n_tipo, n_costo, n_veces, n_telefono);
			break;
		}
	}
}