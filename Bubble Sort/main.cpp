#include <iostream>

using namespace std;

void Bubble_sort(int A[], int len)
{
    int temp;
    for(int i = 0; i < len-1; ++i)
    {
        for(int j = 0; j < len - 1 - i; ++j)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main()
{
    int A[20], len;

    cout << "Enter size of array: ";
    cin  >> len;
    cout << "\nEnter the elements of array ---->\n";
    for(int i = 0; i < len; ++i)
        cin >> A[i];

    Bubble_sort(A, len);

    cout << "\nSorted array ---->\n";
    for(int i = 0; i < len; ++i)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
