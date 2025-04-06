#pragma once

#include <string>
class Numero{
    public:
        virtual Numero* operator+ (const Numero* rhn) const = 0;
        virtual Numero* operator- (const Numero* rhn) const = 0;
        virtual Numero* operator* (const Numero* rhn) const = 0;
        
        virtual std::string toString() const = 0;

        virtual ~Numero() {}
};