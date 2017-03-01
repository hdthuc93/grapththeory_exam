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

bool readData(std::string fileName, int &numOfVertexs, short** &adjacencyMatrix);
void DFS_simple_v1(int local, bool trackingPoint[], int numOfVertexs, short** adjacencyMatrix);

#endif /* implement_func_hpp */
