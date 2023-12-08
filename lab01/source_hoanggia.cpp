#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;

void inputMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
}

void fillRandomMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matrix[i][j] = rand() % 10;
}

void displayMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int** createMatrix(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int** multiplyMatrices(int** matrix1, int** matrix2, int size) {
    
}

int main() {
    srand(time(NULL));
    int n1, m1, n2, m2, k;

    cout << "Enter dimensions of the first matrix: ";
    cin >> n1 >> m1;
    cout << "Enter dimensions of the second matrix: ";
    cin >> n2 >> m2;

    int** M1 = createMatrix(n1, m1);
    int** M2 = createMatrix(n2, m2);

    cout << "Choose matrix filling method:\n"
         << "1 - Manual input\n"
         << "2 - Random filling\n";
    cin >> k;

    switch (k) {
        case 1:
            cout << "Enter elements of the first matrix:\n";
            inputMatrix(M1, n1, m1);

            cout << "Enter elements of the second matrix:\n";
            inputMatrix(M2, n2, m2);
            break;
        case 2:
            fillRandomMatrix(M1, n1, m1);
            fillRandomMatrix(M2, n2, m2);
            break;
    }

    cout << "\nMatrix 1:\n";
    displayMatrix(M1, n1, m1);
    cout << "\nMatrix 2:\n";
    displayMatrix(M2, n2, m2);

 
    deleteMatrix(M1, n1);
    deleteMatrix(M2, n2);

    return 0;
}
