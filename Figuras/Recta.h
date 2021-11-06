#ifndef RECTA_H
#define RECTA_H

#include "Punto.h"


class Recta
{
private:
    Punto p1;
    Punto p2;
public:
    Recta();
    Recta(const Punto& p1, const Punto& p2);
    Punto getP1();
    Punto getP2();
    void setP1(const Punto& p1);
    void setP2(const Punto& p2);
    double distancia(const Punto& p) const;
};


#endif // RECTA_H
