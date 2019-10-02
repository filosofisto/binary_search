#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

#include "BinarySearch.h"

int main() {
    cout << "----------------------------------------" << endl;
    cout << "Binary Search Sample with C++ Templates" << endl;
    cout << "----------------------------------------" << endl;

    list<string> mylist;
    string value;

    // ---------------------------------------------------
    // Popula a lista com valores
    // ---------------------------------------------------
    while (true) {
        cout << "Entre com um valor (X para terminar): ";
        cin >> value;

        if (value == "X") {
            break;
        }

        mylist.push_back(value);
    }

    // ---------------------------------------------------
    // Ordena a lista usando a STL
    // ---------------------------------------------------
    mylist.sort();

    // ---------------------------------------------------
    // Mostra os valores no console
    // ---------------------------------------------------
    list<string>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it) {
        cout << *it << endl;
    }

    // ---------------------------------------------------
    // Informa o valor a ser procurado
    // ---------------------------------------------------
    cout << "Procurar por: ";
    cin >> value;

    // ---------------------------------------------------
    // Binary Search da STL
    // ---------------------------------------------------
    /*if (binary_search(mylist.begin(), mylist.end(), value)) {
        cout << "Founded!!!";
    } else {
        cout << "Not founded!!";
    }*/

    // ---------------------------------------------------
    // Usa uma implementacao pessoal de binary search
    // que foi encapsulado numa Classe C++
    // ---------------------------------------------------
    BinarySearch<string> binarySearch;

    if (binarySearch.binary_search(mylist, value)) {
        cout << "Founded!!!";
    } else {
        cout << "Not founded!!";
    }

    return EXIT_SUCCESS;
}