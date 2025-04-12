#include "menu_items.hpp"
#include "menu_functions.hpp"
#include <cstddef>

// Главное меню
const Djangoboyy::MenuItem Djangoboyy::STUDY_GO_BACK_OTHER_TECH = {
    "0 - Выйти в предыдущее", Djangoboyy::study_go_back_other_tech, &Djangoboyy::STUDY_OTHER_TECH
};
const Djangoboyy::MenuItem Djangoboyy::STUDY_DB = {
    "1 - Базы данных", Djangoboyy::study_db, &Djangoboyy::STUDY_OTHER_TECH
};
const Djangoboyy::MenuItem Djangoboyy::STUDY_CONCURRENT_PROG = {
    "2 - Многопоточное программирование", Djangoboyy::study_concurrent_prog, &Djangoboyy::STUDY_OTHER_TECH
};
const Djangoboyy::MenuItem Djangoboyy::STUDY_NET_TECH = {
    "3 - Сетевые технологии", Djangoboyy::study_net_tech, &Djangoboyy::STUDY_OTHER_TECH
};

namespace {
    const Djangoboyy::MenuItem* const oth_tech_children[] = {
        &Djangoboyy::STUDY_GO_BACK_OTHER_TECH,
        &Djangoboyy::STUDY_DB,
        &Djangoboyy::STUDY_CONCURRENT_PROG,
        &Djangoboyy::STUDY_NET_TECH,
    };
    const int study_oth_tech_size = sizeof(oth_tech_children) / sizeof(oth_tech_children[0]);
}

// Второй уровень меню
const Djangoboyy::MenuItem Djangoboyy::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", Djangoboyy::study_go_back, &Djangoboyy::STUDY
};
const Djangoboyy::MenuItem Djangoboyy::STUDY_PL = {
    "1 - Изучать языки программирования", Djangoboyy::study_pl, &Djangoboyy::STUDY
};
const Djangoboyy::MenuItem Djangoboyy::STUDY_ADS = {
    "2 - Алгоритмы и структуры", Djangoboyy::study_ads, &Djangoboyy::STUDY
};
const Djangoboyy::MenuItem Djangoboyy::STUDY_OTHER_TECH = {
    "3 - Другие технологии", Djangoboyy::show_menu, &Djangoboyy::STUDY, oth_tech_children, study_oth_tech_size
};

namespace {
    const Djangoboyy::MenuItem* const study_children[] = {
        &Djangoboyy::STUDY_GO_BACK,
        &Djangoboyy::STUDY_PL,
        &Djangoboyy::STUDY_ADS,
        &Djangoboyy::STUDY_OTHER_TECH,
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

// Главное меню
const Djangoboyy::MenuItem Djangoboyy::STUDY = {
    "1 - Изучать программирование", Djangoboyy::show_menu, &Djangoboyy::MAIN, study_children, study_size
};
const Djangoboyy::MenuItem Djangoboyy::EXIT = {
    "0 - Пойти играть в футбол", Djangoboyy::exit, &Djangoboyy::MAIN
};

namespace {
    const Djangoboyy::MenuItem* const main_children[] = {
        &Djangoboyy::EXIT,
        &Djangoboyy::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Djangoboyy::MenuItem Djangoboyy::MAIN = {
    nullptr, Djangoboyy::show_menu, nullptr, main_children, main_size
};
