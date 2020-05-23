#include <fstream>
#include <iostream>
#include <Cadena.h>

#define ARG_TXT_ENT_1 1
#define ARG_TXT_ENT_2 2
#define ARG_TXT_SAL 3

#define TODO_OK 0
#define ERROR_ARCH 1


using namespace std;


int main(int argc, char* argv[])
{
    ///TODO: Validar cant argumentos.
    
    filebuf fbEnt1;
    
    if(!fbEnt1.open(argv[ARG_TXT_ENT_1], ios::in))
	{
		cout << "Error abriendo archivo " << argv[ARG_TXT_ENT_1] << endl;
		return ERROR_ARCH;
	}
	
    istream archEnt1(&fbEnt1);
    
    
    filebuf fbEnt2;
    
    if(!fbEnt2.open(argv[ARG_TXT_ENT_2], ios::in))
	{
		cout << "Error abriendo archivo " << argv[ARG_TXT_ENT_2] << endl;
		return ERROR_ARCH;
	}	
	
    istream archEnt2(&fbEnt2);
    
    
    filebuf fbSal;
    
    if(!fbSal.open(argv[ARG_TXT_SAL], ios::out))
	{
		cout << "Error abriendo archivo " << argv[ARG_TXT_SAL] << endl;
		return ERROR_ARCH;
	}	
	
    ostream archSal(&fbSal);
    
    Cadena linea1, linea2;
    Cadena lineaConcat;
    
	while(archEnt1.peek() != EOF && archEnt2.peek() != EOF)
	{
		archEnt1 >> linea1;
		archEnt2 >> linea2;
		lineaConcat = linea1 + "|" + linea2;
		archSal << lineaConcat << endl;
	}
    
    fbEnt1.close();
    fbEnt2.close();
    fbSal.close();
	
    return 0;
}
