#pragma once

#include "App.hpp"
#include "Product.hpp"
#include <asm-dom.hpp>

class Home;
Home& getHome();

class Home {
 public:
    Home(double* cartValue);

    asmdom::VNode* render();

 private:
    bool addToCart(const Product& product);

    struct CartProduct {
        Product product;
        int quantity;
    };
    std::vector<Product> _products;
    std::vector<CartProduct> _cartProducts;
    double* _cartValue{};
};