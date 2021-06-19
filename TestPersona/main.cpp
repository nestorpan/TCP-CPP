#include <iostream>
#include <fstream>

#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"
#include "../Fecha/FechaException.h"
#include "../Persona/EmpleadoBuilder.h"


using namespace std;


int main(int argc, char* argv[])
{
	filebuf fbLog;
	fbLog.open("Logs.txt", ios::app);
	ostream logOS(&fbLog);
	
	PersonaBuilder pb;
	pb.setDni(1);
	pb.setApyn("Pepe Argento");
	pb.setEstadoCivil('C');
/*	
	try
	{
		pb.setFNac(Fecha(1, 3, 1993));
	}
	catch(FechaException& ex)
	{
		logOS << ex.getMensaje() << endl;
		return 1;
	}
*/	
/*
	try
	{
		Persona p = pb.build();
		
		cout << p << endl;
	}
	catch(PersonaException& ex)
	{
		logOS << ex.getMensaje() << endl;
		return 1;
	}
	
	
	filebuf fbPersonas;
	
	if(!fbPersonas.open(argv[1], ios::in))
		return 1;
	
	istream isPersonas(&fbPersonas);
	
	Persona pers;
	
	while(!isPersonas.eof())
	{
		isPersonas >> pers;
		cout << pers << endl;
	}
	
	fbPersonas.close();
*/

	
	EmpleadoBuilder eb;
	eb.setDni(1);
	eb.setApyn("Pepe Argento");
	eb.setEstadoCivil('C');
	eb.setfIngr(Fecha(19, 6, 2020));
	
	Empleado pepe = eb.build();
	
	cout << "Antiguedad de " + pepe.getApyn() + ": " + pepe.getAntiguedad() << endl;
	
/*	
	filebuf fbEmpleados;
	
	if(!fbEmpleados.open(argv[1], ios::in))
		return 1;
	
	istream isEmpleados(&fbEmpleados);
	
	Empleado empl;
	
	while(!isEmpleados.eof())
	{
		isEmpleados >> empl;
		cout << empl << endl;
	}

		
	fbEmpleados.close();
*/
	
	filebuf fbEmpleados;
	
	if(!fbEmpleados.open(argv[1], ios::in))
		return 1;
	
	ofstream oBin("Empleados.dat", ios::out | ios::binary);
	
	istream isEmpleados(&fbEmpleados);
	
	Empleado empl;
	
	while(!isEmpleados.eof())
	{
		isEmpleados >> empl;
		empl.write(oBin);
	}
	
	fbEmpleados.close();
	oBin.close();
	
	
	ifstream iBin("Empleados.dat", ios::in | ios::binary);
	
	while(!iBin.eof())
	{
		empl.read(iBin);
		cout << empl << endl;
		iBin.peek();
	}
	
	iBin.close();
	
    return 0;
}
