#ifndef CADENA_H
#define CADENA_H

#include <iostream>

using namespace std;

class Cadena
{
    private:
        char* cad;

        Cadena(char* cad);

        static int cantCall;

    public:
        Cadena();
        Cadena(const char* cad);

        Cadena(const Cadena& cadena); /// Constructor de copia
        ~Cadena(); /// Destructor

        Cadena& operator =(const Cadena& otra); /// Op asignación
        Cadena operator +(const Cadena& otra) const;
        /// Cadena& operator +=(const Cadena& otra);

        int getCantCall();

        char caracterEnPos(int pos) const;
        int posCaracter(char c) const;
        Cadena podar() const;
        Cadena subcadena(int ini, int fin) const; /// "Hola que tal?".sucadena(0, 4) ==> "Hola"; (1, 3) ==> "ol"
        bool contiene(const Cadena& cadABuscar) const;
        Cadena reemplazar(const Cadena& cadABuscar, const Cadena& cadReempl) const;
        vector<Cadena> split(char separador) const; /// Hola, que tal? split(',') ==> vector = {"Hola", " que tal?"}

        friend ostream& operator <<(ostream& sal, const Cadena& cadena);
        friend istream& operator >>(istream& ent, Cadena& cadena);

};

#endif // CADENA_H
