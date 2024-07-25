#include <iostream>
#include <string>
#include "seguro.hpp"

using namespace std;

int main() {
    Seguro seguro;
    int opcion, cedula;
    string nombreCompleto, tipoSeguro, numeroTelefono, correoElectronico;
    double ingresoNeto;

    while (true) {
        cout << "\nMenu:\n1. Crear Cliente\n2. Consultar Cliente\n3. Actualizar Cliente\n4. Eliminar Cliente\n5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese cedula: ";
            cin >> cedula;
            cout << "Ingrese nombre completo: ";
            cin.ignore();
            getline(cin, nombreCompleto);
            cout << "Ingrese ingreso neto: ";
            cin >> ingresoNeto;
            cout << "Ingrese tipo de seguro (medico/veterinario/automovil): ";
            cin >> tipoSeguro;
            cout << "Ingrese numero de telefono: ";
            cin >> numeroTelefono;
            cout << "Ingrese correo electronico: ";
            cin >> correoElectronico;
            seguro.crearCliente(cedula, nombreCompleto, ingresoNeto, tipoSeguro, numeroTelefono, correoElectronico);
            break;

        case 2:
            cout << "Ingrese cedula del cliente a consultar: ";
            cin >> cedula;
            seguro.consultarCliente(cedula);
            break;

        case 3:
            cout << "Ingrese cedula del cliente a actualizar: ";
            cin >> cedula;
            cout << "Ingrese nombre completo: ";
            cin.ignore();
            getline(cin, nombreCompleto);
            cout << "Ingrese ingreso neto: ";
            cin >> ingresoNeto;
            cout << "Ingrese tipo de seguro (medico/veterinario/automovil): ";
            cin >> tipoSeguro;
            cout << "Ingrese numero de telefono: ";
            cin >> numeroTelefono;
            cout << "Ingrese correo electronico: ";
            cin >> correoElectronico;
            seguro.actualizarCliente(cedula, nombreCompleto, ingresoNeto, tipoSeguro, numeroTelefono, correoElectronico);
            break;

        case 4:
            cout << "Ingrese cedula del cliente a eliminar: ";
            cin >> cedula;
            seguro.eliminarCliente(cedula);
            break;

        case 5:
            return 0;

        default:
            cout << "Opcion invalida.\n";
            break;
        }
    }

    return 0;
	return EXIT_SUCCESS;
}