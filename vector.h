#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
             
    private:
        T* data;
        int dataSize;
        Operation operation;
        int dimensions;
        int* dimensionSizes;

    public:
        Vector() : data(nullptr) {};
             
        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
            dataSize = 1;
            for(int i  = 0; i < dimensions; i++){
                dataSize*=dimensionSizes[i];
            }
            data = new T[dataSize];
        }
             
        void set(T datum, int* coordinates) {
            *(data+operation(coordinates,dimensionSizes,dimensions))=datum;
        }
             
        T get(int* coordinates) {
            return data[operation(coordinates,dimensionSizes,dimensions)];
        }

        ~Vector() {
            delete [] data;
        }
};

#endif
