#include <iostream>
#include <limits.h>

using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(i, *((bracket+i*n)+j), n, bracket, name);
    printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    cout << ")";
}

int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n], bracket[n][n], j, q;

    for (int i = 1; i < n; ++i)
        m[i][i] = 0;

    for (int L = 2; L < n; ++L)
    {
        for (int i = 1; i < n-L+1; ++i)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j-1; ++k)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "\nOptimal Parenthesization is: ";
    printParenthesis(1, n-1, n, (int *)bracket, name);

    return m[1][n-1];

}

int main()
{
    int num;
    cout << "Enter number of matrices: ";
    cin  >> num;

    num++;

    int arr[num];

    cout << "\nEnter dimensions of matrices ---->\n";

    for(int i = 0; i < num; ++i)
    {
        cout << "Dimension P" << i << ": ";
        cin  >> arr[i];
    }

    int size = sizeof(arr)/sizeof(arr[0]);

    cout <<"\nMinimum number of multiplications: " << MatrixChainMultiplication(arr, size);
    cout << endl;

    return 0;
}
