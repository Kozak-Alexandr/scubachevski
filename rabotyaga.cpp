#include <bits/stdc++.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


using namespace std;

class worker {
    private:
        string name;
        int salary;
        int age;
        ofstream &f_out;

    public:
        worker(string name_, int salary_, int age_, ofstream &f_out_) : name(name_), salary(salary_), age(age_), f_out(f_out_) 
        {
            f_out << setfill('.');
        };

        int get_salary()
        {
            return salary;
        }

        string get_name()
        {
            return name;
        }

        void DoWork()
        {
            salary--;
            if (salary == 100) 
                throw underflow_error ("Broke");

            // /*
            char buf[1024];
            sprintf(buf, "%s..........%d..........%d\n", &name[0], age, salary);
            f_out << string(buf);
            // */

            //f_out << name  << setw(10) << age << setw(10) << salary << endl;

        }
};

void thread_funk(class worker* wrk)
{
    while (wrk->get_salary() > 100) 
    {
        try 
        {
            wrk->DoWork();
        }
        catch (underflow_error &ex) {
            cout << wrk->get_name() << " is hired!\n";
        }
    }
}

int main()
{
    ofstream f_out("output.txt");

    int n = 5;

    vector <class worker> v;
    for(int i = 0; i < n; i++)
        v.push_back(worker(string("rabotyaga").append(to_string(i)), 110 + i * 50, i+20, f_out)); //string("rabotyaga").append(to_string(i)
    
    vector <thread> th;
    for(int i = 0; i < n; i++)
    {
        th.push_back(thread(thread_funk, &v[i]));
    }

    for(int i = 0; i < n; i++)
    {
        th[i].join();
    }

}

