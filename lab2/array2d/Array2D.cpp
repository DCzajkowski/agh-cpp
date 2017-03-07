//
// Created by Dariusz Czajkowski on 07/03/17.
//

#include <iostream>
#include "Array2D.h"

using namespace std;

int ** NewArray2D(int n_rows, int n_columns) {
    if (n_rows < 1 || n_columns < 1) {
        return nullptr;
    }

    int ** array = new int*[n_rows];

    for (int i = 0; i < n_rows; i++) {
        array[i] = new int[n_columns];
    }

    int n = 1;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            array[i][j] = n++;
        }
    }

    return array;
}

void DeleteArray2D(int ** array, int n_rows, int n_columns) {
    for (int i = 0; i < n_rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void FillArray2D(int k_rows, int k_cols, int *to_fill[]) {
    int n = 1;
    for (int i = 0; i < k_rows; i++) {
        for (int j = 0; j < k_cols; j++) {
            to_fill[i][j] = n++;
        }
    }
}