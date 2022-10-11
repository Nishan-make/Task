#include "iostream"
#include "fstream"
#include "conio.h"
using namespace std;

int main()
{
  cout<<"Nishan is trying to find your word from the file :"<<endl;
  cout<<"*********************************************************"<<endl;
  int count;
  string s;
  char ch;
  do {
      ifstream go;
      go.open("myfile.txt");
      if(go.is_open())
      {
        count=0;
        string text;
        cout<<"Enter the text you want to find :";
        cin>>text;
        fflush(stdin);
        while(go>>s)
        {
          if(s==text)
          {
            count++;
          }
        }
        if(count>0)
        {
          cout<<"entered text is found "<<count<<" times"<<endl;
        }
        else
        {
          cout<<"sorry...Not found"<<endl;
        }
        cout<<"******************************************************************"<<endl;
        cout<<"Do you Want To take another try?---then press Y otherwise press any key."<<endl;
        ch=getch();
        go.close();
      }
    }while(ch=='y'||ch=='Y');


  return 0;
}
