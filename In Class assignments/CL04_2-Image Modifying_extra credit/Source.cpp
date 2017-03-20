#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;


int main()
{
	ifstream input("bird.ppm");
	string buffer;
	string header;

	// Save the header:
	getline(input, buffer); // ascii code
	header += buffer + "\n";
	getline(input, buffer); // comment
	header += buffer + "\n";
	getline(input, buffer); // width/height
	header += buffer + "\n";
	getline(input, buffer); // max color
	header += buffer + "\n";



	int color;
	while (input >> color)
	{
		color.push_front(color);
	}

	
	//<pre>

	ofstream output("bird2.ppm");
	output << header;
	for (list<int>::iterator it = colors.begin();
		it != colors.end();
		it++)
	{
		output << *it << endl;
	}

	output.close();

	//< / pre>



	int r, g, b;
	while (input >> r >> g >> b)
	{
		colors.push_back(r);
		colors.push_back(g);
		colors.push_back(b);
	}

	return 0;

}