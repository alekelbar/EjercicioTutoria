#pragma once
#include <iostream>
using namespace std;

class Cliente {
public:
	int cedula;
	string nombreCompleto;
	double ingresoNeto;
	string tipoSeguro;
	string numeroTelefono;
	string correoElectronico;
	double saldoTarifa;
	Cliente* siguiente;

	Cliente(int c, string nombre, double ingreso, string tipo, string telefono, string correo, double saldo)
		: cedula(c), nombreCompleto(nombre), ingresoNeto(ingreso), tipoSeguro(tipo),
		numeroTelefono(telefono), correoElectronico(correo), saldoTarifa(saldo), siguiente(nullptr) {}
};