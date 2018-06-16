#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void menu();
class person
{
    int p_id;
    char fname[20], mname[20], lname[20];
    int age_ason_1Jan2000;
    char disability;
    char gender;
public:

    void enter_infilep()
    {
        person p;
            ofstream ofs("people.txt", ios :: app);
            ofs<<p_id<<'\t'<<fname<<'\t'<<mname<<'\t'<<lname<<'\t'<<age_ason_1Jan2000<<'\t'<<disability<<'\t'<<gender<<'\n';
            ofs.close();
    }
    void enter_newp()
    {
        char c;
        do
        {
        cout<<"Enter p_id:\n";
        cin>>p_id;
        cout<<"Enter name: <fname mname lname>\n";
        cin>>fname>>mname>>lname;
        cout<<"Enter age as on 1st January 2000\n";
        cin>>age_ason_1Jan2000;
        cout<<"Enter disability status:('n'->no;'s'->severe;)\n";
        cin>>disability;
        cout<<"Enter gender:('m'->male; 'f'->female)\n";
        cin>>gender;
        cout<<"Please enter the following information. Once entered, it cannot be updated.\n\n";
        displayp();

        cout<<"Is the above information correct?(y/n):\t";
        cin>>c;
        }while(c=='n');
        enter_infilep();
    }
    void displayp()
    {
        cout<<"ID:\t"<<p_id<<endl
            <<"First Name:\t"<<fname<<endl
            <<"Middle Name:\t"<<mname<<endl
            <<"Last Name:\t"<<lname<<endl
            <<"Age as on 1 January 2000:\t"<<age_ason_1Jan2000<<endl
            <<"Disability Status:('n'-> no; 's'->severe;)\t"<<disability<<endl
            <<"Gender:('m'->male; 'f'->female)\t"<<gender<<endl;
    }
    friend void cal_tax();
    friend person getp(int d);
};
person getp(int d)
    {
        person p;
        ifstream ifs("people.txt");
        int i=0;
        try
        {
        do
        {
            i++;
            ifs>>p.p_id>>p.fname>>p.mname>>p.lname>>p.age_ason_1Jan2000>>p.disability>>p.gender;

            if(i>99)
            {
                cout<<"Wrong p_id :(\n";
                throw 0;
            }

        }while(p.p_id != d);
        }
        catch(int a)
        {
            ifs.close();
            throw 0;
        }
        ifs.close();
        return p;
    }

class rules
{
    int fin_yr;
    float dedAm, dedBm;
    float dedCgm, dedCm;    //deduction for girlies
    float dedDsm, dedDm;    //deduction for seniors
    float dedEhm, dedEm;    //deduction for handicapped
    float b1, r1, b2, r2, b3, r3;
public:

    void enter_infiler()
    {
         rules r;
            ofstream ofs("rules.txt", ios :: app);
            ofs<<fin_yr<<'\t'<<dedAm<<'\t'<<dedBm<<'\t'<<dedCgm<<'\t'<<dedCm<<'\t'<<dedDsm<<'\t'<<dedDm<<'\t'<<dedEhm<<'\t'<<dedEm<<'\t'<<b1<<'\t'<<r1<<'\t'<<b2<<'\t'<<r2<<'\t'<<b3<<'\t'<<r3<<'\n';
            ofs.close();
    }
    void enter_newr()
    {
        char c;
        do
        {
        cout<<"Enter financial year:\n";
        cin>>fin_yr;
        cout<<"Enter max deduction of type A and type B, respectively:\n";
        cin>>dedAm>>dedBm;
        cout<<"Enter maximum deduction of type C for women and men, respectively\n";
        cin>>dedCgm>>dedCm;
        cout<<"Enter maximum dedution of type D for senior citizens and normal people, respectively\n";
        cin>>dedDsm>>dedDm;
        cout<<"Enter maximum dedution of type E for disabled and healthy citizens, respectively\n";
        cin>>dedEhm>>dedEm;
        cout<<"Enter the brackets from and their rates respectively(all at once)<b1 r1 b2 r2 b3 r3>\n";
        cin>>b1>>r1>>b2>>r2>>b3>>r3;
        cout<<"Please enter the following information. Once entered, it cannot be updated.\n\n";
        displayr();

        cout<<"Is the above information correct?(y/n):\t";
        cin>>c;
        }while(c=='n');
        enter_infiler();
    }
    void displayr()
    {
        cout<<"financial year:\t"<<fin_yr<<endl
            <<"dedAm:\t"<<dedAm<<endl
            <<"dedBm:\t"<<dedBm<<endl
            <<"dedCgm:\t"<<dedCgm<<endl
            <<"dedCm:\t"<<dedCm<<endl
            <<"dedDsm:\t"<<dedDsm<<endl
            <<"dedDm:\t"<<dedDm<<endl
            <<"dedEhm:\t"<<dedEhm<<endl
            <<"dedEm:\t"<<dedEm<<endl
            <<"b1 r1:\t"<<b1<<'\t'<<r1<<endl
            <<"b2 r2:\t"<<b2<<'\t'<<r2<<endl
            <<"b3 r3:\t"<<b3<<'\t'<<r3<<endl;
    }
    friend rules getr(int d);
    friend void cal_tax();
};
rules getr(int d)
    {
        rules r;
        ifstream ifs("rules.txt");
        int i=0;
        try
        {
        do
        {
            i++;
            ifs>>r.fin_yr>>r.dedAm>>r.dedBm>>r.dedCgm>>r.dedCm>>r.dedDsm>>r.dedDm>>r.dedEhm>>r.dedEm>>r.b1>>r.r1>>r.b2>>r.r2>>r.b3>>r.r3;

            if(i>99)
            {
                cout<<"No entries for this year yet :(\n";
                throw 0;
            }

        }while(r.fin_yr != d);
        }
        catch(int a)
        {
            ifs.close();
            throw 0;
        }
        ifs.close();
        return r;
    }


