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

int** multiplyMatrices(int** matrix1, int** matrix2, int n1, int m1, int n2, int m2) {
    // Test ability to multiply matrices
    if (m1 != n2) {
        cout << "These two matrices cannot be multiplied!";
        return nullptr;
    }

    // Create a result matrix of appropriate size
    int** result = createMatrix(n1, m2);

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < m1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
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

    int** result = multiplyMatrices(M1, M2, n1, m1, n2, m2);

    if (result != nullptr) {
        cout << "\nMatrix Result:\n";
        displayMatrix(result, n1, m2);
        deleteMatrix(result, n1);
    }
 
    deleteMatrix(M1, n1);
    deleteMatrix(M2, n2);

    return 0;
}
