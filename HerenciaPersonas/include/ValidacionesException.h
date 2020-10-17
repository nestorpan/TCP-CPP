#ifndef VALIDACIONESEXCEPTION_H
#define VALIDACIONESEXCEPTION_H


class ValidacionesException
{
    private:
        string mensaje;

    public:
        ValidacionesException();
        ValidacionesException(const string& msj);

        const string& getMensaje() const;

};

#endif // VALIDACIONESEXCEPTION_H
