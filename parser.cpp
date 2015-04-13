#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

void readAndParseFile(char* file)
{	
	string line;
	const char* instruction;
	char* linechar;
	string opcode;
	//opcode = new int[6];

	ifstream myfile(file);
	if (myfile.is_open())
	{
		while(getline(myfile,line))
		{	
			//linechar = line;
			//parse
			vector<char> writableline(line.begin(), line.end());
			writableline.push_back('\0');
			linechar = &writableline[0];	
			
			instruction = strtok(linechar, " ,/n");
			//if first token is in J
			//ldi = 000010
			//add = 000000
			if(strcmp(instruction,"add") == 0) opcode = "000000";
			else if(strcmp(instruction,"ldi") == 0) opcode = "000010";
			else opcode = "111111";
			for(int i = 0; i < 6; ++i)
			{
				cout << opcode[i];
			}
			cout << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file." << endl;
}

int main(int argc, char *argv[]){
	readAndParseFile(argv[1]);
	return 0;
}

