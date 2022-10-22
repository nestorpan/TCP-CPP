#include <iostream>
#include <fstream>
#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"

using namespace std;


int main()
{    
    system("chcp 1252 > nul");

    // PersonaBuilder personaBuilder;    

    // try
    // {
    //     personaBuilder
    //         .setDni(22333444)
    //         .setApellido("Gonzalez")
    //         .setNombre("Juan")
    //         .setFechaNacimiento(Fecha(1, 1, 1990));
    // }
    // catch(PersonaException& e)
    // {
    //     cerr << e.getMensaje() << endl;
    //     return 1; // Error validaci�n.
    // }

    // Persona gonzalezJuan = personaBuilder.buildEstatica();
    
    // cout << gonzalezJuan.getApellido() << ", " << gonzalezJuan.getNombre() << endl;

    // Persona* gonzalezJuan2 = personaBuilder.buildDinamica();
    // cout << gonzalezJuan2->getApellido() << ", " << gonzalezJuan2->getNombre() << endl;
    

    // Grabo en archivo.
    
    // fstream archivo("Personas.txt", ios::out);
    
    // archivo << *gonzalezJuan2 << endl;

    // delete gonzalezJuan2;


    // try
    // {
    //     personaBuilder
    //         .setDni(33444555)
    //         .setApellido("Pérez")
    //         .setNombre("Rodrigo")
    //         .setFechaNacimiento(Fecha(10, 10, 1991));
    // }
    // catch(PersonaException& e)
    // {
    //     cerr << e.getMensaje() << endl;
    //     return 1; // Error validaci�n.
    // }

    // Persona* perezRodrigo = personaBuilder.buildDinamica();

    // archivo << *perezRodrigo << endl;

    // delete perezRodrigo;

    // archivo.close();


    // Leo de archivo.

    fstream archivoLectura("Personas.txt", ios::in);

    vector<Persona*> personas;

    while(archivoLectura.peek() != EOF)
    {
        Persona* persona = new Persona();
        archivoLectura >> *persona;
        personas.push_back(persona);
    }

    for(Persona* pers : personas)
    {
        cout << pers->getApellido() << ", " << pers->getNombre() << endl;
        delete pers;
    }

    return 0;
}
