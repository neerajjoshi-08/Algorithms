#include <iostream>

using namespace std;

int Partition(int A[], int p, int r)
{
	int temp, pivot = A[r];
	int i = p-1;

	for(int j = p; j <= r-1; ++j)
	{
		if (A[j] < pivot)
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

	return (i + 1);
}

void Quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int pi = Partition(A, p, r);
		Quick_sort(A, p, pi-1);
		Quick_sort(A, pi+1, r);
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

    Quick_sort(A, 0, len-1);

    cout << "\nSorted array ---->\n";
    for(int i = 0; i < len; ++i)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
