//
//  declare.hpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#ifndef declare_hpp
#define declare_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// IO data
bool readData(string fileName, int &numOfVertexes, short** &adjacencyMatrix);

// DFS algorithm
void DFS_simple_v1(int local, bool trackingPoint[], int numOfVertexes, short** adjacencyMatrix);
void DFS_simple_v2(int numOfVertexes, short** adjacencyMatrix);

// BFS algorithm
void BFS_simple_v1(int numOfVertexes, short** adjacencyMatrix);

// Spanning tree
void findMinSpanningTree(int numOfvers, short** weighMatrix);

// Chess algorithm
void findTheWayKnightFromAtoB_v1();
void findTheWayKnightFromAtoB_v2();

// find series hotel
void findMaxSeriesHotels();

// a star algorithm
void a_star(int numOfvers, short** weighMaxtrix);

#endif /* declare_hpp */
