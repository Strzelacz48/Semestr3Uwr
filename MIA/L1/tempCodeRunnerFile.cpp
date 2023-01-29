plen--;
    nplen--;
    cout<<"test";
    sort(tabp,tabp+plen);
    sort(tabnp,tabnp+nplen);
    long long pom1=plen-1;
    long long pom2=nplen-1;
    long long sum1=sum;
    while(pom1>0 && pom2>0)
    {
        if(lastodd)
        {
            sum1-=tabp[pom1];
            pom1--;
        }
        else
        {
            sum1-=tabnp[pom2];
            pom2--;
        }
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
    }
    if(sum1<sum)
        cout<<sum1;
    else
        cout<<sum;
    return 0;