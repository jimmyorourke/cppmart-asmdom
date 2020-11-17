#include "ProductDetail.hpp"

#include <emscripten.h>
#include "Navbar.hpp"
#include "utils.hpp"
#include "Home.hpp"

asmdom::VNode* ProductDetail::render() {
    // set the product name in the address bar
    EM_ASM({history.pushState(null, null, UTF8ToString($0))}, _product.name.c_str());

    // clang-format off
    return asmdom::h(u8"div", asmdom::Children {Navbar(_cartValue).render(), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_detail_container"}}), asmdom::Children {asmdom::h(u8"img", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_detail_image"}, {u8"src", _product.image}})), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_card_name"}}), _product.name), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"style", u8"margin: 10px 0; line-height: 24px;"}}), _product.description), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_card_price"}}), "$" + to_fixed_precision_str(_product.price)), asmdom::h(u8"button", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_atc_button"}}, asmdom::Callbacks {{u8"onclick", [c=this->_addToCartFn, p=this->_product](emscripten::val) -> bool {
                    c(p);
                    getApp().pageRender(getHome().render());
                    return true;
                }}}), std::string(u8"Add To Cart"))})});
    // clang-format on
}