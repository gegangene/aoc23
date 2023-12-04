#include <iostream>
#include <fstream>

bool isNumber(char);
int pow2(int);

int main()
{
    const int noOfGames=220;
    const int numbersOnCards=10;
    const int numbersToChoose=25;
	int result=0;
    int cardsObtained[noOfGames]={};

	std::ifstream fileHandle("../input4.txt");
	while(!fileHandle.eof())
	{
		std::string game;
		std::getline(fileHandle, game);

		std::string tempGameNo;
		int counter=0;

		while(!isNumber(game[counter]))
		{
			counter++;
		}
		while(isNumber(game[counter]))
		{
			tempGameNo+=game[counter];
			counter++;
		}
        int gameNo = stoi(tempGameNo)-1;

        cardsObtained[gameNo]++;

		while(!isNumber(game[counter]))
			counter++;

		char card[numbersOnCards]={};
		int cardCounter=0;
		char chosen[numbersToChoose]={};
		int chosenCounter=0;
		for(counter; counter<game.length(); counter++)
		{
			if(cardCounter<numbersOnCards)
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
			if(chosenCounter<24)
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
		for(int i=0; i<24; i++)
		{
			for(int ii=0; ii<numbersOnCards; ii++)
			{
				if(card[ii]==chosen[i])
					matches++;
			}
		}
		// std::cout<<matches<<"\n";
        for(int i=gameNo+1; i<=matches+gameNo; i++)//przypisac ilosc wygranych i przeiterowac do kolejnych kart przez gameno
        {
            cardsObtained[i]+=cardsObtained[gameNo];
            if(gameNo>200)
                std::cout<<gameNo+1<<'\t'<<matches<<'\t'<<cardsObtained[gameNo]<<i<<'\n';
        }
	}

    for(int i=0; i<noOfGames; i++)
    {
        // if(i>200)
        //     std::cout<<i<<'\t'<<cardsObtained[i]<<'\n';
        result+=cardsObtained[i];
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