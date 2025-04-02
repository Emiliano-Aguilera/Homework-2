#pragma once

class Numero{
    private:
        int intPart;
        float realPart;
        float imagPart;
    public:
        virtual int getIntPart() const = 0;
        virtual float getRealPart() const;
        virtual float getImagPart() const;

        virtual void setIntPart(int value) = 0;
        virtual void setRealPart(float value);
        virtual void setImagPart(float iValue);
};