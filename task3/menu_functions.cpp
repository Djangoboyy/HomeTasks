#include "menu_functions.hpp"
#include <cstdlib>
#include <iostream>

// Главвное меню
const Djangoboyy::MenuItem* Djangoboyy::show_menu(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, мой юный друг" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const Djangoboyy::MenuItem* Djangoboyy::exit(const MenuItem* current) {
    std::exit(0);
}

// Второй уровень меню
const Djangoboyy::MenuItem* Djangoboyy::study_pl(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const Djangoboyy::MenuItem* Djangoboyy::study_ads(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const Djangoboyy::MenuItem* Djangoboyy::study_other_tech(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const Djangoboyy::MenuItem* Djangoboyy::study_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

// Третий уровень - другие технологии
const Djangoboyy::MenuItem* Djangoboyy::study_db(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const Djangoboyy::MenuItem* Djangoboyy::study_concurrent_prog(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const Djangoboyy::MenuItem* Djangoboyy::study_net_tech(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const Djangoboyy::MenuItem* Djangoboyy::study_go_back_other_tech(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}
