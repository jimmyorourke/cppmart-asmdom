#pragma once

#include <asm-dom.hpp>
#include "Product.hpp"

// This gets created and immediately destroyed each render. Should just be function?
class ProductCard {
 public:
    ProductCard(Product product, std::function<bool(const Product&)> addToCartFn)
    : _product{std::move(product)}
    , _addToCartFn{std::move(addToCartFn)} {}

    asmdom::VNode* render();

 private:
    Product _product;
    std::function<bool(const Product&)> _addToCartFn;
};