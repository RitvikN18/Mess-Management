#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <fstream>

using namespace std;

class Admin;
class User;
string timetable[7][3];
int options[21][2];
int q=0;
int price=0;
string username;
COORD coord={0,0};
void login();
void sign_admin();
void sign_user();
void sign_in();
void login();
void log_admin();
void in_admin();
void log_user();
void in_user();
void mainscreen();
int password(string);
void gotoxy(int,int);
int random();
char *to_str(int);

char *to_str(int num) //converts a number to string
{
    char* st=new char[3];
    st[1]=num%10+'0';
    num=num/10;
    st[0]=num%10+'0';
    st[2]='\0';
    return st;
}

int random() // generates a random number between 1 and 100
{
    return (rand()%100);
}

int password(string password) // function to check id if the entered password is correct or wrong
{
    char a;
    string p;
    int i=0;
    cout<<"Enter Password :";
    while(1)
    {
    a=_getch();
    if(a=='\r')
    {
        break;
    }
    else if(a=='\b' && i>=1)
    {
        cout<<"\b \b";
        i--;
    }
    else
    {
        cout<<"*";
        p.push_back(a);
        i++;
    }
    }
    if(p==password)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class Base
{
public:
    Base()
    {
    timetable[0][0]="Bread Jam";
    timetable[0][1]="Dal Fry,Aloo Bhujia";
    timetable[0][2]="Soyabean Aloo Masala";
    timetable[1][0]="Upma";
    timetable[1][1]="Jeera Rice";
    timetable[1][2]="Jeera Aloo";
    timetable[2][0]="Idly";
    timetable[2][1]="Chicken Kassa";
    timetable[2][2]="Veg Tadka";
    timetable[3][0]="Bara";
    timetable[3][1]="Bhindi Masala";
    timetable[3][2]="Puri";
    timetable[4][0]="Chowmin";
    timetable[4][1]="Chicken Curry";
    timetable[4][2]="Egg Curry";
    timetable[5][0]="Aloo Sandwich";
    timetable[5][1]="Veg Biryani";
    timetable[5][2]="Aloo Curry";
    timetable[6][0]="Uttapam";
    timetable[6][1]="Fish Curry";
    timetable[6][2]="Chilli Chicken";
    }
void v_timetable() //function displays timetable
{
    system("cls");
    gotoxy(35,3);
    int offset=12;
    gotoxy(39,3);
    cout<<"BREAKFAST";
    gotoxy(56,3);
    cout<<"LUNCH";
    gotoxy(83,3);
    cout<<"DINNER";
    gotoxy(110,3);
    cout<<"SPECIAL";
    gotoxy(27,6);
    cout<<"MONDAY";
    gotoxy(27,9);
    cout<<"TUESDAY";
    gotoxy(27,12);
    cout<<"WEDNESDAY";
    gotoxy(27,15);
    cout<<"THURSDAY";
    gotoxy(27,18);
    cout<<"FRIDAY";
    gotoxy(27,21);
    cout<<"SATURDAY";
    gotoxy(27,24);
    cout<<"SUNDAY";
    gotoxy(39,6);
    cout<<timetable[0][0];
    gotoxy(56,6);
    cout<<timetable[0][1];
    gotoxy(83,6);
    cout<<timetable[0][2];
    gotoxy(39,9);
    cout<<timetable[1][0];
    gotoxy(56,9);
    cout<<timetable[1][1];
    gotoxy(83,9);
    cout<<timetable[1][2];
    gotoxy(39,12);
    cout<<timetable[2][0];
    gotoxy(56,12);
    cout<<timetable[2][1];
    gotoxy(83,12);
    cout<<timetable[2][2];
    gotoxy(39,15);
    cout<<timetable[3][0];
    gotoxy(56,15);
    cout<<timetable[3][1];
    gotoxy(83,15);
    cout<<timetable[3][2];
    gotoxy(39,18);
    cout<<timetable[4][0];
    gotoxy(56,18);
    cout<<timetable[4][1];
    gotoxy(83,18);
    cout<<timetable[4][2];
    gotoxy(39,21);
    cout<<timetable[5][0];
    gotoxy(56,21);
    cout<<timetable[5][1];
    gotoxy(83,21);
    cout<<timetable[5][2];
    gotoxy(39,24);
    cout<<timetable[6][0];
    gotoxy(56,24);
    cout<<timetable[6][1];
    gotoxy(83,24);
    cout<<timetable[6][2];
    gotoxy(110,11);
    cout<<"PANNER ";
    gotoxy(110,12);
    cout<<"CURRY ";
    gotoxy(110,13);
    cout<<"or ";
    gotoxy(110,14);
    cout<<"CHICKEN";
    gotoxy(110,15);
    cout<<"CURRY";
    _getch();
}
virtual void put_username(string)=0;
virtual void put_password(string)=0;
virtual void init()=0;
virtual int check(string,string)=0;
};

class Admin : public Base
{
   string username;
   string password;
   public:
       void put_username(string in1)
       {
           username=in1;
       }
       void put_password(string in1)
       {
           password=in1;
       }
       void init()
       {
           ofstream fout;
           fout.open("AdminData.txt",ios::out|ios::app);
           fout<<username<<" "<<password<<endl;
           fout.close();
       }
       int check(string user,string pass)
       {
           string temp=user+" "+pass;
           string line;
           ifstream fin;
           fin.open("AdminData.txt");
           while(!fin.eof())
           {
               getline(fin,line);
               if(line==temp)
               {
                   return 1;
               }
           }
           return 0;
       }
        void c_timetable() //function to change timetable
       {
    system("cls");
    int option;
    int a,b;
    gotoxy(70,10);
    cout<<"Choose a day :";
    gotoxy(70,11);
    cout<<"1.Monday";
    gotoxy(70,12);
    cout<<"2.Tuesday";
    gotoxy(70,13);
    cout<<"3.Wednesday";
    gotoxy(70,14);
    cout<<"4.Thursday";
    gotoxy(70,15);
    cout<<"5.Friday";
    gotoxy(70,16);
    cout<<"6.Saturday";
    gotoxy(70,17);
    cout<<"7.Sunday";
    gotoxy(70,18);
    cout<<"8.Go back";
    cin>>option;
    if(option==8)
    {
        in_admin();
    }
    else
    {
    a=option-1;
    system("cls");
    gotoxy(70,10);
    cout<<"Choose the timing :";
    gotoxy(70,11);
    cout<<"1.Breakfast";
    gotoxy(70,12);
    cout<<"2.Lunch";
    gotoxy(70,13);
    cout<<"3.Dinner";
    cin>>option;
    b=option-1;
    system("cls");
    gotoxy(70,10);
    cout<<"Enter the changes :";
    cin>>timetable[a][b];
    }
    v_timetable();
}

};

class User : public Base
{
    string username;
    string password;
    public:
       void put_username(string in1)
       {
           username=in1;
       }
       void put_password(string in1)
       {
           password=in1;
       }
       void init()
       {
           ofstream fout;
           fout.open("UserData.txt",ios::out|ios::app);
           fout<<username<<" "<<password<<endl;
           fout.close();
       }
       int check(string user,string pass)
       {
           string temp=user+" "+pass;
           string line;
           ifstream fin;
           fin.open("UserData.txt");
           while(!fin.eof())
           {
               getline(fin,line);
               if(line==temp)
               {
                   return 1;
               }
           }
           return 0;
       }
       void book_coupons()
       {
    system("cls");
    int day,time,choice;
    gotoxy(70,11);
    cout<<"1.Monday";
    gotoxy(70,12);
    cout<<"2.Tuesday";
    gotoxy(70,13);
    cout<<"3.Wednesday";
    gotoxy(70,14);
    cout<<"4.Thursday";
    gotoxy(70,15);
    cout<<"5.Friday";
    gotoxy(70,16);
    cout<<"6.Saturday";
    gotoxy(70,17);
    cout<<"7.Sunday\n";
    gotoxy(70,10);
    cout<<"Which day do you want to book :";
    cin>>day;
    if(day>7 || day<1)
    {
        system("cls");
        gotoxy(70,10);
        cout<<"Incorrect option";
        _getch();
        book_coupons();
    }
    else{
    system("cls");
    gotoxy(70,11);
    cout<<"1.Breakfast";
    gotoxy(70,12);
    cout<<"2.Lunch";
    gotoxy(70,13);
    cout<<"3.Dinner";
    gotoxy(70,10);
    cout<<"Which coupon do you want to book :";
    cin>>time;
    int z=0;
    for(int i=0;i<q;i++)
    {
         if(options[i][0]==day && options[i][1]==time)
         {
                cout<<"This coupon is already booked!";
                z=1;
         }
    }
    if(z!=1)
    {
    if(time>3)
    {
        system("cls");
        gotoxy(70,10);
        cout<<"Incorrect option";
        _getch();
        book_coupons();
    }
    else{
    if(time==1)
    {
        price+=15;
    }
    else if(time==2 || time==3)
    {
        price+=30;
    }
    gotoxy(70,15);
    cout<<"YOUR COUPON IS BOOKED";
    gotoxy(70,16);
    cout<<"Click 1 to book another coupon :";
    cin>>choice;
    if(choice!=1)
    {
        ofstream fout;
        fout.open("CouponData.txt",ios::out|ios::app);
        fout<<username<<" "<<day<<time<<endl;
        fout.close();
    }
    if(choice==1)
    {
        ofstream fout;
        fout.open("CouponData.txt",ios::out|ios::app);
        fout<<username<<" "<<day<<time<<" ";
        fout.close();
    }
    options[q][0]=day;
    options[q][1]=time;
    q++;
    if(choice==1)
    {
        book_coupons();
    }
    }
    }
    }
}
       void view_coupons()
    {
    system("cls");
    cout<<"YOUR COUPONS :\n";
    for(int k=0;k<q;k++)
    {
        if(options[k][0]==1)
        {
            cout<<"Monday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]==2)
        {
            cout<<"Tuesday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]==3)
        {
            cout<<"Wednesday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]==4)
        {
            cout<<"Thursday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]==5)
        {
            cout<<"Friday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]==6)
        {
            cout<<"Saturday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]==7)
        {
            cout<<"Sunday ";
            if(options[k][1]==1)
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]==2)
            {
                cout<<"Lunch\n";
            }
            else if(options[k][1]==3)
            {
                cout<<"Dinner\n";
            }
        }
    }
    cout<<"Total Cost = "<<price<<"\n";
    /*ifstream fin;
    fin.open("CouponData.txt");
    while(!fin.eof())
    {
        getline(fin,line);
        int i=0;
        int l=1;
        while(line[i]!=' ')
        {
            if(username[i]==line[i])
            {
                continue;
            }
            else
            {
                l=0;
                break;
            }
        }
        if(l==1)
        {
        for(i=0;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        for(;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                options[j][0]==line[i+1];
                options[j][1]==line[i+2];
                i+=4;
                j+=1;
            }
        }
        }
        else
        {
            continue;
        }
    }
    for(int k=0;k<=j;k++)
    {
        if(options[k][0]=='1')
        {
            cout<<"Monday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch\n";
            }
            else if(options[k][2]=='3"Lunch\n""
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]=='2')
        {
            cout<<"Tuesday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch"<<endl;
            }
"Lunch\n"            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]=='3')
        {
            cout<<"Wednesday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch"<<endl;
            }
            else if(options[k][2]=='3"Lunch\n""
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]=='4')
        {
            cout<<"Thursday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch"<<endl;
            }
"Lunch\n"            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]=='5')
        {
            cout<<"Friday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch"<<endl;
            }
            else if(options[k][2]=='3')"Lunch\n"Lunch\n"Lunch\n""
            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]=='6')
        {
            cout<<"Saturday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch"<<endl;
            }
"Lunch\n"            {
                cout<<"Dinner\n";
            }
        }
        else if(options[k][0]=='7')
        {
            cout<<"Sunday ";
            if(options[k][1]=='1')
            {
                cout<<"Breakfast\n";
            }
            else if(options[k][1]=='2')
            {
                cout<<"Lunch"<<endl;
            }
            else if(options[k][2]=='3')
            {
                cout<<"Dinner\n";
            }
        }
    }*/
}
       void edit_coupons()
       {
           system("cls");
           gotoxy(70,10);
           cout<<"Which coupon do you want to delete :";
           gotoxy(70,11);
           cout<<"1.Monday";
           gotoxy(70,12);
           cout<<"2.Tuesday";
           gotoxy(70,13);
           cout<<"3.Wednesday";
           gotoxy(70,14);
           cout<<"4.Thursday";
           gotoxy(70,15);
           cout<<"5.Friday";
           gotoxy(70,16);
           cout<<"6.Saturday";
           gotoxy(70,17);
           cout<<"7.Sunday";
           int day;
           cin>>day;
           system("cls");
           gotoxy(70,10);
           cout<<"Which coupon do you want to delete :";
           gotoxy(70,11);
           cout<<"1.Breakfast";
           gotoxy(70,12);
           cout<<"2.Lunch";
           gotoxy(70,13);
           cout<<"3.Dinner";
           int time;
           cin>>time;
           for(int k=0;k<q;k++)
           {
               if(options[k][0]==day && options[k][1]==time)
               {
                   if(time==1)
                   {
                       price=price-15;
                   }
                   else if(time==2)
                   {
                       price=price-30;
                   }
                   else if(time==3)
                   {
                       price=price-30;
                   }
                   options[k][0]=8;
                   options[k][1]=4;
               }
           }
           in_user();
       }
};

void sign_in()
{
    system("CLS");
    gotoxy(70,10);
    cout<<"1. Sign in as Administrator";
    gotoxy(70,11);
    cout<<"2. Sign in as User";
    gotoxy(70,12);
    int option;
    cin>>option;
    if(option==1)
    {
        sign_admin();
    }
    else if(option==2)
    {
        sign_user();
    }
    else
    {
        cout<<"Enter valid input"<<flush;
        system("CLS");
    gotoxy(70,10);
    cout<<"1. Sign in as Administrator";
    gotoxy(70,11);
    cout<<"2. Sign in as User";
    gotoxy(70,12);
    int option2;
    cin>>option2;
    if(option2==1)
    {
        sign_admin();
    }
    else if(option2==2)
    {
        sign_user();
    }
    }
}

void login()
{
    system("CLS");
    int option;
    gotoxy(70,10);
    cout<<"1. Login as Administrator";
    gotoxy(70,11);
    cout<<"2. Login as User";
    gotoxy(70,12);
    cin>>option;
    if(option==1)
    {
        log_admin();
    }
    else if(option==2)
    {
        log_user();
    }
    else
    {
        cout<<"Enter valid option"<<flush;
            system("CLS");
    gotoxy(70,10);
    cout<<"1. Login as Administrator";
    gotoxy(70,11);
    cout<<"2. Login as User";
    gotoxy(70,12);
    int option1;
    cin>>option1;
        if(option1==1)
    {
        log_admin();
    }
    else if(option1==2)
    {
        log_user();
    }
    }
}

void sign_admin()
{
    system("CLS");
    gotoxy(70,10);
    string temp,temp1;
    Admin ad1;
    Admin *ad=&ad1;
    cout<<"Enter your name : ";
    cin>>temp;
    int in=random();
    string abc=to_str(in);
    temp=temp+abc;
    ad->put_username(temp);
    gotoxy(70,11);
    cout<<"Create password : ";
    char a;
    int i=0;
    temp1="";
    while(1)
    {
    a=_getch();
    if(a=='\r')
    {
        break;
    }
    else if(a=='\b' && i>=1)
    {
        cout<<"\b \b";
        i--;
    }
    else
    {
        cout<<"*";
        temp1.push_back(a);
        i++;
    }
    }
    ad->put_password(temp1);
    ad->init();
    gotoxy(70,13);
    cout<<"Your username is "<<temp;
    gotoxy(70,15);
    cout<<"You are now a member:D";
    _getch();
    system("cls");
    login();
}

void sign_user()
{
    system("CLS");
    gotoxy(70,10);
    string temp;
    User us1;
    User *ad=&us1;
    cout<<"Enter your name : ";
    cin>>temp;
    int in=random();
    string abc=to_str(in);
    temp=temp+abc;
    ad->put_username(temp);
    gotoxy(70,11);
    cout<<"Create password : ";
    char a;
    int i=0;
    string temp1="";
    while(1)
    {
    a=_getch();
    if(a=='\r')
    {
        break;
    }
    else if(a=='\b' && i>=1)
    {
        cout<<"\b \b";
        i--;
    }
    else
    {
        cout<<"*";
        temp1.push_back(a);
        i++;
    }
    }
    ad->put_password(temp1);
    ad->init();
    gotoxy(70,13);
    cout<<"Your username is "<<temp;
    gotoxy(70,15);
    cout<<"You are now a member:D";
    _getch();
    system("cls");
    login();
}

void log_admin()
{
    system("CLS");
    gotoxy(70,10);
    string temp,username,password;
    Admin ad1;
    Admin *ad=&ad1;
    cout<<"Enter Username : ";
    cin>>temp;
    username=temp;
    gotoxy(70,11);
    cout<<"Enter password : ";
    char a;
    int i=0;
    temp="";
    while(1)
    {
    a=_getch();
    if(a=='\r')
    {
        break;
    }
    else if(a=='\b' && i>=1)
    {
        cout<<"\b \b";
        i--;
    }
    else
    {
        cout<<"*";
        temp.push_back(a);
        i++;
    }
    }
    password=temp;
    if(ad->check(username,password))
    {
        cout<<"Yes";
        in_admin();
    }
    else
    {
        gotoxy(70,12);
        cout<<"INVALID CREDENTIALS";
        _getch();
        system("cls");
    }
}

void in_admin()
{
    system("cls");
    Admin ad1;
    Admin *A=&ad1;
    int choice;
    gotoxy(70,10);
    cout<<"1. View Timetable";
    gotoxy(70,11);
    cout<<"2. Change Timetable";
    gotoxy(70,12);
    cout<<"3. Exit";
    cin>>choice;
    if(choice==1)
    {
        A->v_timetable();
        in_admin();
    }
    else if(choice==2)
    {
        A->c_timetable();
        in_admin();
    }
    else
    {
        system("cls");
        _getch();
    }
}

void log_user()
{
    system("CLS");
    gotoxy(70,10);
    string temp,password;
    User us;
    User *ad=&us;
    cout<<"Enter Username : ";
    cin>>temp;
    username=temp;
    gotoxy(70,11);
    cout<<"Enter password : ";
    char a;
    int i=0;
    temp="";
    while(1)
    {
    a=_getch();
    if(a=='\r')
    {
        break;
    }
    else if(a=='\b' && i>=1)
    {
        cout<<"\b \b";
        i--;
    }
    else
    {
        cout<<"*";
        temp.push_back(a);
        i++;
    }
    }
    password=temp;
    if(ad->check(username,password))
    {
        cout<<"Yes";
        in_user();
    }
    else
    {
        gotoxy(70,12);
        cout<<"INVALID CREDENTIALS";
        _getch();
        system("cls");
    }
}

void in_user()
{
    system("cls");
    User us;
    User *U=&us;
    int choice;
    gotoxy(70,10);
    cout<<"1. View Timetable";
    gotoxy(70,11);
    cout<<"2. Book coupons";
    gotoxy(70,12);
    cout<<"3. View coupons";
    gotoxy(70,13);
    cout<<"4. Edit coupons\n";
    gotoxy(70,14);
    cout<<"5. Exit";
    cin>>choice;
    if(choice==1)
    {
        int ch;
        U->v_timetable();
        gotoxy(70,26);
        cout<<"Enter 1 to go back :";
        cin>>ch;
        if(ch==1)
        {
            in_user();
        }
    }
    else if(choice==2)
    {
        int ch;
        U->book_coupons();
        gotoxy(70,26);
        cout<<"Enter 1 to go back :";
        cin>>ch;
        if(ch==1)
        {
            in_user();
        }
    }
    else if(choice==3)
    {
        int ch;
        U->view_coupons();
        gotoxy(70,26);
        cout<<"Enter 1 to go back :";
        cin>>ch;
        if(ch==1)
        {
            in_user();
        }
    }
    else if(choice==4)
    {
        U->edit_coupons();
    }
    else if(choice==5)
    {
        system("cls");
        _getch();
    }
}

void mainscreen()
{
    int a;
    gotoxy(76,8);
    cout<<"MESS MANAGEMENT";
    gotoxy(70,10);
    cout<<"1. Sign In";
    gotoxy(70,11);
    cout<<"2. Login";
    gotoxy(70,12);
    cin>>a;
    if(a==1 || a==2)
    {
    if(a==1)
    {
        sign_in();
    }
    else
    {
        login();
    }
    }
    else
    {
        cout<<"ENTER VALID INPUT :";
    }
}

int main()
{
    srand(time(0));
    mainscreen();
    return 0;
}
