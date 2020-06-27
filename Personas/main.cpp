#include <fstream>
#include <iostream>
#include <algorithm>

#include "Empleado.h"
#include "EmpleadoBuilder.h"

#define ARG_TXT_ENT 1
#define ARG_TXT_SAL 2


using namespace std;


int main(int argc, char* argv[])
{
/**
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
		empleadosASal << emp << endl;
	}
	
	fbEnt.close();
	fbSal.close();
*/    
 /**   
    EmpleadoBuilder builder;
    
    builder.setDni(22333444);
    builder.setSexo('M');
    builder.setFechaNac(Fecha(7, 6, 2003));
    builder.setApellido("Perez");
    builder.setNombres("Juan Jose");
    builder.setSueldo(45777.23);
    
    Empleado emp = builder.build();
    
    cout << emp << endl;
    
    cout << emp.getApellido() << ", " << emp.getNombres() << " tiene " << emp.getEdad(Fecha::hoy()) << " anios." << endl;
*/
    
    Empleado emp;
    vector<Empleado> vEmp;
    
    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream empleadosAEnt(&fbEnt);
    
    filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream empleadosASal(&fbSal);
    
	while(empleadosAEnt.peek() != EOF)
	{
		empleadosAEnt >> emp;
		vEmp.push_back(emp);
	}
	
	for(vector<Empleado>::iterator i = vEmp.begin(); i < vEmp.end(); ++i)
        i->setSueldo(i->getSueldo() * 1.30);
	
	sort(vEmp.begin(), vEmp.end());
	
	for(vector<Empleado>::iterator i = vEmp.begin(); i < vEmp.end(); ++i)
        empleadosASal << *i << endl;
	
    fbEnt.close();
	fbSal.close();
    
    
    return 0;
}
