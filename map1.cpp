#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
#include<list>
#include <utility>
#include <stdexcept>
#include <exception> 
#include <set>
//try{...}
//cath(exception& ex){...ex.what()...} poprobovat'
using namespace std;
//unordered map
int alphabet(string &a, string &b)
{
    map <char,int> alph1;
    for(int i = 0; i < size(a); i++)
        alph1[a[i]]++;
    map <char,int> alph2;
    for(int i = 0; i < size(b); i++)
        alph2[b[i]]++;
    if( alph1 == alph2)
        return 1;
    return 0;

   /* map <char, int> :: iterator it = alph.begin();
    for (;it != alph.end(); it++)
        cout << it->first << " " << it->second << endl;*/
    
}

int main()
{
    int N = 0;
    cin >> N;
    string a,b;
    for(int i = 0; i < N; i++)
    {
        cin >> a >> b;
        if(alphabet(a,b))
            cout << "yes" << endl;
        else    
            cout << "no" << endl;
    }
}