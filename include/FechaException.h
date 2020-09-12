#ifndef FECHAEXCEPTION_H
#define FECHAEXCEPTION_H

#include <string>

using namespace std;

class FechaException
{
    public:
//        FechaException();
        FechaException(const string& mensaje);
        const string& getMensaje() const;

    private:
        string mensaje;
};

#endif // FECHAEXCEPTION_H
