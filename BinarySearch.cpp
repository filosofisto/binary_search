
template<typename T>
BinarySearch<T>::BinarySearch() = default;

template<typename T>
BinarySearch<T>::~BinarySearch() = default;

template<typename T>
bool BinarySearch<T>::binary_search(const list <T> &list, T target) const
{
    T array[list.size()];
    populate_array_from_list(list, array);

    return binary_search(array, 0, list.size()-1, target, list.size());
}

template<typename T>
bool BinarySearch<T>::binary_search(const T *array, int begin, int end, T target, int size) const {
    // Tenta o elemento do meio
    int position = size/2;

    // Valor do elemento do meio
    // position+begin eh importante por que estamos tratando de uma fatia do array
    T valueInPos = array[position+begin];

    if (valueInPos == target) {
        // Achou o valor desejado
        return true;
    } else {
        // Condicao de parada do algoritmo recursivo
        if (begin == end) {
            return false;
        }

        // Nao achou e o valor pode estar na parte de cima do array
        if (target > valueInPos) {
            return binary_search(array, position+1, size-1, target, (size-position-1));
        }

        // Nao achou e o valor pode estar na parte de baixo do array
        return binary_search(array, 0, position-1, target, position);
    }
}

template<class T>
void BinarySearch<T>::populate_array_from_list(const list<T> &list, T *array) const {
    int p = 0;

    for (T const &i: list) {
        array[p++] = i;
    }
}