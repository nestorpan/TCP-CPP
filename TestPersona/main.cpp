#include <iostream>
#include <fstream>

#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"
#include "../Fecha/FechaException.h"

using namespace std;


int main()
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

	
    return 0;
}
