#include <iostream>
#include <fstream>

int lenghtFromTime(int,int);

int main()
{
    const char nrOfRaces=4;
    int inputNums[nrOfRaces][2]={};
    std::fstream fileHandle("../input6.txt",std::ios::in);
    for(char i=0; i<2; ++i)
    {
        for(char ii=0; ii<nrOfRaces; ++ii)
        {
            std::string temp;
            fileHandle>>temp;
            inputNums[ii][i]=stoi(temp);
        }
    }
    int result=1;
    for(char i=0; i<nrOfRaces; ++i)
    {
        int possible=0;
        // std::cout<<inputNums[i][0]<<"\t"<<inputNums[i][1]<<"\n";
        for(int ii=inputNums[i][0]/2; ii>-1; ii--)
        {
            if(lenghtFromTime(ii,inputNums[i][0]-ii)>inputNums[i][1])
            {
                // std::cout<<lenghtFromTime(ii,inputNums[i][0]-ii)<<"\t"<<inputNums[i][1]<<"\n";
                possible++;
            }
            else
            {
                break;
            }
        }
        possible*=2;
        possible-=(int)!(bool)(inputNums[i][0]%2);
        result*=possible;
        std::cout<<possible<<'\t'<<result<<"\n";
    }
    return 0;
}

int lenghtFromTime(int timeOfPressing, int restOfTime)
{
    return timeOfPressing*restOfTime; //as velocity equals time of pressing, by multiplying it with rest of time lasted, we get strecke
}