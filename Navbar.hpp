#pragma once

#include <asm-dom.hpp>

class Navbar {
 public:
    Navbar(double cartValue)
    : _cartValue{cartValue} {}

    asmdom::VNode* render();

 private:
    double _cartValue;
};