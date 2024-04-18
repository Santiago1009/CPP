#include <iostream>
using namespace std;
template <class T>
void sortArray(T arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
        for (int j = s - 1; i < j; j--)
            if (arr[j] < arr[j - 1])
            {
                int var = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = var;
            }
    cout << " Sorted array : ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int a[5] = {10, 50, 30, 40, 20};
    int n = 5;
    sortArray(a, n);
    char c[5] = {'g', 'a', 'i', 'h', 'e'};
    sortArray(c, n);
    return 0;
}
