#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n = 0;              
    std::cin >> n;
    int sum = 0;
    std::vector<int> s(n);

    for(int i = 0; i < n; i++)
    {
        std::cin >> s[i];
    }
    for(int j = 0; j < n; j++)
    {
        sum += s[j];
    }
    for(int k = 0; k < n; k++)
    {
        if (s[k] > sum/n)
        {
            std::cout << s[k];
        }
    }
}