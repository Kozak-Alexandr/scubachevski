#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdexcept>
#include <exception>
// #include <operator>
/*
Class rational
Есть поля числитель и знаменатель
1) конструктор написать: если дробь сократима, сократить (нод); знаменатель не может быть отрицательным - если отрицательный умножить числитель и знаменатель на -1; знам не ноль (если ноль, то throw exception() прям в конструкторе

2) перегрузить +,-,*,/,=,==,<,>,«, »,++r,r++
*/
using namespace std;

class rational
{
    public:
        int a;
        int b;

        int NOD(int a_, int b_)
        {
            while(a_!=0 and b_!=0)
                if(a_>b_)
                    a_=a_%b_;
                else 
                    b_=b_%a_;
            return (a_+b_);
        }

    //public:

        //friend istream& operator>>(istream&,rational&);
		//friend ostream& operator<<(ostream&,const fract&);

         void simple()
        {
            int NOD_ = NOD(a,b);
            a = a/NOD_;
            b = b/NOD_;
            if(b < 0){
                a = -a;
                b = -b;
            }
             else if(a<0 && b<0)
            {
                a = -a;
                b = -b;
            }
        
        }
        rational(int a_, int b_)  //constructor
        {
            if(b_ == 0){
                throw std::overflow_error("error");
                return;
            }
           
            a = a_;
            b = b_;
            simple();
        }
        void print()
        {
            std::cout<< a << '/' << b << std::endl;
        }

        rational operator + (rational r)
        {
            int b_ = this->b * r.b;
            int a_ = this->a * r.b + r.a * this->b;
            return rational(a_, b_);
        }

        rational operator - (rational r)
        {
            int b_ = this->b * r.b;
            int a_ = this->a * r.b - r.a * this->b;
            return rational(a_, b_);
        }

        rational operator * (rational r)
        {
            int b_ = this->b * r.b;
            int a_ = this->a * r.a;
            return rational(a_, b_);
        }

        rational operator / (rational r)
        {
            int b_ = this->b * r.a;
            int a_ = this->a * r.b;
            return rational(a_, b_);
        }

        rational& operator ++ ()
        {
            *this = *this + *this;
            return *this;
        }

        rational operator ++ (int)
        {
            rational prev = *this;
            *this = *this + *this;
            return prev;
        }
        
        rational& operator = (rational r)
        {
            this->a = r.a;
            this->b = r.b;
            return *this;
        }

        bool operator == (rational r)
        {
            if(this->a == r.a && this->b == r.b)
                return true;
            else 
                return false;
        }

         bool operator > (rational r)
        {
            if(this->a * r.b > r.a * this->b)
                return true;
            else 
                return false;
        }

         bool operator < (rational r)
        {
            if(this->a * r.b < r.a * this->b)
                return true;
            else 
                return false;
        }

        
  
};

istream& operator>>(istream& next, rational& r)
{
    return next >> r.a >> r.b;
}

istream& operator<<(istream& next,rational& r){
	return next >> r.a >> r.b;
}



int main()
{
    //throw exception();
    rational rat (-1, -47);
    //std::cin << rat;
    rational ratt(1, 3);
    rational rattt(1, 1);
    rattt = rat + ratt;
    //rattt++;
    //++rattt;
    //rattt = rat * ratt;
    rattt.print();

    std::cout << "\n";
    int a1 = 5;
    int a2 = 5;
    int i1 = 1;
    int i2 = 1;
    a1 = i1++;
    a2 = ++i2;
    a1 = (a1 = 3);
    std::cout << a1 << " " << a2 << "\n";
    return 0;
}