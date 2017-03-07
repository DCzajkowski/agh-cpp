//
// Created by Dariusz Czajkowski on 07/03/17.
//

#include "Array2D.h"

int ** Array2D(int n_rows, int n_columns) {
    int ** array = new int*[n_rows];

    for (int i = 0; i < n_rows; i++) {
        array[i] = new int[n_columns];
    }

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            array[i][j] = i + j + 1;
        }
    }

    return array;
}

void DeleteArray2D(int ** array, int n_rows, int n_columns) {

}