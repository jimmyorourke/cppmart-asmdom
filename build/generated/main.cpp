#include <asm-dom.hpp>
#include <emscripten/val.h>
#include <iostream>

#include <emscripten.h>
#include <emscripten/bind.h>
#include "App.hpp"
#include "Home.hpp"


void renderHome() { getApp().pageRender(getHome().render()); }
EMSCRIPTEN_BINDINGS(app) {
    emscripten::function("renderHome", &renderHome);
};

int main() {
    // Initialize asm-dom.
    const auto config = asmdom::Config();
    asmdom::init(config);

    auto& app = getApp();
    app.pageRender(getHome().render());

    // listener for the back button
    EM_ASM(window.addEventListener(
        'popstate', function(e) {
            var product = e.state;

            if (product == null) {
                Module.renderHome();
            }
        }));
}