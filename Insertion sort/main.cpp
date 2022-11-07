#include <iostream>

using namespace std;

void Insertion_sort(int A[], int len)
{
    int ele, j;
    for(int i = 1; i < len; ++i)
    {
        ele = A[i];
        j = i - 1;
        while(j >= 0)
        {
            if(A[j] > ele)
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = ele;
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

    Insertion_sort(A, len);

    cout << "\nSorted array ---->\n";
    for(int i = 0; i < len; ++i)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
