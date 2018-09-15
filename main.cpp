#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions) {
        int suma = 0;
        int producto = 1;
        for(int i = 0; i < dimensions; i++){
            if(i>0) producto *= sizes[i-1];

            suma+=sizes[i]*producto;
        }
        return suma;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    int sizes[] = {5, 6};
    Vector<Integer> v1(2, sizes);

    int coord[] = {2, 2};
    v1.set(6, coord);

    cout << v1.get(coord) << endl;



    system("pause");
    return EXIT_SUCCESS;
}