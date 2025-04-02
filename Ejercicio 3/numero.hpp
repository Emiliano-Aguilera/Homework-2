#pragma once

#include <string>
class Numero{
    protected:
        int intPart;
        float realPart;
        float imagPart;
    public:
        int getIntPart() const;
        float getRealPart() const;
        float getImagPart() const;

        void setIntPart(int value);
        void setRealPart(float value);
        void setImagPart(float iValue);

        virtual std::string toString() const = 0;

        // Usa el metodo toString() para crear una funcion generica que permite usar cout.
        friend std::ostream& operator<<(std::ostream& os, const Numero& numero);
};