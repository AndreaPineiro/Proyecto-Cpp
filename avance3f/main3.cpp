/*  
    MAIN
    Andrea Piñeiro A01705681
    (Base de datos para un gimnasio)

    Este es el archivo .cpp, que contiene el main.
    También se añaden la clase gimnasio, que a su vez contiene las 
    otras clases
*/

#include <iostream>


#include "gimnasio.h"

//Esta función solo crea las opciones que se desplegaran en la 
//pantalla para que el usuario elija. 
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

	//Aquí se especifica el tipo de dato para la parte en la
	//que se crean objetos.
	int opcion=0, n_edad=0, n_horas=0, n_veces=0;
	string n_nombre="", n_especialidad="", n_labor="", n_tipo="";
	char n_genero= 'f';
	float n_peso=0, n_altura=0, n_costo;
	bool n_pago=false, n_certificados=false;
	long n_telefono=0;

	while (opcion <16 && opcion >-1){

		opciones();

		cout << "\nElije la opción que prefieras: ";
		cin >> opcion;

		switch(opcion){

			//La opción 1 muestra los objetos de la lista clientes
			case 1:
				gimnasio.muestra_clientes();
			break;

			//La opción 2 muestra los objetos de la lista servicios
			case 2:
				gimnasio.muestra_servicios();
			break;

			//La opción 3 muestra los objetos de la lista entrenadores
			case 3:
				gimnasio.muestra_entrenadores();
			break;

			//La opción 4 muestra los objetos de la lista administrativos
			case 4:
				gimnasio.muestra_administrativos();
			break;

			//La opción 5 muestra el pago total de todos los servicios
			case 5:
				cout << "Gasto mensual en servicios\t" << gimnasio.pago_servicios() <<"\n\n";
			break;

			//La opción 6 muestra el pago total de la nómina de los entrenadores
			case 6:
				cout << "Nómina a entrenadores\t" << gimnasio.pago_entrenadores() <<"\n\n";
			break;

			//La opción 7 muestra el pago total de la nómina de los administrativos
			case 7:
				cout << "Nómina a administradores\t" << gimnasio.pago_administrativos() <<"\n\n";
			break;

			//La opción 8 muestra el gasto total mensual del gimnasio
			case 8:
				cout << "Gastos mensuales totales\t" << gimnasio.egreso_total() <<"\n\n";
			break;

			//La opción 9 muestra el ingreso total, del pago de los clientes
			case 9:
				cout << "Ingreso mensual:\t" << gimnasio.ingreso_clientes() << "\n\n";
			break;

			//La opción 10 muestra la lista de clientes que tienen deuda.
			case 10:
				gimnasio.clientes_morosos();
			break;

			//La opción 11 muestra la ganancia mensual del gimnasio.
			case 11:
				cout << "Ganancia mensual:\t" << gimnasio.ganancia() << "\n\n";
			break;

			//La opción 12 pide los datos al usuario para crear un objeto 
			//de la clase cliente
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

			//La opción 13 pide los datos al usuario para crear un objeto 
			//de la clase entrenador
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

			//La opción 14 pide los datos al usuario para crear un objeto 
			//de la clase admnistrativo
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

			//La opción 15 pide los datos al usuario para crear un objeto 
			//de la clase servicio
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