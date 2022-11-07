#include <iostream>

using namespace std;

void Selection_sort(int A[], int len)
{
    int min_ele, pos;
    for(int i = 0; i < len-1; ++i)
    {
        min_ele = A[i], pos = i;
        for(int j = i+1; j < len; ++j)
        {
            if(min_ele > A[j])
            {
                min_ele = A[j];
                pos = j;
            }
        }
        A[pos] = A[i];
        A[i] = min_ele;
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

    Selection_sort(A, len);

    cout << "\nSorted array ---->\n";
    for(int i = 0; i < len; ++i)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
