#include <iostream>
#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"

using namespace std;


int main()
{    
    system("chcp 1252 > nul");

    PersonaBuilder personaBuilder;    

    try
    {
        personaBuilder
            .setDni(22333444)
            .setApellido("Gonzalez")
            .setNombre("Juan")
            .setFechaNacimiento(Fecha(1, 1, 1990));
    }
    catch(PersonaException& e)
    {
        cerr << e.getMensaje() << endl;
        return 1; // Error validación.
    }

    Persona gonzalezJuan = personaBuilder.buildEstatica();
    
    cout << gonzalezJuan.getApellido() << ", " << gonzalezJuan.getNombre() << endl;

    Persona* gonzalezJuan2 = personaBuilder.buildDinamica();
    cout << gonzalezJuan2->getApellido() << ", " << gonzalezJuan2->getNombre() << endl;
    delete gonzalezJuan2;

    return 0;
}
