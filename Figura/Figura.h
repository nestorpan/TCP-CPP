#ifndef FIGURA_H
#define FIGURA_H


class Figura // Clase abstracta: No puedo instanciar(crear) objetos de esta clase
{
public:
    virtual double area() const = 0; // = 0 significa que es un método virtual puro.
    virtual double perimetro() const = 0;
};


#endif // FIGURA_H
