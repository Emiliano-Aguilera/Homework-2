#include "real.hpp"

Real::Real(float value){
    intPart = static_cast<int>(value);
    realPart = value - intPart;
}

Real Real::operator+ (const Real& rhn) const {
    float value1 = intPart + realPart;
    float value2 = rhn.getIntPart() + rhn.getRealPart();
    
    return Real(value1 + value2);
}

Real Real::operator- (const Real& rhn) const {
    float value1 = intPart + realPart;
    float value2 = rhn.getIntPart() + rhn.getRealPart();
    
    return Real(value1 - value2);
}

Real Real::operator* (const Real& rhn) const {
    float value1 = intPart + realPart;
    float value2 = rhn.getIntPart() + rhn.getRealPart();

    return Real(value1 * value2);
}

Real Real::operator/ (const Real& rhn) const {
    float value1 = intPart + realPart;
    float value2 = rhn.getIntPart() + rhn.getRealPart();

    if (value2 == 0.0){
        throw std::invalid_argument("Division by zero.");
    }
    
    return Real(value1 / value2);
}

std::string Real::toString() const {
    return std::format("{}", (intPart + realPart));
}
