#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void TriangularForm(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = i + 1; j < rowCount; j++) {
            if (a[j][i] != 0) {
                double ratio = static_cast<double>(a[j][i]) / a[i][i];
                for (int k = 0; k < colCount; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }
}

int CountRowsWithAvgLessThan(int** a, const int rowCount, const int colCount, double threshold) {
    int count = 0;
    for (int i = 0; i < rowCount; i++) {
        double sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += a[i][j];
        }
        double avg = sum / colCount;
        if (avg < threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Low = -10;
    int High = 10;
    int rowCount, colCount;

    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    TriangularForm(a, rowCount, colCount);
    cout << "Трикутна форма матриці:" << endl;
    Print(a, rowCount, colCount);

    double threshold;
    cout << "Введіть порогове значення для середнього арифметичного: ";
    cin >> threshold;

    int count = CountRowsWithAvgLessThan(a, rowCount, colCount, threshold);
    cout << "Кількість рядків, середнє арифметичне яких менше " << threshold << ": " << count << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}