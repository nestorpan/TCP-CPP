#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;


class Figura
{
private:
    string nombre;

public:
    Figura(const string& nombre);
    virtual ~Figura();

    virtual float area() const =0;
    virtual float perimetro() const=0;

    const string& getNombre() const;
};


#endif // FIGURA_H
