#include <iostream>
using namespace std;

int main()
{

    int p[] = {10, 20, 30, 40};
    int n = 3;

    int m[4][4];

    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            int k = i;

            m[i][j] = m[i][k]
                    + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

            if (i == 1 && j == 3)
            {
                cout << "A1 x A2 x A3" << endl;
                cout << "k = 1 : " << m[i][j] << endl;
            }

            for (k = i + 1; k < j; k++)
            {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (i == 1 && j == 3)
                {
                    cout << "k = " << k
                         << " : " << cost << endl;
                }

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << endl;

    cout << "m[1][2] (A1 x A2) = "
         << m[1][2] << endl;

    cout << "m[2][3] (A2 x A3) = "
         << m[2][3] << endl;

    cout << "m[1][3] (A1 x A2 x A3) = "
         << m[1][3] << endl;

    cout << endl;

    cout << "Minimum value = "
         << m[1][3] << endl;

    return 0;
}
