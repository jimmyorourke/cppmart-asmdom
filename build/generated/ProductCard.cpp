#include "ProductCard.hpp"

#include <iostream>
#include "utils.hpp"
#include "App.hpp"
#include "Home.hpp"
#include "ProductDetail.hpp"

asmdom::VNode* ProductCard::render() {
    // clang-format off
    return asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_card_container"}}), asmdom::Children {asmdom::h(u8"div", asmdom::Data (asmdom::Callbacks {{u8"onclick", [p = this->_product, c = this->_addToCartFn](emscripten::val) -> bool {
                 std::cout << "product deatail\n";
                 getApp().pageRender(ProductDetail{std::move(p), std::move(c), getApp().cartValue}.render());
                 return true;
               }}}), asmdom::Children {asmdom::h(u8"img", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_card_image"}, {u8"src", _product.image}})), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_card_name"}}), _product.name)}), asmdom::h(u8"div", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_card_price"}}), "$" + to_fixed_precision_str(_product.price)), asmdom::h(u8"button", asmdom::Data (asmdom::Attrs {{u8"class", u8"product_atc_button"}}, asmdom::Callbacks {{u8"onclick", // n.b. Can't just capture "this" otherwise there will be lifetime issues with the callback
             [c=this->_addToCartFn, p=this->_product](emscripten::val) -> bool {
               c(p);
               getApp().pageRender(getHome().render());
               return true;
             }}}), std::string(u8"Add To Cart"))});
    // clang-format on
}