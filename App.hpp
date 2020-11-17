#pragma once

#include <asm-dom.hpp>

// Essentially global app state and controller

class App {
 public:
    void pageRender(asmdom::VNode* newVnode) {
        static auto vdomReplaced = false;
        if (!vdomReplaced) {
            const auto root =
                emscripten::val::global("document").call<emscripten::val>("getElementById", std::string("root"));
            _currentVnode = asmdom::patch(root, newVnode);
            vdomReplaced = true;
        } else {
            _currentVnode = asmdom::patch(_currentVnode, newVnode);
        }
    }

    // application state -- shared state needed by multiple page views
    double cartValue{};
    
private:
    // asmdom state
    asmdom::VNode* _currentVnode = nullptr;
};

inline App& getApp() {
    static App a;
    return a;
}