#include <iostream>

using namespace std;

int main()
{
	int A[2][2], B[2][2], C[2][2];
	int S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
	int P1, P2, P3, P4, P5, P6, P7;

	cout << "Enter the 4 elements of 1st matrix ---->\n";
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			cin >> A[i][j];

    cout << endl;

	cout << "Enter the 4 elements of 2nd matrix ---->\n";
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			cin >> B[i][j];

    //Sum matrices.
    S1 = B[0][1] - B[1][1];
    S2 = A[0][0] + A[0][1];
    S3 = A[1][0] + A[1][1];
    S4 = B[1][0] - B[0][0];
    S5 = A[0][0] + A[1][1];
    S6 = B[0][0] + B[1][1];
    S7 = A[0][1] - A[1][1];
    S8 = B[1][0] + B[1][1];
    S9 = A[0][0] - A[1][0];
    S10 = B[0][0] - B[0][1];

	//Product matrices.
	P1 = A[0][0] * S1;
	P2 = S2 * B[1][1] ;
	P3 = S3 * B[0][0];
	P4 = A[1][1] * S4;
	P5 = S5 * S6;
	P6 = S7 * S8;
	P7 = S9 * S10;

	//Final matrix.
	C[0][0] = P5 + P4 - P2 + P6;
	C[0][1] = P1 + P2;
	C[1][0] = P3 + P4;
	C[1][1] = P5 + P1 - P3 - P7;

	cout << "\nMatrix multiplication by Strassen's algorithm ---->\n" ;
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
			cout << C[i][j] << " ";
        cout << endl;
	}

	return 0;
}
