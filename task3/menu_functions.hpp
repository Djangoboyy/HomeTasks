#pragma once
#include "menu.hpp"

namespace Djangoboyy {
    // Главное меню
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);

    // Второй уровень меню
    const MenuItem* study_go_back(const MenuItem* current);
    const MenuItem* study_pl(const MenuItem* current);
    const MenuItem* study_ads(const MenuItem* current);
    const MenuItem* study_other_tech(const MenuItem* current);

    // Третий уровень меню
    const MenuItem* study_go_back_other_tech(const MenuItem* current);
    const MenuItem* study_db(const MenuItem* current);
    const MenuItem* study_concurrent_prog(const MenuItem* current);
    const MenuItem* study_net_tech(const MenuItem* current);
}
