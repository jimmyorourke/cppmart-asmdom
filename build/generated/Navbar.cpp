#include "Navbar.hpp"

#include "utils.hpp"

asmdom::VNode* Navbar::render() {
    // clang-format off
    return asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"navbar"}}), asmdom::Children {asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"navbar_title"}}), "CppMart"), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"navbar_cart_value"}}), to_fixed_precision_str(_cartValue))});
    // clang-format on
}