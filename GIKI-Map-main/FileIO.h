#pragma once


#include "DSL.h"

using namespace DSL;
using namespace std;

namespace IO
{

	class FileIO
	{
	public:

		void load_map(Graph& G)  //Making a function to load the verteces from a file into the graph
		{
			string nodes;
			ifstream mapFile;
			mapFile.open("Map.txt", ios::in);
			while (true)
			{
				if (mapFile.eof() == true)
				{
					return;
				}
				else
				{
					getline(mapFile, nodes);
					G.add_vertex(nodes);
				}
			}
		}


		void load_costs(Graph& G)   //Making a function to load the edges matrix from a file into the program
		{
			string cost;
			string data;
			ifstream costFile;
			costFile.open("cost.txt");
			int i = 0;
			int j = 0;
			int num = 0;
			while (true)
			{
				if (costFile.eof() == true)
				{
					return;
				}
				else
				{
					getline(costFile, cost);
					stringstream ss(cost);
					while (getline(ss, data, ',') && i < 40 && j < 40)
					{
						num = stoi(data);
						G.add_edges(num, i, j);
						j++;
					}
					j = 0;
					i++;
				}
			}
		}
	};
	
}