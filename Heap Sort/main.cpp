#include <iostream>

using namespace std;

void Max_heap(int A[], int i, int len)
{
	int j, temp;
	temp = A[i];
	j = 2*i;

 	while (j <= len)
	{
		if (j < len && A[j+1] > A[j])
		j = j+1;
		if (temp > A[j])
			break;
		else if (temp <= A[j])
		{
			A[j/2] = A[j];
			j = 2*j;
		}
	}
	A[j/2] = temp;
	return;
}

void Heap_sort(int A[], int len)
{
	int i, temp;
	for (i = len; i >= 2; i--)
	{
		temp = A[i];
		A[i] = A[1];
		A[1] = temp;

        Max_heap(A, 1, i-1);
	}
}

void Build_maxheap(int A[], int len)
{
	for(int i = len/2; i >= 1; --i)
		Max_heap(A, i, len);
}
int main()
{
	int A[20], len;

    cout << "Enter size of array: ";
    cin  >> len;
    cout << "\nEnter the elements of array ---->\n";
    for(int i = 0; i < len; ++i)
        cin >> A[i];

    Build_maxheap(A, len-1);
	Heap_sort(A, len-1);

    cout << "\nSorted array ---->\n";
    for(int i = 0; i < len; ++i)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
