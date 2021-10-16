#include <iostream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaException.h"


using namespace std;


int main()
{
    try
    {
		Persona juan(22333444, "Pérez", "Juan", 'M', Fecha(17, 10, 2000));
		
		cout << "La edad de " << juan.getNombre() << " es: " << juan.getEdad() << '.' << endl; 
		
		return 0;
    }
    catch(PersonaException& ex)
    {
    	cout << ex.getMensaje() << endl;
    	return 1;
    }
}
