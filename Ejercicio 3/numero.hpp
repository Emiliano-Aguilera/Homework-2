#pragma once

#include <string>
class Numero{
    public:
        virtual std::shared_ptr<Numero> Numero::operator+ (const Complejo& rhn) const = 0;
        virtual std::shared_ptr<Numero> Numero::operator- (const Complejo& rhn) const = 0;
        virtual std::shared_ptr<Numero> Numero::operator* (const Complejo& rhn) const = 0;
};