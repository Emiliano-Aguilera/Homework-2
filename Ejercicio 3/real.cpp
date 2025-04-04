#include "real.hpp"

Real::Real(float value){
    realPart = value;
}

Real Real::operator+ (const Real& rhn) const {    
    return Real(realPart + rhn.getRealPart());
}

Real Real::operator- (const Real& rhn) const {
    return Real(realPart - rhn.getRealPart());
}

Real Real::operator* (const Real& rhn) const {
    return Real(realPart * rhn.getRealPart());
}

Real Real::operator/ (const Real& rhn) const {
    if (rhn.getRealPart() == 0.0){
        throw std::invalid_argument("Division by zero.");
    }
    
    return Real(realPart / rhn.getRealPart());
}

std::string Real::toString() const {
    return std::format("{}", realPart);
}
