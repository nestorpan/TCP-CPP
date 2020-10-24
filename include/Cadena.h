#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

using namespace std;

class Cadena
{
    private:
        char* cad;

        Cadena(char* cad);

        static int cantCall;

        static int contarDigitos(int d);

    public:
        Cadena();
        Cadena(const char* cad);
        Cadena(char c);
        Cadena(int d);

        Cadena(const Cadena& cadena); /// Constructor de copia
        ~Cadena(); /// Destructor

        Cadena& operator =(const Cadena& otra); /// Op asignación
        ///Cadena operator +(const Cadena& otra) const;
        Cadena& operator +=(const Cadena& otra);
        /// Cadena& operator +=(const Cadena& otra);

        int getCantCall();

///        char caracterEnPos(int pos) const;
        int posCaracter(char c, int ini = 0) const;
///        Cadena podar() const;
        Cadena subcadena(int ini, int fin) const;
        Cadena subcadena(int ini) const;
///        bool contiene(const Cadena& cadABuscar) const;
///        Cadena reemplazar(const Cadena& cadABuscar, const Cadena& cadReempl) const;
        vector<Cadena> split(char separador) const; /// Hola, que tal? split(',') ==> vector = {"Hola", " que tal?"}

        istream& leer(istream& ent, char hastaCar);
        bool letrasYEspacios() const;

        friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);

        friend ostream& operator <<(ostream& sal, const Cadena& cadena);
        friend istream& operator >>(istream& ent, Cadena& cadena);

};

#endif // CADENA_H