int verify()
{
    int i=0,k=0;
    char pw[20], check[20], ch, c;
    ifstream ifs("password.txt");

    while(ifs.get(c))
        pw[k++]=c;
    pw[k]='\0';

    ifs.close();

    cout<<"Enter Password:\t";
    do
    {
        ch=getch();
        check[i++]=ch;
        cout<<'*';
    }while(ch!='\t');
    check[i]='\0';
    system("cls");
    if(!strcmp(pw, check))
        return 1;
    return 0;
}
void new_pw()
{
    int i=0;
    char a[50], b[50], ch;
    cout<<"Enter new Password:\t";
    do
    {
        ch=getch();
        a[i++]=ch;
        cout<<'*';
    }while(ch!='\t');
    a[i]='\0';
        cout<<"Re-nter new Password:\t";
    i=0;
    do
    {
        ch=getch();
        b[i++]=ch;
        cout<<'*';
    }while(ch!='\t');
    b[i]='\0';
    if(!strcmp(a,b))
    {
        ofstream ofs("password.txt");
        ofs<<a;
        ofs.close();
        cout<<"\nNew password set!\n";
    }
    system("cls");
}
void cal_tax()
{

    person p;
    rules r;
    int fy, id;
    pid:
    cout<<"Enter p_id:\n";
    cin>>id;
    try
    {
        p=getp(id);
    }
    catch(int n)
    {
        cout<<"No person with such id\nTry enter a person first.(Enter 'm' to goto main menu;'t' to try again)\n";
        char ch;
        cin>>ch;
        switch(ch)
        {
        case 'm':
            menu();
            break;
        case 't':
            goto pid;
            break;
        default:
            menu();
        }
    }
    finyr:
    cout<<"Enter fin_yr:\n";
    cin>>fy;
    try
    {
        r=getr(fy);
    }
    catch(int n)
    {
        cout<<"The rules for this financial year have not been defined yet\nRequest your administrator to enter the rules first.(Enter 'm' to goto main menu;'t' to try again)\n";
        char ch;
        cin>>ch;
        switch(ch)
        {
        case 'm':
            menu();
            break;
        case 't':
            goto finyr;
            break;
        default:
            menu();
        }
    }
    float tot_income, tds, taxable_income, tax=0, tax_payable;
    float dedAc, dedBc, dedCc, dedDc, dedEc;
    float ltg, stg;
    cout<<"You are about to calculate the tax for:\n\n";
    p.displayp();
    cout<<"\n\nUnder the following rules:\n\n";
    r.displayr();
    cout<<"\n\nEnter (y/n) to continue:\t";
    char ch;
    ch=getch();
    if(ch!='y')
        goto pid;
    system("cls");
    cout<<"Enter the total income(excluding equity gains):\n";
    cin>>tot_income;
    cout<<"Enter LTG:\n";
    cin>>ltg;
    cout<<"Enter STG:\n";
    cin>>stg;
    cout<<"Enter tds (if any):\n";
    cin>>tds;
    cout<<"Enter deductions claimed of type A, B, C, D and E(respectively):\n";
    cin>>dedAc>>dedBc>>dedCc>>dedDc>>dedEc;
    dedAc=dedAc>r.dedAm?r.dedAm:dedAc;
    dedBc=dedBc>r.dedBm?r.dedBm:dedBc;
    if(p.gender=='f')
        dedCc=dedCc>r.dedCgm?r.dedCgm:dedCc;
    else
        dedCc=dedCc>r.dedCm?r.dedCm:dedCc;
    if(p.age_ason_1Jan2000+r.fin_yr-2000>60)
        dedDc=dedDc>r.dedDsm?r.dedDsm:dedDc;
    else
        dedDc=dedDc>r.dedDm?r.dedDm:dedDc;
    if(p.disability=='s')
        dedEc=dedEc>r.dedEhm?r.dedEhm:dedEc;
    else
        dedEc=dedEc>r.dedEm?r.dedEm:dedEc;
tot_income +=stg;
taxable_income = tot_income - (dedAc+dedBc+dedCc+dedDc+dedEc);
if(taxable_income<r.b1)
        tax=0;
else if(taxable_income <r.b2)
    tax+=(taxable_income-r.b1)*r.r1/100;
else if(taxable_income <r.b3)
{
    tax+=(r.b2-r.b1)*r.r1/100;
    tax+=(taxable_income-r.b2)*r.r2/100;
}
else
{
    tax+=(r.b2-r.b1)*r.r1/100;
    tax+=(r.b3-r.b2)*r.r2/100;
    tax+=(taxable_income-r.b3)*r.r3/100;
}
tax_payable = tax-tds;
if(tax_payable < 0)
    tax_payable =0;
system("cls");
cout<<"Transaction details:\n\n";
cout<<"p_id:\t"<<p.p_id<<endl
    <<"fincial year:\t"<<r.fin_yr<<endl
    <<"STG:\t"<<stg<<endl
    <<"LTG:\t"<<ltg<<endl
    <<"Income Declared:\t"<<tot_income<<endl
    <<"TDS paid:\t"<<tds<<endl
    <<"deduction A:\t"<<dedAc<<endl
    <<"deduction B:\t"<<dedBc<<endl
    <<"deduction C:\t"<<dedCc<<endl
    <<"deduction D:\t"<<dedDc<<endl
    <<"deduction E:\t"<<dedEc<<endl
    <<"taxable income:\t"<<taxable_income<<endl
    <<"Tax:\t"<<tax<<endl
    <<"tax payable:\t"<<tax_payable<<endl;
ofstream ofs("taxlogs.txt", ios::app);
ofs<<p.p_id<<'\t'<<r.fin_yr<<'\t'<<tot_income<<'\t'<<tds<<'\t'<<taxable_income<<'\t'<<tax<<'\t'<<dedAc<<'\t'<<dedBc<<'\t'<<dedCc<<'\t'<<dedDc<<'\t'<<dedEc<<'\t'<<taxable_income<<'\t'<<tax<<'\t'<<tax_payable<<endl;
ofs.close();
}

