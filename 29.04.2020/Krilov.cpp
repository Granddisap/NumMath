#include <iostream>
#include <vector>
#include "Gaus.h"

using namespace std;

int main()
{
    setlocale(0, "");

    vector<vector<double>> x, y;

    const unsigned n = 5;

    x = { { 5, 3, -1, -3, 4 },
     { -3, 2, 3, -5, -5 },
     { 0, -2, -2, -4, 5 },
     { -2, 1, 0, 1, 2 },
     { 4, 2, 0, -4, -4 } };

    y.resize(n);

    for (unsigned i = 0; i < n; i++)
        y[i].resize(n + 1);

    y[0][0] = 1;

    for (unsigned k = 0; k < n; k++)
        for (unsigned i = 0; i < n; i++)
            for (unsigned j = 0; j < n; j++)
                y[i][k + 1] += x[i][j] * y[j][k];

    cout << "y[0] .. y[" << n << "] " << endl;

    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n + 1; j++)
            cout << y[i][j] << "\t";
        cout << endl;
    }

    cout << endl;

    float b[] = { y[0][n], y[1][n], y[2][n], y[3][n], y[4][n] };
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            x[i][k] = y[i][j];
            k++;
        }
        k = 0;
    }

    Gaus(n, x, b);

    for (unsigned i = 0; i < n; i++)
        cout << "p[" << i << "]: " << b[i] << endl;

    cout << endl;
    system("pause");
    return 0;
}