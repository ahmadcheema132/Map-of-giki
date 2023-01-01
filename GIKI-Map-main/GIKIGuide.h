#pragma once

#include "PathFinder.h"

using namespace Search;

namespace Guide
{
	class GIKIMAP
	{
	private:
		Graph G;
		PathFinder P;
		FileIO F;
	public:



		GIKIMAP()  //Constrcutor to load map cand costs
		{
			F.load_map(G);
			F.load_costs(G);
		}

		void shortest_path(string start, string goal)  //Function to print shortest path that calls a function UCS from the PathFinder.h header
		{
			P.UCS(G, start, goal);
		}

		void show_loctions()  //Function to show verteces of a graph
		{
			G.print_verteces();
		}

	};
}


