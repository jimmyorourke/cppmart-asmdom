#pragma once

#include <asm-dom.hpp>
#include "Product.hpp"

class ProductDetail {
 public:
    ProductDetail(Product product, std::function<bool(const Product&)> addToCartFn, double cartValue)
    : _product{product}
    , _addToCartFn{addToCartFn}
    , _cartValue{cartValue} {}

    asmdom::VNode* render();

 private:
    Product _product;
    std::function<bool(const Product&)> _addToCartFn;
    double _cartValue;
};