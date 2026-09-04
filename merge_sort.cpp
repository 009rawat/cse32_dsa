#include <iostream>
using namespace std;

void Merge(int a[], int l, int r, int mid)
{
    int n = mid - l + 1;
    int m = r - mid;

    int L[n], R[m];

    for (int i = 0; i < n; i++)
        L[i] = a[l + i];

    for (int j = 0; j < m; j++)
        R[j] = a[mid + j + 1];

    int i = 0, j = 0, k = l;

    while (i < n && j < m)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < m)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);

        Merge(a, l, r, mid);
    }
}

int main()
{
    int a[] = {3, 1, 2, 6, 4, 7, 5};
    int n = 7;

    MergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}