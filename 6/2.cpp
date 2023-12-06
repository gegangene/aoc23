#include <iostream>
#include <fstream>

long lenghtFromTime(long,long);

int main()
{
    const char nrOfRaces=4;
    long inputNums[2]={};
    std::fstream fileHandle("../input6.txt",std::ios::in);
    for(char i=0; i<2; ++i)
    {
        std::string temp;
        std::string temp2;
        for(char ii=0; ii<nrOfRaces; ++ii)
        {
            fileHandle>>temp;
            temp2+=temp;
        }
        inputNums[i]=stol(temp2);
    }
    int possible=0;
    for(long i=inputNums[0]/2; i>-1; i--)
    {
        if(lenghtFromTime(i,inputNums[0]-i)>inputNums[1])
        {
            possible++;
        }
        else
        {
            break;
        }
    }
    possible*=2;
    possible-=(int)!(bool)(inputNums[0]%2);
    std::cout<<possible;
    return 0;
}

long lenghtFromTime(long timeOfPressing, long restOfTime)
{
    return timeOfPressing*restOfTime; //as velocity equals time of pressing, by multiplying it with rest of time lasted, we get strecke
}