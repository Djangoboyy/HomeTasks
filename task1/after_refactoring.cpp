#include <ctime>
#include <iostream>

int series_average(int* array, int size);
void series_filler(int* array, int size);
void series_print(int* array, int size);

int main()
{
    std::srand(time(0));

    const int arr_size = 10;

    for( int count = 1; count <= 3; count++ ) {
        int array[arr_size];
        series_filler( array, arr_size );
        std::cout << count << " последовательность" << std::endl;
        series_print( array, arr_size );
        std::cout << "Среднее " << count << " последовательности: " << series_average( array, arr_size ) << std::endl << std::endl;
    }

    return 0;
}


int series_average(int* array, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return float(sum) / float(size);
}

void series_filler(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }
}

void series_print(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
