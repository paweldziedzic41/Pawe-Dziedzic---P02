#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;

/*Dla ciągu (w postaci tablicy) zawierającego wyłącznie wartości 0 lub 1, znajdź podciąg zawierający równą liczbę zer i jedynek, którego długość jest największa
Przykład.
	Wejście: 0,0,1,0,1,0,0
	Wyjście: Najdłuższym podciągiem są: 0,1,0,1 oraz 1,0,1,0
*/

int podciag (int arr[], int n)
{
    int sum = 0; // W tej zmiennej będzie przechowywana suma ciągu
    int maks = -1; // W tej zmiennej będzie przechowywany maksymalny rozmiar podciągu
    int start; // Początek podciągu
    int sum2 = 0; // W tej zmiennej będzie przechowywana suma drugiego ciągu 
    int maks2 = -1; // W tej zmiennej będzie przechowywany maksymalny rozmiar drugiego podciągu
    int start2; // Początek drugiego podciągu

    // Sprawdzamy po kolei każdy wyraz w tablicy
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 0) 
            sum = -1; // Jeśli wyraz jest równy 0 to nadajemy zmiennej sum wartość -1
        else 
            sum = 1; // Natomiast jeśli ma wartość 1 to nadajemy zmiennej sum wartość 1

        // Liczymy od od i-tego wyrazu ciągu różnice lub sume aż do ostatniego wyrazu
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == 0) {
                sum = sum - 1;
            }
            else {
                sum = sum + 1;
            }
            // Jeśli zmienna sum po dodawaniu i odejmowaniu kolejnych wartości będzie równa 0 
            // to przerywamy pętle i wykonujemy instrukcje warunkową 
            if (sum == 0 && maks < j - i + 1) {
                maks = j - i + 1; // Do zmiennej maks zapisujemy długość ciągu
                start = i; // Do zmiennej start zapisujemy początek podciągu 
            }
        }
    }
        // Jeśli w ciągu nie znajdziemy zmiennej sum równej 0 to oznacza że nie ma w naszym ciągu,
        // podciągu o równej liczbie zer i jedynek
    if (maks == -1) {
        cout << "Brak podciągów";
        cin.get();
        return 0;
    }
        // W przeciwnym razie wypisujemy nasz podciąg zaczynając od zmiennej zacznij, a kończąc na zmiennej suma,
        // której przypisujemy wartość sumy zacznij i maks oraz różnicy 1
        else {
            cout << "Najdluszym podciagiem jest: ";
            int suma = start + maks - 1;
            for (int k = start; k <= suma; k++) {
                cout << arr[k] << ",";
            }
        }
        //Program wykonuje kolejny objeg po ciągu tym razem zaczynając od kolejnego wyrazu, znalezionego podciągu 
        for (int s = start + 1 ; s < n - 1; s++) {
            if (arr[s] == 0)
                sum2 = -1;
            else
                sum2 = 1;

            for (int m = s + 1; m < n; m++) {
                if (arr[m] == 0) {
                    sum2 = sum2 - 1;
                }
                else {
                    sum2 = sum2 + 1;
                }

                if (sum2 == 0 && maks2 < m - s + 1) {
                    maks2 = m - s + 1;
                    start2 = s;
                }
            }
        }
        // Teraz sprawdzamy czy drugi podciąg ma taką samą długość.
        // Jeśli tak to wypisujemy go na tych samych warunkach co podciąg pierwszy
        if (maks2 == maks) {
            cout << " oraz ";
            if (maks2 == -1) {
            
            }
            else
            {
                int suma2 = start2 + maks2 - 1;
                for (int i = start2; i <= suma2; i++) {
                    cout << arr[i] << ",";
                }
            }
        }

        cin.get();
        return maks, maks2;
        
}


int main()
{

    int arr[] = {0,0,1,0,1,0,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
    podciag(arr, size);
    return 0;

}
