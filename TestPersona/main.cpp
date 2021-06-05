#include <iostream>
#include <fstream>

#include "../Persona/include/PersonaBuilder.h"
#include "../Persona/include/PersonaException.h"
#include "../Fecha/FechaException.h"

using namespace std;


int main()
{
	filebuf fbLog;
	fbLog.open("Logs.txt", ios::app);
	ostream logOS(&fbLog);

	PersonaBuilder pb;
	pb.setDni(2404600);
	pb.setApyn("Pepe Argento");
	pb.setEstadoCivil('C');

	try
	{
		pb.setFNac(Fecha(1, 3, 1993));

		Fecha fecNac = Fecha(1, 3, 1993);
		pb.setFNac(fecNac);
	}
	catch(FechaException& ex)
	{
		logOS << ex.getMensaje() << endl;
		return 1;
	}

    Persona p;
	try
	{
		p = pb.build();
		Persona p2 = pb.build();


		cout << p << endl;
	}
	catch(PersonaException& ex)
	{
		logOS << ex.getMensaje() << endl;
		return 1;
	}


    return 0;
}
