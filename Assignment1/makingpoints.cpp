#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;
#define PI 3.14159

int main() {
	int size = 0; // How many dots around the ring
	float s, t; //s and t coords
	float theta = 0;
	int r = 0; //angle where each point will be and the radius
	float x, y; //x and y of each point

	//Ask user for input to change size and num points
	cout << "How many points around your cone?\n" << endl;
	cin >> size;
	cout << "How big do you want your circle?\n" << endl;
	cin >> r;

	//Open file to write to
	ofstream myfile("points.cpp");
	if (myfile.is_open())
	{
		//Print out header info and beginning of VertexData struct
		myfile << "// *******************\n"
			<< "// VERTEX BUFFER DATA:\n"
			<< " // *******************\n"
			<< "#ifdef DEFINITION\n"
			<< "struct vertex\n"
			<< "{\n"
			<< "\tglm::vec3	position;\n"
			<< "\tglm::vec3	normal;\n"
			<< "\tglm::vec3	color;\n"
			<< "\tglm::vec2	texCoord;\n"
			<< " };\n"
			<< "#endif\n"
			<< "struct vertex VertexData[] =\n"
			<< "{ \n";

		//For as many circle points, print triangles that go Center, Point i, Point i+1 (COUNTERCLOCKWISE)
		for (int i = 0; i <size ; i++) {
			theta = i* 2.0*PI*r / size;
			//PRINY MIDDLE POINT
			myfile << "\t//Center for the 0, " << i << ", " << i + 1 << " triangle for circle\n"
				<< "\t{\n"
				<< "\t\t{ 0. 0. 0. },\n"
				<< "\t\t{ 1. 0. 1. },\n"
				<< "\t\t{ 1. 1. 1. },\n"
				<< "\t\t{ 0.5 0. 0.5 }\n";
			myfile << "\t},\n\n";

			//DO math for i's x y and s t
			x = r * cos(theta);
			y = r * sin(theta);
			s = x / 2.0*r;
			t = y / 2.0*r;
			if (x < 0.001) x = 0.0;
			if (x == 1) x = 1.00001; // FIX THIS ERROR
			if (y < 0.001) y = 0.0;
			myfile << "\t\t{ " << x << " 0. " << y << " },\n"
				<< "\t\t{ 1. 0. 1. },\n"
				<< "\t\t{ 1. 1. 1. },\n"
				<< "\t\t{ " << s << " " << t << " }\n";
			myfile << "\t},\n\n";

			//DO math for i+1's x y and s t
			x = r * cos(theta+ 2.0*PI*r / size);
			y = r * sin(theta+ 2.0*PI*r / size);
			s = x / 2.0*r;
			t = y / 2.0*r;
			if (x < 0.001) x = 0.0;
			if (y < 0.001) y = 0.0;
			myfile << "\t\t{ " << x << " 0. " << y << " },\n"
				<< "\t\t{ 1. 0. 1. },\n"
				<< "\t\t{ 1. 1. 1. },\n"
				<< "\t\t{ " << s << " " << t << " }\n";
			myfile << "\t},\n\n";
		}
		myfile << "};\n";

		myfile.close();
	}
	else cout << "Unable to open file";
	
	
	return 0;

}