#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <iomanip>

using namespace std;
vector<double> arr;
void per90(int counter);
void mediane(int counter);
void minimum();
void maximum(int counter);
void middle(int counter);

int main(int argc, char* argv[])
{
int counter=0;
arr.reserve(1000);
double buff;
ifstream file;
file.open(argv[1]);
if (file.is_open())
{
    while(!file.eof())
    {
    file>>buff;
    arr[counter]=buff;
    counter++;
    }
for(int i=0;i<counter;i++)
    for(int k=i;k<counter;k++)
        if (arr[k]<arr[i])
        {
            double buf=arr[i];
            arr[i]=arr[k];
            arr[k]=buf;
        }
per90(counter);
mediane(counter);
minimum();
maximum(counter);
middle(counter);
}
else
    cout<<"file is not open"<<'\n';
return 0;
}

void per90(int counter)
{
double per;
per=arr[(90*(counter-1)/100)];
cout<<setprecision(2)<<fixed<<per<<'\n';
}

void mediane(int counter)
{
double me;
int N=(counter+1)/2;
if ((N%2)==0)
    me=(arr[N]+arr[N+1])/2;
else
    me=arr[N];
cout<<setprecision(2)<<fixed<<me<<'\n';
}

void minimum()
{
cout<<setprecision(2)<<fixed<<arr[0]<<'\n';
}

void maximum(int counter)
{
double a;
a=arr[counter-1];
cout<<setprecision(2)<<fixed<<a<<'\n';
}

void middle(int counter)
{
double sum=0;
for(int i=0;i<counter;i++)
        sum+=arr[i];
sum=sum/(counter);
cout<<setprecision(2)<<fixed<<sum<<'\n';
}
