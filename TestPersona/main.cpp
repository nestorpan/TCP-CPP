#include <iostream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaExc.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "spanish");
    Persona pepe;
    Cadena dni("24004600");

    try {
        pepe.setDni(dni);
        pepe.setNombre("José");
    }
    catch(PersonaExc exc) {
        cout << "Error al crear la Persona" << endl;
        return 1;
    }
    cout << "Persona creada OK!!!" << endl;

    //Persona* juan = NULL;
    Persona juan;

    try {
        juan = Persona(3233232, "Juan", "Perez", Fecha(1, 1, 1970), 'M');
    }
    catch(PersonaExc exc) {
        cout << "Error al crear la Persona " << endl;
        return 1;
    }
    cout << "Persona creada OK!!!" << juan.getNombre()<< endl;
//    delete juan;

    return 0;
}
