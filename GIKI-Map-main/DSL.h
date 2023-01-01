#pragma once



/*		 This Library is designed to implement the LinkedList data structure in form of vectors(like in STL) and to implement Graphs
		 The Library is developed for general purpose usage for any C++ programmer.
*/
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


namespace DSL  //Specifying the namespace DSL
{
	template <class T> //Making a class template Node to store data along with the pointer to the next node in the linkedlist
	class Node
	{
	public:
		T data;
		Node* link;

		Node()
		{
			link = nullptr;

		}

	};

	template <class S> //Making a class template named Vector  with basic Vector Functionality
	class Vector
	{
	private:
		Node<S>* head;
		int size = 0;
	public:
		Vector()
		{
			head = nullptr;
		}

		void push_back(S data)  //Making a function to push_back data into my vector
		{
			if (head == nullptr)
			{
				head = new Node<S>;
				head->data = data;
				head->link = nullptr;
				size++;
			}
			else
			{
				Node<S>* current = head;
				while (current->link != nullptr)
				{
					current = current->link;
				}

				current->link = new Node<S>;
				current = current->link;
				current->data = data;
				current->link = nullptr;
				size++;
			}
		}


		void print_vector()  //Making a function to print all the vector elements
		{
			if (head == nullptr)
			{
				cout << "The vector is empty\n";
			}
			else
			{
				Node<S>* current = head;
				while (current != nullptr)
				{
					cout << current->data << endl;
					current = current->link;
				}
			}
		}


		S& operator[](int index) //Overloading the [] operator to implement the array indexing capabilities.
		{

			if (head == nullptr)
			{
				cout << "Vector is empty\n";
			}
			else
			{
				Node<S>* current = head;
				for (int i = 0; i < index; i++)
				{
					current = current->link;
				}

				return current->data;
			}
		}


		void delete_element(int index) //Making a function to delete an element from a vector provided the index
		{
			if (head == nullptr)
			{
				cout << "Vector is Empty\n";
			}
			else if (index == 0)
			{
				Node<S>* temp = head;
				head = head->link;
				delete temp;
				size--;
			}
			else if (index == size - 1)
			{
				Node<S>* current = head;
				while (current->link->link != nullptr)
				{
					current = current->link;
				}
				Node<S>* temp = current->link;
				current->link = nullptr;
				delete temp;
				size--;

			}

			else
			{
				Node<S>* current = head;
				for (int i = 0; i < index - 1; i++)
				{
					current = current->link;
				}
				Node<S>* temp = current;
				temp = temp->link;
				current->link = current->link->link;
				delete temp;
				size--;
			}
		}

		int get_size()  //Making a function to get the size of the vector
		{
			return size;
		}

		bool is_in(S loc) //Function that returns true if an element is present in the vector and false otherwise
		{
			bool check = false;
			Node<S>* current = head;
			while (current != nullptr)
			{
				if (current->data == loc)
				{
					return true;
				}
				current = current->link;

			}

			return false;
		}

	};




	class Vertex  //Making a class function to implement Vertex of the graph
	{
	public:
		string location;

		Vertex()
		{
			location = " ";
		}
	};

	class Graph  //Making a class graph
	{
	private:

	public:
		int** cost = nullptr;
		Vector<Vertex> verteces;
		Graph()                                 //Constructor to intiliaze 2D Dynamic array of adjency matrix.
		{
			cost = new int* [40];
			for (int i = 0; i < 40; i++)
			{
				cost[i] = new int[40];
			}
		}

		void add_vertex(string loc)      //Function to add Vertex
		{
			Vertex V;
			V.location = loc;
			verteces.push_back(V);
		}


		void add_edges(int num, int i, int j)  //Function to add Edge
		{
			cost[i][j] = num;
		}


		void print_matrix()       //Function to print the adjency matrix
		{
			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 40; j++)
				{
					cout << cost[i][j] << " ";
				}
				cout << endl;
			}
		}

		void print_verteces()  //Function to print verteces of the graph.
		{
			for (int i = 0; i < verteces.get_size(); i++)
			{
				cout << verteces[i].location << endl;
			}
		}

		int find_vertex(string loc)  //Function to return the index of the vertex
		{
			for (int i = 0; i < verteces.get_size(); i++)
			{
				if (loc == verteces[i].location)
				{
					return i;
				}
			}
		}

		int get_size()  //Function to get size of verteces vector
		{
			return verteces.get_size();
		}
	};

}


