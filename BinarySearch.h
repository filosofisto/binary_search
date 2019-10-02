//
// Created by Eduardo Ribeiro da Silva on 02/10/19.
//

#ifndef BINARYSEARCH_BINARYSEARCH_H
#define BINARYSEARCH_BINARYSEARCH_H

#include <list>

using namespace std;

template <typename T>
class BinarySearch {
public:
    /**
     * Construtor
     */
    BinarySearch();

    /**
     * Destrutor
     */
    virtual ~BinarySearch();

    /**
     * Pesquisa binaria.
     *
     * @param list List de inteiros (universo de pesquisa)
     * @param target Valor procurado
     * @return true indica se o valor procurado esta na lista, e false caso contrario
     */
    bool binary_search(const list<T> &list, T target) const;

private:

    /**
     * Realiza a pesquisa binaria propriamente dita, usando array[int] ao inves do list
     * @param array Array
     * @param begin Inicio do array
     * @param end  Fim do array
     * @param target Valor procurado
     * @param size Tamanho da faixa do array usada na procura
     * @return true se achou e false se nao achou
     */
    bool binary_search(const T array[], int begin, int end, T target, int size) const;

    /**
     * Converte a list para um array[int] para facilitar o algoritmo
     * @param list List original
     * @param array
     */
    void populate_array_from_list(const list<T> &list, T* array) const;
};

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
        if (begin == end) {
            // Condicao de parada do algoritmo recursivo
            return false;
        } else if (target > valueInPos) {
            // Nao achou e o valor pode estar na parte de cima do array
            return binary_search(array, position+1, size-1, target, (size-position-1));
        } else {
            // Nao achou e o valor pode estar na parte de baixo do array
            return binary_search(array, 0, position-1, target, position);
        }
    }
}

template<class T>
void BinarySearch<T>::populate_array_from_list(const list<T> &list, T *array) const {
    int p = 0;

    for (T const &i: list) {
        array[p++] = i;
    }
}


#endif //BINARYSEARCH_BINARYSEARCH_H
