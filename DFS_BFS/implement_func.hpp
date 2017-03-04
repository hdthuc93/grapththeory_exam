//
//  implement_func.hpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#ifndef implement_func_hpp
#define implement_func_hpp

#include <iostream>

bool readData(std::string fileName, int &numOfVertexes, short** &adjacencyMatrix);
void DFS_simple_v1(int local, bool trackingPoint[], int numOfVertexes, short** adjacencyMatrix);
void DFS_simple_v2(int numOfVertexes, short** adjacencyMatrix);

void BFS_simple_v1(int numOfVertexes, short** adjacencyMatrix);

#endif /* implement_func_hpp */
