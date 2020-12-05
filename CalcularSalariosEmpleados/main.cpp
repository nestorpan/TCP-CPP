#include <iostream>
#include <fstream>

#include <EmpleadoInterno.h>
#include <EmpleadoExterno.h>

using namespace std;

#define ARG_ARCH_ENT 1
#define ARG_ARCH_SAL 2


Empleado* leerEmpleado(istream& arch);


int main(int argc, char* argv[])
{
    filebuf fbIn;
    fbIn.open(argv[ARG_ARCH_ENT], ios::in);
    
    istream archEnt(&fbIn);
    Empleado* empl;
    vector<Empleado*> vecEmpl;
    
    while(archEnt.peek() != EOF)
    {
		empl = leerEmpleado(archEnt);
		vecEmpl.push_back(empl);
    }
    
    fbIn.close();
    
    filebuf fbOut;
    fbOut.open(argv[ARG_ARCH_SAL], ios::out);
    
    ostream archSal(&fbOut);
        
    for(vector<Empleado*>::iterator i = vecEmpl.begin(); i < vecEmpl.end(); i++) 
    {
		archSal << (*i)->getDni() << '|' << (*i)->getApellido() << '|' << (*i)->getNombre() << '|' << (*i)->calcularSueldo() << endl;
		delete *i;
    }
    
    fbOut.close();
	
    return 0;
}


Empleado* leerEmpleado(istream& arch)
{
    Empleado* empl;
    Cadena tipoEmpl;
	
	tipoEmpl.leer(arch, '|');
	
	if(tipoEmpl == "interno")
	{
		empl = new EmpleadoInterno;
		arch >> *(EmpleadoInterno*)empl;
	}
	else
	{
		empl = new EmpleadoExterno;
		arch >> *(EmpleadoExterno*)empl;
	}
	
	arch.ignore(TAM_CAR_FIN_LINEA); /// Saco el fin de linea
	return empl;
}