void menu()
{
    menu:
    system("cls");
    cout<<"\t\t\t=====MENU=====\n"
        <<"\t\t\t1. Enter new person\n"
        <<"\t\t\t2. Enter rules for a new year(admin)\n"
        <<"\t\t\t3. Calculate taxes\n"
        <<"\t\t\t4. Change Administrator password(admin)\n"
        <<"\t\t\t5. Display all people(admin)\n"
        <<"\t\t\t6. Display all rules\n"
        <<"\t\t\t7. Display tax details(admin)\n"
        <<"\t\t\t8. Exit\n";
    int a,i;
    a=getch()-48;
    system("cls");
    switch(a)
    {
    case 1:
        person p;
        p.enter_newp();
        cout<<"\n\n\nPress any key to got to menu\n";
        getch();
        goto menu;
        break;
    case 2:
        i=verify();

        if(i==1)
        {
            rules r;
            r.enter_newr();
            cout<<"\n\n\nPress any key to got to menu\n";
            getch();
            goto menu;
        }
        else
            goto menu;
        break;
    case 3:
        cal_tax();
        cout<<"\n\n\nPress any key to got to menu\n";
        getch();
        goto menu;
        break;
    case 4:

        if(verify())
            new_pw();
        getch();
            goto menu;
        break;
    case 5:
        if(verify())
        {
            system("cls");
            cout<<"p_id\tfname\tmname\t\tlname\tAgeIn2k disab sex\n\n";
            char c;
            ifstream ifs("people.txt");
            while(ifs.get(c))
                cout<<c;
            ifs.close();
            cout<<"\n\n\nPress any key to got to menu\n";
            getch();
            goto menu;
        }
        else
            goto menu;
        break;
    case 6:
        if(1)
        {
            system("cls");
            cout<<"fin_yr  dedAm   dedBm  dedCgm   dedCm   dedDsm   dedDm   dedDhm   dedHm   b1\tr1\tb2\tr2\tb3\tr3\n\n";
            char c;
            ifstream ifs("rules.txt");
            while(ifs.get(c))
                cout<<c;
            ifs.close();
            cout<<"\n\n\nPress any key to got to menu\n";
            getch();
            goto menu;
        }
        else
            goto menu;
        break;
    case 7:
        if(verify())
            {
                system("cls");
                cout<<"\nP_ID\tfin_yr\tTotalIncome\tTDS\tdedA\tdedB\tdedC\tdedD\tdedE\ttaxable_income\tTax\tTax_payable\n\n";
                ifstream ifs("taxlogs.txt");
                char c;
                while(ifs.get(c))
                    cout<<c;
                ifs.close();
                cout<<"\n\n\nPress any key to got to menu\n";
                getch();
                goto menu;
            }
        else
            goto menu;
        break;
    case 8:
        exit(0);
    default:
        cout<<"Incorrect choice\n";
        goto menu;
    }
}

main()
{
    cout<<"Hello!\n\n\tThis program is made to help in Income Tax Management!\n\nPress any key for Main Menu!";
    getch();
    menu:
    system("cls");
    menu();
}
