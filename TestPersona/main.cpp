#include <iostream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaException.h"
#include <locale.h>

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "spanish");
    try
    {
		Persona juan(22333444, "Pérez", "Juan", 'M', Fecha(16, 10, 2000));
		Persona juana(22333444, "Pérez", 'F');

		cout << "La edad de " << juan.getNombre() << " es: " << juan.getEdad() << '.' << endl;
		cout << "La edad de " << juana.getNombre() << " - sexo: " << juana.getSexo() << " es: " << juana.getEdad() << '.' << endl;

		return 0;
    }
    catch(PersonaException& ex)
    {
    	cout << ex.getMensaje() << endl;
    	return 1;
    }

}
