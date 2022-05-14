#ifndef FECHAEXC_H
#define FECHAEXC_H

#include <string>

using namespace std;


class FechaExc
{
private:
    string mensaje;

public:
    FechaExc(const string& mensaje);

    const string& getMensaje() const;
};


#endif // FECHAEXC_H
