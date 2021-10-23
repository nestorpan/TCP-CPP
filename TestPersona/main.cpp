#include <iostream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaException.h"
#include "../Persona/PersonaBuilder.h"
#include "../Persona/Empleado.h"

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
		
		Empleado pepe(22333444, "Pérez", "Juan", 'M', Fecha(17, 10, 2000), 11111, "Sistemas", 40000, Fecha(24, 10, 2021));
		
		return 0;
    }
    catch(PersonaException& ex)
    {
    	cout << ex.getMensaje() << endl;
    	return 1;
    }
}
