#include <iostream>
#include <vector>

using namespace std;

void Gaus(unsigned n, vector<vector<double>> a, float b[])
{
	unsigned i, j, line, prev_line = 1;
	int k, g = 0;
	float d;

	for (j = 0; j < n; j++)
		for (i = g; i < n; i++)
			if (a[i][j] != 0)
			{
				line = i; 
				unsigned flag;

				if (prev_line != line)
					flag = 0;
				else
					flag = 1;

				if (flag == 0) 
				{
					prev_line = line;
					d = a[i][j];

					for (k = j; k < n; k++)
						a[i][k] /= d; 

					b[i] /= d;
					g = i;

					for (k = 0; k < n; k++)
						for (int w = 0; w < n; w++)
						{
							float buf = a[k][w]; 
								if ((w == j) && (k != g))
								{
									int p = k; int c = w;
									a[p][c] = buf; 

									for (c = w; c < n; c++)
										a[p][c] -= buf * a[g][c];

									b[k] -= buf * b[i];
								}
						}
					i = n; 
				}
			}
}