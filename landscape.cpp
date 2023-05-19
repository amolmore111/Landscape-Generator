#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;

    while (cin >> N >> K)
    {
        vector<int> v1(N + 10);
        for (int i = 0; i < K; i++)
        {
            char ch;
            int X1, X2;
            cin >> ch >> X1 >> X2;
            if (ch == 'R' || ch == 'D')
            {
                v1[X1 - 1] += (ch == 'R' ? 1 : -1);
                v1[X1] -= (ch == 'R' ? 1 : -1);
                v1[X2] -= (ch == 'R' ? 1 : -1);
                v1[X2 + 1] += (ch == 'R' ? 1 : -1);
            }
            else
            {
                v1[X1 - 1] += (ch == 'H' ? 1 : -1);
                v1[(X2 + X1) / 2] -= (ch == 'H' ? 1 : -1);
                v1[(X2 + X1 + 1) / 2] -= (ch == 'H' ? 1 : -1);
                v1[X2 + 1] += (ch == 'H' ? 1 : -1);
            }
        }
        int x = 0, d = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            x += d;
            d += v1[i];
            if (i >= 1 && i <= N)
                cout << x << endl;
        }
    }
}
