#include <iostream>

#include <Cadena.h>

using namespace std;


void generarArchivoProductos(const Cadena& nombreArchivo);

int main(int argc, char* argv[])
{
	generarArchivoProductos(argv[1]);
	
	
    return 0;
}


void generarArchivoProductos(const Cadena& nombreArchivo)
{
	fstream archivo;
	archivo.open(nombreArchivo.getPChar(), ios::out | ios::binary);
	
	
}
