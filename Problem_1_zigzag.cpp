#include <iostream>
#include <string>
#include <vector>
using namespace std;

int pro(int a[],int l)
{
    string t = "";
    for(int i=0;i<l-1;i++)
    {
        if(a[i+1]-a[i]>0)
        {
            t = t + 'x';
        }
        else if(a[i+1]-a[i]<0)
        {
            t = t+ 'y';
        }
    }
    cout<<t<<endl;
    int s = t.length();
    cout<<s<<endl;
    int num=0;
    char q = t[0];
    vector<char> v;
    v.push_back(t[0]);
    for(int i =1;i<s;i++)
    {
        if(v.back()!=t[i])
        {
           num++;
           v.push_back(t[i]);
        }

    }
    for(int i =0 ; i<v.size();i++)
    {

        cout<<v[i]<<" ";
    }
    cout<<endl;
    return v.size()+1;
}

int main()
{
    int n;
    cout<<"Enter no. of elemets"<<endl;
    cin>>n;
    cout<<"Enter Elements"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int x = pro(a,n);
    cout<<x<<endl;

}

