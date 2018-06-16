#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
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
            ofs<<fin_yr<<'\t'<<dedAm<<'\t'<<dedBm<<'\t'<<dedCgm<<'\t'<<dedCm<<'\t'<<dedDsm<<'\t'<<dedDm<<'\t'<<dedEhm<<'\t'<<dedEm<<b1<<'\t'<<r1<<'\t'<<b2<<'\t'<<r2<<'\t'<<b3<<'\t'<<r3<<'\n';
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




main()
{
    rules p, g;
    //p.enter_newr();
    try{

    g= getr(2000);
    g.displayr();
    }
    catch(int a)
    {
        cout<<"no id matches\n";
    }

}
