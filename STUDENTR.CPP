#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
class student
{
int rollno;
char name[50];
int p_marks,c_marks,m_marks,cs_marks,e_marks;
float per;
char grade;
void calculate();
public:
void getdata();
void showdata();
void show_tabular();
int retrollno();
};
void student::calculate()
{
per=(p_marks+c_marks+m_marks+cs_marks+e_marks)/5;
if(per>=89.99)
grade='A1';
else if(per>=79.99)
grade='A2';
else if(per>=69.99)
grade='B1';
else if(per>=59.99)
grade='B2';
else if(per>=49.99)
grade='C1';
else if(per>=39.99)
grade='C2';
else if(per>=31.99)
grade='D';
else if(per>=19.99)
grade='E1';
else if(per>=0)
grade='E2';
}
void student::getdata()
{
cout<<"\n Enter the Roll Number of the Student: \t";
cin>>rollno;
cout<<"\n Enter the Name of the Student: \t";
gets(name);
cout<<"\n\n\t\t All the Marks are out of 100.";
cout<<"\n Enter the Marks in Physics: \t";
cin>>p_marks;
cout<<"\n Enter the Marks in Chemistry: \t";
cin>>c_marks;
cout<<"\n Enter the Marks in Mathematics: \t";
cin>>m_marks;
cout<<"\n Enter the Marks in Computer Science : \t";
cin>>cs_marks;
cout<<"\n Enter the Marks in English: \t";
cin>>e_marks;
calculate();
}
void student::showdata()
{
cout<<"\n Roll Number of Student: \t"<<rollno;
cout<<"\n Name of Student: \t"<<name;
cout<<"\n Marks in Physics: \t"<<p_marks;
cout<<"\n Marks in Chemistry: \t"<<c_marks;
cout<<"\n Marks in Mathematics: \t"<<m_marks;
cout<<"\n Marks in Computer Science: \t"<<cs_marks;
cout<<"\n Marks in English: \t"<<e_marks;
cout<<"\n Percentage of Student: \t"<<per;
cout<<"\n Grade of Student: \t"<<grade;
}
void student::show_tabular()
{
cout<<rollno<<setw(6)<<"\t"<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)<<cs_marks<<setw(4)<<e_marks<<setw(6)<<per<<setw(6)<<"\t"<<grade<<endl;
}
int student::retrollno()
{
return rollno;
}
void write_student();
void display_all();
void display_sp(int);
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();
int main()
{
char ch;
cout.setf(ios::fixed|ios::showpoint);
cout<<setprecision(2);
clrscr();
intro();
do
{
clrscr();
cout<<"\n\n\t\t\ MAIN MENU";
cout<<"\n\t 1. RESULT MENU";
cout<<"\n\t 2. ENTRY/EDIT MENU";
cout<<"\n\t 3. EXIT";
cout<<"\n\t Please Select your Option: \t";
cin>>ch;
clrscr();
switch(ch)
{
case '1':
result();
break;
case '2':
entry_menu();
break;
case '3':
exit(0);
break;
default:
cout<<"\a";
}
}
while(ch!='3');
return 0;
}
void write_student()
{
student st;
ofstream f1;
f1.open("student.dat",ios::binary|ios::app);
st.getdata();
f1.write((char*)&st,sizeof(student));
f1.close();
cout<<"\n Student Record has been Created.";
cin.ignore();
getch();
}
void display_all()
{
student st;
ifstream f2;
f2.open("student.dat",ios::binary);
if(!f2)
{
cout<<"\n File does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
return;
}
cout<<"\n\n\t\t DISPLAY ALL RECORDS !!! \n\n";
while(f2.read((char*)&st,sizeof(student)))
{
st.showdata();
cout<<"\n\n==================\n";
}
f2.close();
getch();
}
void display_sp(int n)
{
student st;
ifstream f2;
f2.open("student.dat",ios::binary);
if(!f2)
{
cout<<"\n File does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
return;
}
int flag=0;
while(f2.read((char*)&st,sizeof(student)))
{
if(st.retrollno()==n)
{
st.showdata();
flag=1;
}
}
f2.close();
if(flag==0)
cout<<"\n File does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
}
void modify_student(int n)
{
int found=0;
student st;
fstream f;
f.open("student.dat",ios::binary|ios::in|ios::out);
if(!f)
{
cout<<"\n File does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
return ;
}
while(f.read((char*)&st,sizeof(student))&&found==0)
{
if(st.retrollno()==n)
{
st.showdata();
cout<<"\n Please Enter the New Details of the Student:"<<endl;
st.getdata();
int pos=(-1)*sizeof(st);
f.seekp(pos,ios::cur);
f.write((char*)&st,sizeof(student));
cout<<"\n\t RECORD UPDATED !!!";
found=1;
}
}
f.close();
if(found==0)
cout<<"\n Record does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
}
void delete_student(int n)
{
student st;
ifstream f2;
f2.open("student.dat",ios::binary);
if(!f2)
{
cout<<"\n File does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
return;
}
ofstream f1;
f1.open("Temp.dat",ios::out);
f2.seekg(0,ios::beg);
while(f2.read((char*)&st,sizeof(student)))
{
if(st.retrollno()!=n)
{
f1.write((char*)&st,sizeof(student));
}
}
f1.close();
f2.close();
remove("student.dat");
rename("Temp.dat","student.dat");
cout<<"\n RECORD DELETED !!!";
getch();
}
void class_result()
{
student st;
ifstream f2;
f2.open("student.dat",ios::binary);
if(!f2)
{
cout<<"\n File does not EXIST..!!!";
cout<<"\n Press any key to continue.";
getch();
return;
}
cout<<"\n\n\t\t ALL STUDENTS' RESULTS !!!";
cout<<"===================================================\n";
cout<<"R.No.    Name    P  C  M  CS  E  Percentage  Grade"<endl;
cout<<"===================================================\n";
while(f2.read((char*)&st,sizeof(student)))
{
st.show_tabular();
}
getch();
f2.close();
}
void result()
{
char ch;
int rno;
cout<<"\n\n\t\t RESULT MENU";
cout<<"\n\t 1. CLASS RESULT";
cout<<"\n\t 2. STUDENT REPORT CARD";
cout<<"\n\t 3. BACK TO MAIN MENU";
cout<<"\n\t Enter your Choice \t";
cin>>ch;
switch(ch)
{
case '1':
class_result();
break;
case '2':
cout<<"\n Enter the Roll Number of the Student: \t";
cin>>rno;
display_sp(rno);
break;
case '3':
exit(0);
break;
default:
cout<<"\a";
}
}
void intro()
{
cout<<"\n\t STUDENT REPORT CARD AND DATA MANAGEMENT OF STUDENT DETAILS";
cout<<"\n Name: Santosh";
cout<<"\n Std/Div: XII/A";
cout<<"\n School: Kola Perumal Chetty Vaishnav Senior Secondary School";
getch();
}
void entry_menu()
{
char ch;
int num;
clrscr();
cout<<"\n\n\t\t ENTRY MENU";
cout<<"\n\t 1. CREATE STUDENT RECORD";
cout<<"\n\t 2. DISPLAY ALL STUDENTS' RECORDS";
cout<<"\n\t 3. SEARCH STUDENT RECORD";
cout<<"\n\t 4. MODIFY STUDENT RECORD";
cout<<"\n\t 5. DELETE STUDENT RECORD";
cout<<"\n\t 6. BACK TO MAIN MENU";
cout<<"\n\t Please Enter your Choice: \t";
cin>>ch;
switch(ch)
{
case '1':
write_student();
break;
case '2':
display_all();
break;
case '3':
cout<<"\n Enter the Roll Number of the Student: \t";
cin>>num;
display_sp(num);
break;
case '4':
cout<<"\n Enter the Roll Number of the Student: \t";
cin>>num;
modify_student(num);
break;
case '5':
cout<<"\n Enter the Roll Number of the Student: \t";
cin>>num;
delete_student(num);
break;
case '6':
exit(0);
break;
default:
cout<<"\a";
entry_menu();
}
}

