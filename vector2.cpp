#include <iostream>
#include <vector>
#include <string>

void my_reverse(std::vector <int> &w);

int main()
{
    std::vector<int> v = {7, 5, 16, 8};

    my_reverse(v);
    for(int i = 0; i < 4; i++)
        std::cout << v[i] << " ";
}

void my_reverse(std::vector <int> &w)
{
    int n = std::size(w);
    for(int i = 0; i < n/2; i++)
        std::swap(w[i], w[n -i -1]);
}