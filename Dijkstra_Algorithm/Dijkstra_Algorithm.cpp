// Dijkstra_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Reference: https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <limits.h>

#define V 9

using namespace std;

int minDistance(int dist[], bool shortestPTSet[]) {
	//initializes the minimum distance value
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++) {
		if (shortestPTSet[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}
	return min_index;
}

void printPath(int parent[], int j) {
	if (parent[j] == -1) {
		return;
	}

	printPath(parent, parent[j]);

	cout << j << " ";
}

int printSolution(int dist[], int n, int parent[]) {
	int src = 0;
	cout << "Vertex: \t Distance: \t Path: \n" << endl;
	for (int i = 1; i < V; i++) {
		cout << " " << src << " -> " << i << "\t \t " << dist[i] << " " << "\t \t" << src << " " ;
		printPath(parent, i);

		cout << endl;
	}
	return src;
}

void Dijkstra(int graph[V][V], int src) {
	int dist[V];
	bool shortestPTSet[V];
	int parent[V];
	for (int i = 0; i < V; i++) {
		parent[src] = -1;
		dist[i] = INT_MAX;
		shortestPTSet[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V; count++) {
		int u = minDistance(dist, shortestPTSet);
		shortestPTSet[u] = true;
		for (int v = 0; v < V; v++) {
			if (!shortestPTSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, V, parent);
}

int main()
{				//    0  1  2  3  4  5  6  7  8
	int graph[V][V] = { {0, 1, 0, 0, 0, 0, 0, 11, 0},		//0
				    {1, 0, 12, 0, 0, 0, 0, 10, 0},		//1
				    {0, 12, 0, 39, 0, 30, 0, 0, 28},	//2
				    {0, 0, 39, 0, 27, 17, 0, 0, 0},	//3
				    {0, 0, 0, 27, 0, 20, 0, 0, 0},		//4
				    {0, 0, 30, 17, 20, 0, 51, 0, 0},	//5
				    {0, 0, 0, 0, 0, 51, 0, 29, 45},	//6
				    {11, 10, 0, 0, 0, 0, 29, 0, 31},	//7
				    {0, 0, 28, 0, 0, 0, 45, 31, 0}		//8
				};
	Dijkstra(graph, 0);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
