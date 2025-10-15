#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(int a[], int n, int m)
{
    sort(a, a + n);

    int i = 0;
    int j = m - 1;

    int mini = INT_MAX;
    while (j < n)
    {
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }

    return mini;
}

int main()
{

    int chocolate[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int n = 8, m = 5;

    cout << chocolateDistribution(chocolate, n, m);

    return 0;
}