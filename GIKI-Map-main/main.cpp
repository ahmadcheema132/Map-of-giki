

#include "GIKIGuide.h";
using namespace Guide;


int main()
{

	GIKIMAP G; //Making object of class GIKIMAP
	string start, end;

	G.show_loctions(); //Displaying all the available location points
	cout << endl << endl;
	cout << "Enter Your Starting Point\n";
	cin >> start;
	cout << "Enter Your Destination\n";
	cin >> end;
	cout << endl << endl;

	cout << "Path : ";
	G.shortest_path(start, end); //Displaying the path along with the distance

	return 0;
}
