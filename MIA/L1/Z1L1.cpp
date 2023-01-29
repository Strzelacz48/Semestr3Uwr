#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long input,plen=0,nplen=0;
    long long tabp[2000];
    long long tabnp[2000];
    long long sum=0;
    //long long tabremoved[n];
    ////cout<<"test\n";
    for(int i=0; i<n; i++)
    {
        cin>>input;
        ////cout<<"\ntest : "<<i<<" "<<input;
        if(input%2==0)
        {
            ////cout<<" parzysta\n";
            tabp[plen]=input;
            plen++;
            ////cout<<"koniec";
        }
        else
        {
            ////cout<<" nieparzysta\n";
            tabnp[nplen]=input;
            nplen++;
            ////cout<<"koniec";
        }
        sum+=input;
    }
    plen--;
    nplen--;
    ////cout<<"test";
    sort(tabp,tabp+plen+1);
    sort(tabnp,tabnp+nplen+1);
    long long pom1=plen;
    long long pom2=nplen;
    long long sum1=sum;
    for(int i=0; i<n; i++)
    {
        //cout<<"\ntabp["<<i<<"] : "<<tabp[i];
        //cout<<"\ntabnp["<<i<<"] : "<<tabnp[i];
    }
    bool lastodd=false;
    while(pom1 >= 0 && pom2 >= 0)
    {
        //cout<<"\nwhile";
        if(lastodd)
        {
            //cout<<"\ntabp[pom1] : "<<tabp[pom1];
            sum1-=tabp[pom1];
            pom1--;
        }
        else
        {
            //cout<<"\ntabnp[pom2] : "<<tabnp[pom2];
            sum1-=tabnp[pom2];
            pom2--;
        }
        lastodd=!lastodd;
        //cout<<"\nsum1 : "<<sum1;
    }
    if(pom1<0 && lastodd==false)
    {
        sum1-=tabnp[pom2];
        pom2--;
    }
    else if(pom2<0 && lastodd==true)
    {
        sum1-=tabp[pom1];
        pom1--;
    }
    lastodd=true;
    while(plen >= 0 && nplen >= 0)
    {
        //cout<<"\nwhile2";
        if(lastodd)
        {
            //cout<<"\ntabp[plen] : "<<tabp[plen];
            sum-=tabp[plen];
            plen--;
        }
        else
        {
            //cout<<"\ntabnp[nplen] : "<<tabnp[nplen];
            sum-=tabnp[nplen];
            nplen--;
        }
        lastodd=!lastodd;
        //cout<<"\nsum : "<<sum;
    }
    if(plen<0 && lastodd==false)
    {
        sum-=tabnp[nplen];
        nplen--;
    }
    else if(nplen<0 && lastodd==true)
    {
        sum1-=tabp[plen];
        plen--;
    }
    if(sum1 < sum)
        cout<<sum1;
    else
        cout<<sum;
    return 0;
}
/*while(pom1>0 && pom2>0)
    {
        if(lastodd)
        {
            //cout<<"\ntabp[pom1] : "<<tabp[pom1];
            sum1-=tabp[pom1];
            pom1--;
        }
        else
        {
            //cout<<"\ntabnp[pom2] : "<<tabnp[pom2];
            sum1-=tabnp[pom2];
            pom2--;
        }
        lastodd=!lastodd;
    }
    lastodd=true;
    while(plen>0 && nplen>0)
    {
        if(lastodd)
        {
            sum-=tabp[pom1];
            pom1--;
        }
        else
        {
            sum-=tabnp[pom2];
            pom2--;
        }
        lastodd=!lastodd;
    }
    */