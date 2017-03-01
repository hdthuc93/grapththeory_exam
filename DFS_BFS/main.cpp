//
//  main.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//


#include "implement_func.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    int numOfVertexes;
    short** adjacencyMatrix = NULL;
    bool resultReadData = readData("data.txt", numOfVertexes, adjacencyMatrix);
    
    if(resultReadData) {
//        for(int i = 0; i < numOfVertexes; ++i) {
//            for(int j = 0; j < numOfVertexes; ++j) {
//                std::cout << adjacencyMatrix[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
        
        
        bool trackingPoint[numOfVertexes];
        
        for (int i = 0; i < numOfVertexes; ++i) {
            trackingPoint[i] = false;
        }
        
        DFS_simple_v1(3, trackingPoint, numOfVertexes, adjacencyMatrix);
    }
    std::cout << std::endl;
    
    
    
    delete adjacencyMatrix;
    return 0;
}
