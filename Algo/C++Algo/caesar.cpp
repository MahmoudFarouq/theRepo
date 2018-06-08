#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    std::string omar;
    cout<<"insert your word to encrypt it ";
    std::getline (std::cin,omar);
    cout<<omar;
    cout<<"\n";
    string alphabet;
    alphabet="abcdefghijklmnopqrstuvwxyz";
    cout<<"insert your encryption shift number ";
    int x = 0;
    cin>>x;
    int i = 0,j=0;
    string encrypted=omar;
    for(j=0;j<=omar.length();j++)
    {
      int z=0;
      cout<<omar[j];
    for(i=0;i<=25;i++)
    {
      //cout<<alphabet[i];
      if(alphabet[i]==omar[j])
      {if((i+x)>25)
        {
        z=i+x-25;  
        encrypted[j]=alphabet[z];
        }
      else
      {
        z=i+x;
        cout<<"\t";
        cout<<z;
        cout<<"\t";
        encrypted[j]=alphabet[z];
        cout<<alphabet[z];
        cout<<"\t";
        cout<<omar[j];
        cout<<"\t";
        cout<<alphabet[i];
        cout<<"\t";
        cout<<encrypted[j];
        cout<<"\t";
        cout<<"\n";
      }
      break;
      }
    }
    }
    cout<<encrypted;
    cout<<"\t";
    cout<<omar;
}
