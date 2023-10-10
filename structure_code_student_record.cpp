#include<iostream>
#include<string>

using namespace std;
struct student
{
    int  semester_completed, credit_completed;
    string unique_id;
    float cgpa;
};

int main()
{
    student s[10];
s[1].unique_id="22-35625-2";
s[1].semester_completed=4;
s[1].credit_completed=19;
s[1].cgpa=2.5;

s[2].unique_id="22-47336-2";
s[2].semester_completed=5;
s[2].credit_completed=42;
s[2].cgpa=4;

s[3].unique_id="22-23356-1";
s[3].semester_completed=4;
s[3].credit_completed=50;
s[3].cgpa=3.82;

s[4].unique_id="22-25356-3";
s[4].semester_completed=6;
s[4].credit_completed=10;
s[4].cgpa=3.5;

s[5].unique_id="20-22356-2";
s[5].semester_completed=10;
s[5].credit_completed=120;
s[5].cgpa=3.65;

s[6].unique_id="22-65356-9";
s[6].semester_completed=8;
s[6].credit_completed=100;
s[6].cgpa=3.94;

s[7].unique_id="22-14356-2";
s[7].semester_completed=4;
s[7].credit_completed=30;
s[7].cgpa=3.95;

s[8].unique_id="22-22356-3";
s[8].semester_completed=4;
s[8].credit_completed=26;
s[8].cgpa=4;

s[9].unique_id="22-23562-8";
s[9].semester_completed=4;
s[9].credit_completed=10;
s[9].cgpa=3.9;

s[10].unique_id="22-47337-2";
s[10].semester_completed=4;
s[10].credit_completed=41;
s[10].cgpa=3.52;

cout<<"\nScholarship students:\n";
for (int i=0;i<10; i++){
        if (s[i].cgpa >= 3.75){
            cout<<"student id :\n"<<s[i].unique_id<<endl;
        }

}
cout<<"\n  students completed more than 50 credit:\n";
for (int i=0;i<10; i++){
        if (s[i].credit_completed >= 50){
            cout<<"student id :\n"<< s[i].unique_id<<endl;
        }

}

cout<<"\n  students completed more than 28 credit and 2 semester:\n";
for (int i=0;i<10; i++){
        if (s[i].credit_completed >= 28 && s[i].semester_completed >=2 ){
            cout<<"student id :\n"<< s[i].unique_id<<endl;
        }

}



}


