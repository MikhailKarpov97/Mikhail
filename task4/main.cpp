#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include <vector>

using namespace std;

int main(int argc,char *argv[])
{
int h1;
int h2;
int h3;
int h4;
char s1;
char s2;
int current_hour;
int current_minute;
int current_client=0;
int current_client_max=0;
int moment_current_client=0;
int start_counter=0;
int counter=0;
int hour_start;
int minute_start;
int hour_end;
int minute_end;
vector<int>input_hour(1);
vector<int>output_hour(1);
vector<int>input_minute(1);
vector<int>output_minute(1);
ifstream file;
file.open(argv[1]);
if(file.is_open())
{
    while(!file.eof())
    {
        file>>h1>>s1>>h2>>h3>>s2>>h4;
        input_hour[counter]=h1;
        output_hour[counter]=h3;
        input_minute[counter]=h2;
        output_minute[counter]=h4;
        input_hour.push_back(1);
        output_hour.push_back(1);
        input_minute.push_back(1);
        output_minute.push_back(1);
        counter++;
    }
    file.close();

    for(current_hour=8;current_hour<20;current_hour++)
    {
        for(current_minute=0;current_minute<60;current_minute++)
        {
            for(int i=0;i<counter;i++)
            {
                if ((input_hour[i]==current_hour)&&(input_minute[i]==current_minute))
                {
                    current_client++;
                }
                if ((output_hour[i]==current_hour)&&(output_minute[i]==current_minute))
                {
                    current_client--;
                }
            }
            if (current_client>current_client_max)
            {
            current_client_max=current_client;
            }
        }
    }
    current_client=0;
    for(current_hour=8;current_hour<20;current_hour++)
    {
        for(current_minute=0;current_minute<60;current_minute++)
        {
            moment_current_client=0;
            for(int i=0;i<counter;i++)
            {
                if ((input_hour[i]==current_hour)&&(input_minute[i]==current_minute))
                {
                    moment_current_client++;
                }
                if ((output_hour[i]==current_hour)&&(output_minute[i]==current_minute))
                {
                    moment_current_client--;
                }
            }
            if(moment_current_client!=0)
            {
                current_client+=moment_current_client;
                if((current_client==current_client_max)&&(start_counter==0))
                {
                    hour_start=current_hour;
                    minute_start=current_minute;
                    start_counter=1;
                }
                if((current_client-moment_current_client)==current_client_max)
                {
                    start_counter=0;
                    hour_end=current_hour;
                    minute_end=current_minute;
                    if((minute_start>=10)&&(minute_end>=10))
                        cout<<hour_start<<":"<<minute_start<<" "<<hour_end<<":"<<minute_end<<'\n';
                    if((minute_start<10)&&(minute_end>=10))
                        cout<<hour_start<<":0"<<minute_start<<" "<<hour_end<<":"<<minute_end<<'\n';
                    if((minute_start>=10)&&(minute_end<10))
                        cout<<hour_start<<":"<<minute_start<<" "<<hour_end<<":0"<<minute_end<<'\n';
                    if((minute_start<10)&&(minute_end<10))
                        cout<<hour_start<<":0"<<minute_start<<" "<<hour_end<<":0"<<minute_end<<'\n';
                }
            }
        }
    }
}
else
    cout<<"file is not open"<<'\n';
}

