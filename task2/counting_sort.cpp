#include <vector>
#include "counting_sort.hpp"

// int Q[] // counting_sort_mod - модифицировано от концепции сортирокой подсчетом
std::vector<int> gra::sortings::dumps_into_cells( std::vector<int> &array, const int lim ) {
    std::vector<int> cells(lim, 0) ;
    for ( int i : array ) { // O(N)
        cells[i]++;
    }

    int prev = -1;
    for ( int i = 0; i <= lim ; ++i ) { // O(K)
        if( cells[i] ) {
            cells[i] += cells[prev];
            prev = i;
        }
    }

    return cells;
}
