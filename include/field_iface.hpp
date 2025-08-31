#pragma once
#include "types.hpp"

struct FieldQuery { double fx{0.0}, fy{0.0}; };

struct FieldInterface {
    virtual ~FieldInterface() = default;
    virtual FieldQuery query(double /*x*/, double /*y*/) const { return {}; }
};
