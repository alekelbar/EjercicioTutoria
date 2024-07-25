#pragma once
#include <iostream>
#include "Cliente.hpp"

using namespace std;

class Seguro {
private:
	Cliente* cabeza;

	double calcularTarifa(const string& tipoSeguro) {
		if (tipoSeguro == "medico") return 50.0;
		if (tipoSeguro == "veterinario") return 25.0;
		if (tipoSeguro == "automovil") return 0.0; // Definir tarifa para seguro de automóvil
		return 0.0;
	}

public:
	Seguro() : cabeza(nullptr) {} // ¿Que otra forma hay de hacer esto?

	void crearCliente(int cedula, string nombreCompleto, double ingresoNeto, string tipoSeguro, string numeroTelefono, string correoElectronico) {
		double tarifa = calcularTarifa(tipoSeguro);

		Cliente* nuevoCliente = new Cliente(cedula, nombreCompleto, ingresoNeto, tipoSeguro, numeroTelefono, correoElectronico, tarifa);
		nuevoCliente->siguiente = cabeza;
		cabeza = nuevoCliente;
		cout << "Cliente creado exitosamente.\n";
	}

	void consultarCliente(int cedula) {
		Cliente* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cedula == cedula) {
				cout << "Cedula: " << actual->cedula << "\nNombre: " << actual->nombreCompleto
					<< "\nIngreso Neto: " << actual->ingresoNeto << "\nTipo de Seguro: " << actual->tipoSeguro
					<< "\nNumero de Telefono: " << actual->numeroTelefono << "\nCorreo Electronico: " << actual->correoElectronico
					<< "\nSaldo o Tarifa: " << actual->saldoTarifa << "\n";
				return;
			}
			actual = actual->siguiente;
		}
		cout << "Cliente no encontrado.\n";
	}

	void actualizarCliente(int cedula, string nombreCompleto, double ingresoNeto, string tipoSeguro, string numeroTelefono, string correoElectronico) {
		Cliente* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cedula == cedula) {
				actual->nombreCompleto = nombreCompleto;
				actual->ingresoNeto = ingresoNeto;
				actual->tipoSeguro = tipoSeguro;
				actual->numeroTelefono = numeroTelefono;
				actual->correoElectronico = correoElectronico;
				actual->saldoTarifa = calcularTarifa(tipoSeguro);
				cout << "Cliente actualizado exitosamente.\n";
				return;
			}
			actual = actual->siguiente;
		}
		cout << "Cliente no encontrado.\n";
	}

	void eliminarCliente(int cedula) {
		Cliente* actual = cabeza;
		Cliente* anterior = nullptr;
		while (actual != nullptr) {
			if (actual->cedula == cedula) {
				if (anterior == nullptr) {
					cabeza = actual->siguiente;
				}
				else {
					anterior->siguiente = actual->siguiente;
				}
				delete actual;
				cout << "Cliente eliminado exitosamente.\n";
				return;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		cout << "Cliente no encontrado.\n";
	}
};