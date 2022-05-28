#include <iostream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaExc.h"
#include "../Cadena/FueraDeRangoExc.h"


using namespace std;


int main()
{
    Persona* persona1 = NULL;

    try
    {
        persona1 = new Persona("M12345678", "Juan", "Perez", Fecha(1, 1, 2000), 'M');
    }
    catch (PersonaExc& e)
    {
        cout << e.getMensaje() << endl;
        return 1;
    }
    catch(FueraDeRangoExc& e)
    {
        cout << e.getMensaje() << endl;
        return 2;
    }

    cout << "DNI: " << persona1->getDNI() << endl;

    delete persona1;

    return 0;
}
