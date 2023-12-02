#include <iostream>
#include <fstream>

bool isAlphanum(std::string);
bool isAlphanum(char);
std::string deleteLastChar(std::string);
int isPossible(std::string, std::string, int[]);
bool isColour(std::string);

int main()
{
	int maxPossible[]={12, 13, 14};
	int gamesSum=0;
	std::fstream inputHandle("../input2.txt", std::ios::in);
	int gameID=0;
	bool readGID=false;
	std::string previous="";
	bool isGamePossible=true;
	std::cout<<"colour\ttooMuch\tgameID\n";
	
	while(!inputHandle.eof())
	{
		std::string got;
		inputHandle>>got;

		if(readGID)
		{
			gameID=stoi(deleteLastChar(got));
			readGID=false;
		}

		if(got=="Game")
		{
			if(isGamePossible)
			{
				std::cout<<"\n\n\t|"<<gameID<<"|\n\n";
				gamesSum+=gameID;
			}
			readGID=true;
			isGamePossible=true;
		}

		if(!isAlphanum(got))
		{
			got=deleteLastChar(got);
		}

		if(isColour(got) && isPossible(got, previous, maxPossible)==3)
		{
			isGamePossible=false;
			std::cout<<got<<"\t"<<previous<<"\t"<<gameID<<"\n";
		}

		previous=got;
		std::cout<<"\n"<<gameID<<"\n";
	}

	if(isGamePossible)
	{
		std::cout<<"\n\n\t|"<<gameID<<"|\n\n";
		gamesSum+=gameID;
	}

	std::cout<<"\n\t"<<gamesSum;
	
	return 0;
}





bool isAlphanum(std::string input)
{
	for(int i=0; i<static_cast<int>(input.length()); i++)
	{
		if(!isAlphanum(input[static_cast<size_t>(i)]))
		{
			return false;
		}
	}
	return true;
}

bool isAlphanum(char input)
{
	switch(static_cast<int>(input))
	{
		case 48 ... 57:
			return true;
		case 65 ... 90:
			return true;
		case 97 ... 122:
			return true;
		default:
			return false;
	}
}

std::string deleteLastChar(std::string input)
{
	std::string axa="";
	for(int i=0; i<static_cast<int>(input.length())-1; i++)
	{
		axa+=input[static_cast<size_t>(i)];
	}
	return axa;
}

int isPossible(std::string colour, std::string number, int maxPossible[])
{
	if(colour=="red")
	{
		if(stoi(number)<=maxPossible[0])
		{
			return 0;
		}
	}
	else if(colour=="green")
	{
		if(stoi(number)<=maxPossible[1])
		{
			return 1;
		}
	}
	else if(colour=="blue")
	{
		if(stoi(number)<=maxPossible[2])
		{
			return 2;
		}
	}
	return 3;
}

bool isColour(std::string input)
{
	if(input=="red" || input=="green" || input=="blue")
	{
		return true;
	}
	return false;
}
