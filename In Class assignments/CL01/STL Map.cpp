#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	// Create a map that uses two strings. Name it colors.
	map <string, string> colors;


	// Populate several colors and their hex codes
	// but I'm not using these.....red = FF0000, green = 00FF00, blue = 0000FF
	// ...or these....magenta = FF00FF, yellow = FFFF00, cyan = 00FFFF
	// I'm using these:   

	colors["redish"] = "f13e2d";
	colors["orangey"] = "f1a02d";
	colors["neon green"] = "2df13e";
	colors["bright blue"] = "3e2df1";
	colors["baby blue"] = "2de0f1";
	colors["pinky"] = "f12d7e";


	string color;
	cout << "Enter a color, you're gonna get 'em wrong: ";
	cin >> color;

	// Display the hex value of the color, using the user's input as a key.
	cout << "Hex value: "<< colors [color] << endl;

	return 0;
}