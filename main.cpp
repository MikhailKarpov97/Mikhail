#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <cmath>
using namespace std;
double epsilon=0.0001;
double PI=3.14159256;

int main(int argc,char *argv[])
{
double points_4[4][2];
double current_point[2];
double current_vector[2];
double next_vector[2];
double bet_angle;
double angle_sum;
double vec_sum;
double sqrt1;
double sqrt2;
int exit_counter=0;
ifstream file1;
file1.open(argv[1]);
if(file1.is_open())
{
    for(int i=0;i<4;i++)
    {
        file1>>points_4[i][0]>>points_4[i][1];
    }
}
else
    cout<<"file_1 not open"<<'\n';
file1.close();
ifstream file2;
file2.open(argv[2]);
if(file2.is_open())
{
    while(!file2.eof())
    {
        exit_counter=0;
        file2>>current_point[0]>>current_point[1];
        angle_sum=0;
        for(int i=0;i<4;i++)
        {
            current_vector[0]=current_point[0]-points_4[i][0];
            current_vector[1]=current_point[1]-points_4[i][1];
            if((current_vector[0]==0)&&(current_vector[1]==0))
            {
                cout<<"0"<<'\n';
                exit_counter++;
            }
            else
            {
                if(i<3)
                {
                    next_vector[0]=current_point[0]-points_4[i+1][0];
                    next_vector[1]=current_point[1]-points_4[i+1][1];
                }
                else
                {
                    next_vector[0]=current_point[0]-points_4[0][0];
                    next_vector[1]=current_point[1]-points_4[0][1];
                }

                sqrt1=sqrt(current_vector[0]*current_vector[0]+current_vector[1]*current_vector[1]);
                sqrt2=sqrt(next_vector[0]*next_vector[0]+next_vector[1]*next_vector[1]);
                vec_sum=current_vector[0]*next_vector[0]+current_vector[1]*next_vector[1];

                bet_angle=acos(vec_sum/(sqrt1*sqrt2));

                if((PI-bet_angle)<=epsilon)
                {
                    cout<<"1"<<'\n';
                    exit_counter++;
                }
                else
                {
                    angle_sum+=bet_angle;
                }
            }
        }
        if(exit_counter==0)
        {
            if(((2*PI-angle_sum)<=epsilon))
                cout<<"2"<<'\n';
            else
                cout<<"3"<<'\n';
        }
    }
}
else
    cout<<"file_2 not open"<<'\n';
file2.close();
return 0;
}
