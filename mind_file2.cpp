
#include "iostream"
#include "fstream"
#include "conio.h"

using namespace std;
int Eid=1;
class Employee
{
  private:
    int id;
    char name[40];
    int age;
    float height;
    char gender;

  public:
    void putdata();
    void getdata();
};


void Employee :: putdata()
{
  id=Eid++;
  cout<<"Enter the name : ";
  cin>>name;
  fflush(stdin);
  cout<<"Enter the age : ";
  cin>>age;
  cout<<"Enter the height : ";
  cin>>height;
  cout<<"Enter the gender : ";
  cin>>gender;
}

void Employee :: getdata()
{
  cout<<"id: " << id << endl;
  cout<<"Name: " << name << endl;
  cout<<"Age: " << age << endl;
  cout<<"Height: " << height <<endl;
  cout<<"Gender: " << gender <<endl;
  cout<<"*******************************"<<endl;
}


int main()
{
  ofstream bb1;
  bb1.open("human.txt", ios::out);

  if(bb1.is_open())
  {
    Employee ob1;
    char ch;
    do {
      ob1.putdata();
      cout<<"Do you Want To Insert more Data---press Y or N :";
      bb1.write( (char *) & ob1, sizeof(ob1));
      ch=getch();
      cout<<endl;
    } while(ch=='y'||ch=='Y');
    cout<<"Congrats!  Details of Human has successfully written to the file "<<endl<<"****************************************"<<endl;
    bb1.close();
  }
  else
  {
    cout<<"File not found"<<endl;
  }

  ifstream bb2;
  bb2.open("human.txt", ios::in);
  if(bb2.is_open())
  {
    Employee ob2;
    int i=1;
    cout<<" All details of the employees from the file : "<<endl;
    while(i++<=Eid)
    {
      bb2.read( (char *) & ob2, sizeof(ob2));
      ob2.getdata();
    }
    bb2.close();
  }
  else
  {
    cout<<"File is not found"<<endl;
  }

return 0;
}
