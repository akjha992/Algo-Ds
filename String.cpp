#include <bits/stdc++.h>

using namespace std;

vector<string> split(string &str, char token = ' ')
{
    vector<string> result;
    int i = 0, j = 0;
    while (i < str.size())
    {
        j = i;
        while (j < str.size() && str[j] != token)
            j++;
        result.push_back(str.substr(i, j - i));
        i = j + 1;
    }
    return result;
}

string next(string &line, char token = ' ')
{
    int i = 0;
    while (i < line.size() && line[i] != token)
        i++;
    string result = line.substr(0, i);
    line = i == line.size() ? "" : line.substr(i + 1);
    return result;
}

string add(string &num1, string &num2, int base = 10)
{
    string result = "";
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int res = carry + num1[i] - '0' + num2[j] - '0';
        carry = res / base;
        res = res % base;
        result.push_back('0' + res);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int res = carry + num1[i] - '0';
        carry = res / base;
        res = res % base;
        result.push_back('0' + res);
        i--;
    }
    while (j >= 0)
    {
        int res = carry + num2[j] - '0';
        carry = res / base;
        res = res % base;
        result.push_back('0' + res);
        j--;
    }
    if (carry)
        result.push_back('0' + carry);
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string str = "My*Name is Ashish";
    while (str.size() > 0)
    {
        cout << "[" << next(str,'*') << "]";
    }
}