#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;
#define PI 3.14159

struct point {
	int x, y, z;
};


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

		/*ALL OF THIS IS FOR GETTING POINTS FROM FILE*/
		int x, i =0, j =0;
		ifstream myinfile("input.txt");
		if (myinfile.is_open())
		{
			//get size, make array of points.
			myinfile >> x;
			point** points = new point*[x];
			for (int k = 0; k < x; k++) {
				mypoints[k] = new point[3];
			}

			while (myinfile >> input)
			{
				i++;
				if (counter % 3 = 0) {
					j++;
					i = 0;
				}
				mypoints[j][i].x = input;
				myinfile >> input;
				mypoints[j][i].y = input;
				myinfile >> input;
				mypoints[j][i].z = input;
			}
			myinfile.close();

			for (int m = 0; m < x; m++) {
				for (int n = 0; n < 3; n++) {
					cout << mypoints[m][n].x  << ", " << mypoints[m][n].y << ", " << mypoints[m][n].z << "\t\t";
				}
				cout << endl;
			}
		}

		else cout << "Unable to open file";

	
		
		myfile << "};\n";

		myfile.close();
	}
	else cout << "Unable to open file";


	return 0;

}