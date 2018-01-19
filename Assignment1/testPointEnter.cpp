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

point normalize(point vec1, point vec2) {
	point normal;
	point unitnormal;

	normal = 
}


int main() {


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
		int input = 0, i =0;
		int size0;
		ifstream myinfile("input.txt");
		if (myinfile.is_open())
		{
			//get size, make array of points.
			myinfile >> size;
			point* mypoints = new point[size];

			while (myinfile >> input)
			{
				mypoints[i].x = input;
				myinfile >> input;
				mypoints[i].y = input;
				myinfile >> input;
				mypoints[i].z = input;
				i++;
			}
			myinfile.close();

			for (int m = 0; m < size; m++) {
				if (m % 3 == 0) cout << endl;
					cout << mypoints[m].x  << ", " << mypoints[m].y << ", " << mypoints[m].z << "   ";
			}
		/*NOW TO CALCULATE NORMALS*/
			for (int i = 0; i < m / 3; i++) {
				point p1, p2, p3;
				p1 = mypoints[i * 3];
				p2 = mypoints[i * 3 + 1];
				p3 = mypoints[i * 3 + 2];

				point v1, v2;
				v1.x = p3.x - p1.x; v1.y = p3.y - p1.y; v1.z = p3.z - p1.z;
				v2.x = p2.x - p1.x; v2.y = p2.y - p2.y; v=2.z = p2.z - p1.z;

				point normal = normalize(v1, v2);
				mynormals[i * 3] = normal;
				mynormals[i * 3 + 1] = normal;
				mynormals[i * 3 + 2] = normal;
			}

		/*NOW TO PRINT TO THE FILE*/
		for (int m = 0; m < size; m++) {
			myfile << "\t\t{ " << mypoints[m].x << ". " << mypoints[m].y << ", " << mypoints[m].z << ". },\n"
				"\t\t{ " << mynormals[m].x << ". " << mynormals[m].y << ", " << mynormals[m].z << ". },\n"
				<< "\t\t{ 1. 1. 1. },\n"
				<< "\t\t{ " << myst[m].s << " " << myst[m].t << " }\n";
			myfile << "\t},\n\n";
			if (m % 3 == 0)
				myfile << "//Triangle " << (int)m / 3 << endl;
		}

		else cout << "Unable to open file";
		}
	
		
		myfile.close();
	}
	else cout << "Unable to open file";


	return 0;

}