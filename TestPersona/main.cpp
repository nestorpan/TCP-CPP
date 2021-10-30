#include <iostream>
#include <fstream>
#include <vector>
#include "../Persona/Persona.h"
#include "../Persona/PersonaException.h"
#include "../Persona/PersonaBuilder.h"
#include "../Persona/Empleado.h"
#include "../Persona/EmpleadoBuilder.h"

using namespace std;


int main()
{
	try
   	{
		// Persona juan(22333444, "Pérez", "Juan", 'M', Fecha(17, 10, 2000));
		
		PersonaBuilder builder;
		builder.setFNac(Fecha(23, 10, 2000));
		builder.setNombre("Juan");
		builder.setDni(22333444);
		
		Persona juan = builder.build();
		
		cout << "La edad de " << juan.getNombre() << " es: " << juan.getEdad() << '.' << endl; 
		
		cout << juan << endl;

		EmpleadoBuilder eBuilder;
		eBuilder.setDni(22333444);
		eBuilder.setNombre("Pedro");
		eBuilder.setPuesto("Sistemas");
		eBuilder.setFNac(Fecha(1, 1, 2000));

		Empleado pepe = eBuilder.build();
		
		cout << pepe << endl;


		filebuf fb;
		fb.open("Empleados.txt", ios::in);
	
		if(!fb.is_open())
			throw "No se pudo abrir el archivo\n";
	
		istream empleadosI(&fb);

		Empleado* empl;
		vector<Empleado*> empleadosV;

		while(!empleadosI.eof())
		{
			empl = eBuilder.buildDin();
			empleadosI >> *empl;
			empleadosV.push_back(empl);
		}

		fb.close();
		Empleado emp = eBuilder.build();
		for(vector<Empleado*>::iterator i = empleadosV.begin(); i < empleadosV.end(); i++)
		{
			emp = **i;
			cout << emp << endl;
		}
			
		return 0;
    }
    catch(PersonaException& ex)
    {
    	cout << ex.getMensaje() << endl;
    	return 1;
    }
}
