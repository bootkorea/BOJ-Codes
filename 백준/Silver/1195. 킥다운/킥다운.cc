#include <bits/stdc++.h>
using namespace std;

string str1, str2;

int main()
{
    cin >> str1;
    cin >> str2;

    int len1 = str1.length(), len2 = str2.length(), minWidth = len1 + len2;
    if (len1 < len2)
    {
        swap(str1, str2);
        swap(len1, len2);
    }

    for (int shift = -len2 + 1; shift < len1; shift++)
    {
        bool valid = true;
        for (int i = 0; i < len2; i++)
        {
            int pos = shift + i;
            if (pos >= 0 && pos < len1 && str1[pos] == '2' && str2[i] == '2')
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            int width = max(len1, shift + len2) - min(0, shift);
            minWidth = min(minWidth, width);
        }
    }

    cout << minWidth;

    return 0;
}