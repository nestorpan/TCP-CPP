#ifndef OPERATORFECHAINVALIDAEXCEPTION_H
#define OPERATORFECHAINVALIDAEXCEPTION_H


class OperatorFechaInvalidaException
{
   private:
        char mensaje[200];

    public:
        OperatorFechaInvalidaException(const char* mensaje);
        const char* getMensaje() const;
};

#endif // OPERATORFECHAINVALIDAEXCEPTION_H
