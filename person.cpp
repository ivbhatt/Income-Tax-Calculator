#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
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




main()
{
    person p, g;
    //p.enter_newp();
    try{

    g= getp(8);
    g.displayp();
    }
    catch(int a)
    {
        cout<<"no id matches\n";
    }

}

