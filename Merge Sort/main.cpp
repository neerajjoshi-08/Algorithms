#include <iostream>

using namespace std;

void Merge(int A[], int p, int q)
{
    int mid = (p+q)/2;
    int i = p, j = mid+1, k = p;
    int temp[50];

    while(i <= mid && j <= q)
    {
        if(A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while(i <= mid)
        temp[k++] = A[i++];
    while(j <= q)
        temp[k++] = A[j++];

    for(int i = p; i <= q; ++i)
        A[i] = temp[i];
}

void Merge_sort(int A[], int p, int q)
{
    if(p >= q)
    {
        return;
    }

    int mid = (p+q)/2;

    Merge_sort(A, p, mid);
    Merge_sort(A, mid+1, q);

    Merge(A, p, q);

}

int main()
{
    int A[20], len;

    cout << "Enter size of array: ";
    cin  >> len;
    cout << "\nEnter the elements of array ---->\n";
    for(int i = 0; i < len; ++i)
        cin >> A[i];

    Merge_sort(A, 0, len-1);

    cout << "\nSorted array ---->\n";
    for(int i = 0; i < len; ++i)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
