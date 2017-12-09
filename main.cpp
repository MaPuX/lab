#include <iostream>
#include <iomanip>

using namespace std;

void FillingArrayByRandom (int rows, int columns, int **array);
void FillingArrayByYourself(int rows, int columns, int **array);
void SortArray(int rows, int columns, int **array, int *array2);
void OutputArray(int rows, int columns, int **array);
void Menu();

int main() {

    int sum;
    sum = 0;

    cout << "Before you start, enter the size of a two-dimensional array\n";

    cout << "Enter the number of rows in the array\n";
    int rows;
    cin >> rows;

    cout << "Enter the number of columns in the array\n";
    int columns;
    cin >> columns;

    int **array = new int *[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }

    Menu();

    int menu = 0;
    cin >> menu;

    while (menu > 0 || menu < 5) {
        switch (menu) {
            case 1: {
                cout << "1 - Случайно заполнить массив\n"
                        "2 - Ввести элементы массива с клавиатуры\n";
                int a;
                cin >> a;

                switch (a) {
                    case 1:
                        FillingArrayByRandom(rows, columns, array);
                        break;
                    case 2:
                        FillingArrayByYourself(rows, columns, array);
                        break;
                    default:
                        cout << "Ошибка, попробуйте снова.";
                }

                cout << endl;

                Menu();
                cin >> menu;
                break;
            }
            case 2: {
                int *array2 = new int[rows];

                SortArray(rows, columns, array, array2);

                delete[] array2;

                cout << "Массив отсортирован по убыванию сумм элементов каждой строки";
                cout << endl;

                Menu();
                cin >> menu;
                break;
            }
            case 3: {
                OutputArray(rows, columns, array);

                cout << endl;

                Menu();
                cin >> menu;
                break;
            }
            case 4:
                exit(0);
                break;
            default: {
                cout << "Неправильное число! Попробуйте снова!" << endl;
                Menu();
                cin >> menu;
                break;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

}

void FillingArrayByRandom (int rows, int columns, int **array){
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 10 + 1;
            sum += array[i][j];
            cout << setw(7) << array[i][j];
        }
        cout << "  |  " << sum << endl;
        sum = 0;
    }
}


void FillingArrayByYourself(int rows, int columns, int **array){
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> array[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += array[i][j];
            cout << setw(7) << array[i][j];
        }
        cout << "  |  " << sum << endl;
        sum = 0;
    }
}

void SortArray(int rows, int columns, int **array, int *array2){
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += array[i][j];
        }
        array2[i] = sum;
        sum = 0;
    }

    for (int i = 0; i < rows; i++) {
        int max = array2[i];
        int positionMax = i;
        int *mas;
        for (int j = i + 1; j < rows; j++) {
            if (array2[j] > max) {
                max = array2[j];
                positionMax = j;
            }
        }
        if (positionMax != i) {
            array2[positionMax] = array2[i];
            array2[i] = max;

            mas = array[i];
            array[i] = array[positionMax];
            array[positionMax] = mas;
        }
    }
}

void OutputArray(int rows, int columns, int **array){
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += array[i][j];
            cout << setw(7) << array[i][j];
        }
        cout << "  |  " << sum << endl;
        sum = 0;
    }
}

void Menu() {
    cout << "------- Menu -------" << endl;
    cout << "1. Enter values\n2. Data processing\n3. Output results\n4. Exit\n";
}
