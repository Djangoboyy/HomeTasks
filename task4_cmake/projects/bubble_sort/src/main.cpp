#include "io.hpp"
#include "sortings.hpp"

int main() {
    int arr[] = {1, 8, 2, 5, 3, 11};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	gra::print_array("Массив до сортировки:", arr, arr_size);
    
    gra::sortings::bubble_sort(arr, arr_size);

    gra::print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}
