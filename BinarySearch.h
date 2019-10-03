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

#include "BinarySearch.cpp"

#endif //BINARYSEARCH_BINARYSEARCH_H
