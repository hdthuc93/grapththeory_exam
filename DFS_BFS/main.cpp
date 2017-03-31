//
//  main.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//


#include "declare.hpp"

int main(int argc, const char * argv[]) {

//    findMaxSeriesHotels();
//    findTheWayKnightFromAtoB_v2();
    
    int numOfVertexes;
    short** adjacencyMatrix = NULL;
    short** weightMatrix = NULL;
//    bool resultReadData = readData("data.txt", numOfVertexes, adjacencyMatrix);
    bool resultReadData = readData("txt_input/input_prim.txt", numOfVertexes, weightMatrix);

    if(resultReadData) {
        bool trackingPointDFS[numOfVertexes];
        
        for (int i = 0; i < numOfVertexes; ++i) {
            trackingPointDFS[i] = false;
        }
        
//        DFS_simple_v1(3, trackingPointDFS, numOfVertexes, adjacencyMatrix);
//        DFS_simple_v2(numOfVertexes, adjacencyMatrix);
//
//        BFS_simple_v1(numOfVertexes, adjacencyMatrix);
        
        findMinSpanningTree(numOfVertexes, weightMatrix);
    }
    cout << endl;
    
    delete adjacencyMatrix;
    return 0;
}
