#include <iostream>
using namespace std;

void quickSort(int* array, int left, int right) {
    int i = left, j = right;
    int pivot = array[(left + right) / 2];
    while(i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i > j) break;
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
        i++;
        j--;
    }
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

int main() {
    freopen("1726.inp","r",stdin);
    long long n, sum = 0;
    cin >> n;
    int xCoords[n];
    int yCoords[n];
    for (long long i = 0; i < n; i++) cin >> xCoords[i] >> yCoords[i];
    quickSort(xCoords, 0, n - 1);
    quickSort(yCoords, 0, n - 1);
    for (long long i = 1; i < n; i++) sum += ((xCoords[i] - xCoords[i - 1]) + (yCoords[i] - yCoords[i - 1])) * (i) * (n - i) * 2;
    sum = sum / (n * (n - 1));
    cout << sum << endl;
    return 0;
}
