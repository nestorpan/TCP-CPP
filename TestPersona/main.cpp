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
        /*
        personaBuilder.setDni(22333444);
        personaBuilder.setApellido("Gonzalez");
        personaBuilder.setNombre("Juan");
        personaBuilder.setFechaNacimiento(Fecha(1, 1, 1990));
        */
        personaBuilder
            .setDni(10000)
            .setApellido("Gonzalez")
            .setNombre("Juan")
            .setFechaNacimiento(Fecha(1, 1, 1990));
    }
    catch(PersonaException& e)
    {
        cerr << e.getMensaje() << endl;
        return 1; // Error validación.
    }

    //Persona garcia;
    Persona gonzalezJuan = personaBuilder.buildEstatica();
    //gonzalezJuan.setApellido("Garcia");

    cout << gonzalezJuan.getApellido() << ", " << gonzalezJuan.getNombre() << " DNI = " << gonzalezJuan.getDni() << endl;

    Persona* gonzalezJuan2 = personaBuilder.buildDinamica();
    cout << gonzalezJuan2->getApellido() << ", " << gonzalezJuan2->getNombre() << endl;
    delete gonzalezJuan2;


    return 0;
}
