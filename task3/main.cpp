#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <dirent.h>
#include <Windows.h>

using namespace std;

int main(int argc,char *argv[])
{
SetCurrentDirectory(argv[1]);
char adress1[]="Cash1.txt";
char adress2[]="Cash2.txt";
char adress3[]="Cash3.txt";
char adress4[]="Cash4.txt";
char adress5[]="Cash5.txt";
char buff[100];
double double_buff;
double buff1=0;
int index;
double time[16];
int file_not_open_counter=0;

ifstream cash1;
cash1.open(adress1);
if(cash1.is_open())
{
    for(int i=0;i<16;i++)
    {
        cash1>>buff;
        double_buff=atof(buff);
        time[i]+=double_buff;
    }
}
else
{
    cout<<"file Cash1.txt is not open"<<'\n';
    file_not_open_counter++;
}
cash1.close();

ifstream cash2;
cash2.open(adress2);
if(cash2.is_open())
{
    for(int i=0;i<16;i++)
    {
        cash2>>buff;
        double_buff=atof(buff);
        time[i]+=double_buff;
    }
}
else
{
    cout<<"file Cash2.txt is not open"<<'\n';
    file_not_open_counter++;
}
cash2.close();

ifstream cash3;
cash3.open(adress3);
if(cash1.is_open())
{
    for(int i=0;i<16;i++)
    {
        cash3>>buff;
        double_buff=atof(buff);
        time[i]+=double_buff;
    }
}
else
{
    cout<<"file Cash3.txt is not open"<<'\n';
    file_not_open_counter++;
}
cash3.close();

ifstream cash4;
cash4.open(adress4);
if(cash1.is_open())
{
    for(int i=0;i<16;i++)
    {
        cash4>>buff;
        double_buff=atof(buff);
        time[i]+=double_buff;
    }
}
else
{
    cout<<"file Cash4.txt is not open"<<'\n';
    file_not_open_counter++;
}
cash4.close();


ifstream cash5;
cash5.open(adress5);
if(cash1.is_open())
{
    for(int i=0;i<16;i++)
    {
        cash5>>buff;
        double_buff=atof(buff);
        time[i]+=double_buff;
    }
}
else
{
    cout<<"file Cash5.txt is not open"<<'\n';
    file_not_open_counter++;
}
cash5.close();
if(file_not_open_counter==0)
{
for(int i=0;i<16;i++)
{
    if(time[i]>buff1)
    {
        buff1=time[i];
        index=i;
    }
}
cout<<index+1<<'\n';
}
return 0;
}
