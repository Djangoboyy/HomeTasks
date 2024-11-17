#include <iostream>
#include <vector>
#include "response_io.hpp"

void gra::response( std::vector<std::vector<int>> &queries, std::vector<int> &cells ) {
    for ( std::vector<int> q: queries ) { // O(Q)
        std::cout << q[0] << "..." << q[1] << " : ";

        if( !( cells[q[1]] && cells[q[0]] ) ) {
            std::cout << 0 << std::endl;
            continue;
        }

        std::cout << cells[q[1]] - cells[q[0]] + 1 << std::endl;
    }
}
