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
    setlocale(LC_CTYPE, "spanish");
	try
   	{
		// Persona juan(22333444, "Pérez", "Juan", 'M', Fecha(17, 10, 2000));

		PersonaBuilder builder;
		builder.setFNac(Fecha(23, 10, 2000));
		builder.setNombre("Juan");
		builder.setApellido("Perez");
		builder.setDni(22333444);

		Persona juan = builder.build();

		//Persona juan2(222, "", "", 'M', Fecha::hoy()); NO SE PUEDE MAS!!!

		//cout << "La edad de " << juan.getNombre() + " "+ juan.getApellido() << " es: " << juan.getEdad() << '.' << endl;


		PersonaBuilder builderMarta;
		builderMarta.setFNac(Fecha::hoy());
		builderMarta.setApellido("Perez");
		builderMarta.setDni(2222222);

		Persona marta = builderMarta.buildMarta();
/*
		cout << "La edad de " << marta.getNombre() << " Sexo ==> " << marta.getSexo() << + " "+ marta.getApellido()
                << " es: " << marta.getEdad() << '.' << endl;
*/
/*
		Empleado pepe(22333444, "Pérez", "Juan", 'M', Fecha(17, 10, 2000),
                11111, "Sistemas", 40000, Fecha::hoy());
*/
        EmpleadoBuilder eBuilder;
		eBuilder.setDni(22333444);
		eBuilder.setNombre("Pedro");
		eBuilder.setApellido("García");
		eBuilder.setPuesto("Sistemas");
		eBuilder.setSueldo(100000);
		eBuilder.setFNac(Fecha(1, 1, 2000));

		Empleado pepe = eBuilder.build();

//		cout << pepe << endl;

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
		    //if (!empl.isEmpy())
            {
                empleadosV.push_back(empl);
		    }
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
