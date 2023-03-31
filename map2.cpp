#include <bits/stdc++.h>

using namespace std;

map <string,vector <string> > way;
map <string,vector <string> > stops;

void new_bus()
{
    string bus;
    cin >> bus;
    int stopcount = 0;
    cin >> stopcount;
    for(int i = 0; i < stopcount; i++)
    {
        string stop;
        cin >> stop;
        way[bus].push_back(stop);
        stops[stop].push_back(bus);
    }
    
}

void buses_for_stop()
{
    string stop;
    cin >> stop;
    if(!stops.count(stop))
    {
        cout << "No stop" << endl;
        return;
    }
    for( int i = 0; i < size(stops[stop]); i++)
        cout << stops[stop][i] << " ";
    cout << endl;

}

void stops_for_bus()
{
    string bus;
    cin >> bus;
    if(!way.count(bus))
    {
        cout << "No bus" << endl;
        return;
    }
    for(int i = 0; i < size(way[bus]); i++)
    {
        cout << "Stop " << way[bus][i] << ": ";
        if(size(stops[way[bus][i]]) == 1)
        {
            cout << "No interchange"<< endl;
            continue;
        }
        for( int j = 0; j < size(stops[way[bus][i]]); j++)
        {
            if(!(bus.compare( stops[ way[bus][i] ][j] ) ))
                continue;
            cout << stops[way[bus][i]][j] << " ";
        }
        cout << endl;
    }

}

void all_buses()
{   
    if(way.empty())
    {
        cout << "No buses" << endl;
        return;
    }
    map <string, vector<string> > :: iterator i = way.begin();
    for (;i != way.end(); i++)
    {
        cout << i->first << ": ";
        for(int j = 0; j < size(i->second); j++)
            cout << (i->second)[j] << " ";
        cout << endl;
    }

}

int main()
{
    int Q = 0;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        string a;
        cin >> a;
        if(a == "NEW_BUS")
            new_bus();
        if(a == "BUSES_FOR_STOP")
            buses_for_stop();
        if(a == "STOPS_FOR_BUS")
            stops_for_bus();
        if(a == "ALL_BUSES")
            all_buses();

    }

}

/*
12
NEW_BUS
1
3
aa bb cc
NEW_BUS
2
4
aa bb dd ee
NEW_BUS       
3
1
cc
NEW_BUS
4
2
bb cc
NEW_BUS
5
3
aa cc ee
*/