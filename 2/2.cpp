#include <iostream>
#include <fstream>

bool isAlphanum(std::string);
bool isAlphanum(char);
std::string deleteLastChar(std::string);
int isColourWhich(std::string);

int main()
{
	int maxPossible[3]={0};
	int gamesSum=0;
	std::fstream inputHandle("../input2.txt", std::ios::in);
	int gameID=0;
	bool readGID=false;
	std::string previous="";
	
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
			int temp=1;
			std::cout<<"\n"<<gameID<<"\t";
			for(auto &i:maxPossible)
			{
				std::cout<<i<<"\t";
				temp*=i;
				i=0;
			}
			gamesSum+=temp;
			readGID=true;
		}

		if(!isAlphanum(got))
		{
			got=deleteLastChar(got);
		}

		if(isColourWhich(got))
		{
			if(maxPossible[isColourWhich(got)-1]<stoi(previous))
			{
				maxPossible[isColourWhich(got)-1]=stoi(previous);
			}
		}

		previous=got;
	}

	int temp=1;
	std::cout<<"\n"<<gameID<<"\t";
	for(auto i:maxPossible)
	{
		std::cout<<i<<"\t";
		temp*=i;
	}
	gamesSum+=temp;

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

int isColourWhich(std::string input)
{
	if(input=="red")
	{
		return 1;
	}

	else if(input=="green")
	{
		return 2;
	}

	else if(input=="blue")
	{
		return 3;
	}

	return 0;
}
