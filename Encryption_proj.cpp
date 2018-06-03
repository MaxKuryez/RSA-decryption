#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


int Extended_alg(int, int);

int Power_mod_n(long int, int, int);

char translate(int);

int factoring(int);


int main()
{

    ifstream fin("C:\\Users\\Maxim\\Desktop\\Encrypt_proj_Kuryez_Maksim\\RSA.txt");

    int e,n,p1,p2;

    fin >>n;
    fin >>e;

    p1=factoring(n);
    p2=n/p1;

    int Fi=(p1-1)*(p2-1);
    int d=Extended_alg(e,Fi);


    long int a;
    while (fin >> a )
    {
        a=Power_mod_n(a,d,n);
        char ch=translate(a);
        cout<<ch;
    }
    return 0;
}

//****factoring numbers****


int factoring(int n)
{
    int i=2,p1;
    while (true)
    {
        if (n%i==0)
        {
            p1=i;
            break;
        }
        i++;
    }
    return p1;
}


//*****extended algorithm to find inverse of e*******


int Extended_alg(int a, int n)
{
    int n_1,a_1,tmp,rem_1=1,rem_2=-1,row=0;
    if (a<n)
    {
        tmp=a;
        a=n;
        n=tmp;
    }
    n_1=n;
    a_1=a;
    vector<int> Mult;
    while (true)
    {
        Mult.push_back(n/a);
        tmp=n%a;
        n=a;
        a=tmp;
        if (a==1||a==0)
            break;
    }
    if (a==0)
    {
        n_1=n_1/n;
        a_1=a_1/n;
        Mult.pop_back();
    }
    if (Mult.size()%2==1)
        row=1;
    rem_2=rem_2*Mult[Mult.size()-1];
    Mult.pop_back();
    if (Mult.size()>=1)
        while (true)
        {
            rem_1=(rem_1-rem_2*Mult[Mult.size()-1]);
            Mult.pop_back();
            if (Mult.size()==0)
                break;
            rem_2=(rem_2-rem_1*Mult[Mult.size()-1]);
            Mult.pop_back();
            if (Mult.size()==0)
                break;
        }
    if (row==1)
    {
        tmp=rem_1;
        rem_1=rem_2;
        rem_2=tmp;
    }
    if (rem_1<0)
        while(rem_1<0)
            rem_1=rem_1+n_1;
    if (rem_2<0)
        while(rem_2<0)
            rem_2=rem_2+a_1;
    rem_1=rem_1%n_1;
    rem_2=rem_2%a_1;
    return rem_2;
}


//********counting power with respect to modulo n******


int Power_mod_n(long int a, int b, int n)
{
    int c=1;
    for (int i=0; i<b; i++)
    {
        c=(c*a)%n;
    }
    return c;
}


//******mapping numbers and alphabet******



char translate(int a)
{
    ifstream fin("C:\\Users\\Maxim\\Desktop\\Encrypt_proj_Kuryez_Maksim\\alphabet.txt");
    int num;
    char a_1,ch;
    while (num !=a)
        {fin >> num;
        fin >> a_1;
        }
    if (num==96)
        a_1=' ';
    return a_1;
}
