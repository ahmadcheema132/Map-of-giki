#pragma once

#include "FileIO.h"

using namespace std;
using namespace DSL;
using namespace IO;

namespace Search

{

	class PathFinder
	{
	public:

		int priority(Vector<int> pr_queue)  //Function to select the most cost efficent element from the list
		{
			int min = pr_queue[0];
			int index = 0;
			for (int i = 0; i < pr_queue.get_size(); i++)
			{
				if (min > pr_queue[i])
				{
					min = pr_queue[i];
					index = i;
				}
			}
			return index;
		}


		void UCS(Graph G, string start, string goal) //Uniform Cost Search Function
		{
			if (start == goal)
			{
				cout << "You are already at your destination\n";
			}
			else
			{
				Vector<string> visited;
				Vector<string> queue;
				Vector<int> pr_queue;
				Vector<string> Path;
				Vector<Vector<string>> activePaths;
				string current;
				int pr = 0;
				int cost = 0;
				int index = 0;
				Vector<int> costs;

				queue.push_back(start);
				pr_queue.push_back(0);

				index = G.find_vertex(start);
				for (int i = 0; i < 40; i++)    //Making initial active paths from the start node.
				{
					if (G.cost[index][i] != 0)
					{
						Vector<string> path;
						path.push_back(start);
						path.push_back(G.verteces[i].location);
						activePaths.push_back(path);

					}
				}


				while (queue.get_size() > 0) //Running the loop until the queue is empty
				{
					//Selecting the best Vertex from the priority queue.

					pr = priority(pr_queue);
					current = queue[pr];
					queue.delete_element(pr);
					cost = pr_queue[pr];
					pr_queue.delete_element(pr);




					if (visited.is_in(current) == false && current != goal)  //Checking if the current vertex is in visited or not
					{


						visited.push_back(current);
						index = G.find_vertex(current);
						for (int i = 0; i < 40; i++)
						{
							if (G.cost[index][i] != 0)
							{

								pr_queue.push_back(G.cost[index][i] + cost);
								queue.push_back(G.verteces[i].location);
							}
						}

						Vector<string> path;


						for (int i = 0; i < activePaths.get_size(); i++)  //Creating active paths for UCS
						{
							if (activePaths[i][activePaths[i].get_size() - 1] == current)
							{

								for (int k = 0; k < 40; k++)
								{
									if (G.cost[index][k] != 0 && visited.is_in(G.verteces[k].location) == false && G.verteces[k].location != goal)
									{

										Vector<string> path;
										for (int x = 0; x < activePaths[i].get_size(); x++)
										{
											path.push_back(activePaths[i][x]);

										}
										path.push_back(G.verteces[k].location);
										activePaths.push_back(path);

									}
									else if (G.verteces[k].location == goal && G.cost[index][k] != 0)
									{
										Vector<string> path;
										for (int x = 0; x < activePaths[i].get_size(); x++)
										{
											path.push_back(activePaths[i][x]);

										}
										path.push_back(goal);
										activePaths.push_back(path);
										break;

									}
								}
							}
						}

					}
					else if (current == goal)
					{
						visited.push_back(current);

						//Selecting the best active path among all the paths.

						int min = 10000;
						int index = 0;
						int cost_index = 0;
						int cost_index_next = 0;
						int totalCost = 0;
						for (int i = 0; i < activePaths.get_size(); i++)
						{
							if (min > activePaths[i].get_size() && activePaths[i].is_in(goal) == true)
							{

								min = activePaths[i].get_size();
								index = i;

							}
						}
						for (int i = 0; i < activePaths[index].get_size(); i++)
						{
							cout << activePaths[index][i] << "  ";
						}

						//Finding the total cost of the path
						for (int i = 0; i < activePaths[index].get_size() - 1; i++)
						{
							cost_index = G.find_vertex(activePaths[index][i]);
							cost_index_next = G.find_vertex(activePaths[index][i + 1]);
							totalCost = totalCost + G.cost[cost_index][cost_index_next];

						}

						cout << endl;
						cout << "Total Distance : " << totalCost << " metres \n";

						return;
					}
				}
			}
		}
	};
	
}

