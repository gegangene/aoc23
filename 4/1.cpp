#include <iostream>
#include <fstream>

bool isNumber(char);
int pow2(int);

int main()
{
	int result=0;
	std::ifstream fileHandle("../input4.txt");
	while(!fileHandle.eof())
	{
		std::string game;
		std::getline(fileHandle, game);
		std::string tempGameNo;
		int counter=0;
		while(!isNumber(game[counter]))
			counter++;
		while(isNumber(game[counter]))
			counter++;
		while(!isNumber(game[counter]))
			counter++;
		char card[10]={};
		int cardCounter=0;
		char chosen[25]={};
		int chosenCounter=0;
		for(counter; counter<game.length(); counter++)
		{
			if(cardCounter<10)
			{
				if(isNumber(game[counter]))
				{
					std::string numTempStr="";
					while(isNumber(game[counter]))
					{
						numTempStr+=game[counter];
						counter++;
					}
					// std::cout<<"|"<<numTempStr<<"|\n";
					card[cardCounter]=stoi(numTempStr);
					cardCounter++;
				}
			}
			if(chosenCounter<25)
			{
				if(isNumber(game[counter]))
				{
					std::string numTempStr="";
					while(isNumber(game[counter]))
					{
						numTempStr+=game[counter];
						counter++;
					}
					// std::cout<<"|"<<numTempStr<<"|\n";
					chosen[chosenCounter]=stoi(numTempStr);
					chosenCounter++;
				}
			}
		}
		int matches=0;
		for(int i=0; i<25; i++)
		{
			for(int ii=0; ii<10; ii++)
			{
				if(card[ii]==chosen[i])
					matches++;
			}
		}
		// std::cout<<matches<<"\n";
		result+=(matches>0)?pow2(matches-1):0;

		// while(!isNumber(game[counter]))
		// {
		// 	counter++;
		// }
		// while(isNumber(game[counter]))
		// {
		// 	tempGameNo+=game[counter];
		// 	counter++;
		// }
		// std::cout<<tempGameNo<<"\n";
	}
	std::cout<<result;
	return 0;
}

bool isNumber(char input)
{
	if(input>47 && input<58)
	{
		return true;
	}
	return false;
}

int pow2(int input)
{
	int axa=1;
	for(int i=0; i<input; i++)
	{
		axa*=2;
	}
	return axa;
}