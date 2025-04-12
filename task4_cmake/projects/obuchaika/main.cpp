#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"
#include <iostream>

int main() {
    const Djangoboyy::MenuItem* current = &Djangoboyy::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}