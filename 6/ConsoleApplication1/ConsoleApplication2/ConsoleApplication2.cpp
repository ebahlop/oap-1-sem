#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    vector <int> del;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (find(del.begin(), del.end(), i) == end(del))
            {
                cout << i;
                del.push_back(i);
                if (i != n / i)
                    del.push_back(n / i);
            }
        }
    }
    sort(del.begin(), del.end());
    for (int i = 0; i < del.size(); i++)
        cout << del[i] << " ";
    return 0;
}