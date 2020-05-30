#include <fstream>
#include <iostream>

#include "Empleado.h"


#define ARG_TXT_ENT 1
#define ARG_TXT_SAL 2


using namespace std;


int main(int argc, char* argv[])
{
    Empleado emp;
    
    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream empleadosAEnt(&fbEnt);
    
    filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream empleadosASal(&fbSal);
    
	while(empleadosAEnt.peek() != EOF)
	{
		empleadosAEnt >> emp;
		emp.setSueldo(emp.getSueldo() * 1.30);
	///	empleadosAEnt.ignore(1); ///Saca un carácter (enter) del buffer.
		empleadosASal << emp << endl;
	}
	
	fbEnt.close();
	fbSal.close();
    
    return 0;
}
