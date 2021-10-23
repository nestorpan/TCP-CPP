#include <iostream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaException.h"
#include "../Persona/PersonaBuilder.h"
#include "../Persona/Empleado.h"
#include <locale.h>

using namespace std;

int main()
{
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

		cout << "La edad de " << juan.getNombre() + " "+ juan.getApellido() << " es: " << juan.getEdad() << '.' << endl;


		PersonaBuilder builderMarta;
		builderMarta.setFNac(Fecha::hoy());
		builderMarta.setApellido("Perez");
		builderMarta.setDni(2222222);

		Persona marta = builderMarta.buildMarta();

		cout << "La edad de " << marta.getNombre() << " Sexo ==> " << marta.getSexo() << + " "+ marta.getApellido()
                << " es: " << marta.getEdad() << '.' << endl;


		Empleado pepe(22333444, "Pérez", "Juan", 'M', Fecha(17, 10, 2000),
                11111, "Sistemas", 40000, Fecha::hoy());

		return 0;
    }
    catch(PersonaException& ex)
    {
    	cout << ex.getMensaje() << endl;
    	return 1;
    }
}
