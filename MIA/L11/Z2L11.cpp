#include<iostream>
using namespace std;
long long odddivs(long long number)
{
    long long score=0,div=3;
    while(div*div<number)
    {
        if(number%div==0)
        {
            score++;
        }
        div+=2;
    }
    return score;
}
long long GOD(long long number)
{
    if(number%2 == 1)
        return number;
    while(!(number%2==1))
        number/=2;
    return number;
}
int main()
{
    long long n, number;
    cin>>n;
    for(int i = 0; i < n ;i++)
    {
        cin>> number;
        bool first = true;
        while(number>1)
        {
            if(number==2)
            {
                //cout<<number<<" if a\n";
                number--;
                first=!first;
            }
            else if(number%2==0 && (number/2)%2==1)
            {
                //trzeba podzielić przez licbę nieparzystą tylko jaką?
                first!=first;
            }
            else if(GOD(number)>1)
            {
                //cout<<number<<" if b\n";
                number/=GOD(number);
                first=!first;
            }
            else
            {
                //cout<<number<<" if c\n";
                number--;
                first=!first;
            }
            
        }
        if(first)
        {
            cout<<"FastestFinger\n";
        }
        else
        {
            cout<<"Ashishgup\n";
        }
    }
    return 0;
}
/*if(number==1)//1st player has no moves and loses by default
        {
            cout<<"FastestFinger\n";
        }
        else if(number%2)//1st player always divides number by itself
        {
            cout<<"Ashishgup\n";
        }
        else if(odddivs(number)%2==1)
        {
            cout<<"\n";
        }
        else
        {
            cout<<"\n";
        }*/