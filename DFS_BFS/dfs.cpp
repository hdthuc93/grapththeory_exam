//
//  implement_func.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"


void DFS_simple_v1(int local, bool trackingPoint[], int numOfVertexes, short** adjacencyMatrix) {
    trackingPoint[local] = true;
    
    for(int i = 0; i < numOfVertexes; ++i) {
        cout << trackingPoint[i] << " ";
    }
    cout << endl;
    
    
    for(int i = 0; i < numOfVertexes; ++i) {
        if(adjacencyMatrix[local][i] == 1 && !trackingPoint[i]) {
            DFS_simple_v1(i, trackingPoint, numOfVertexes, adjacencyMatrix);
            cout << "Back to point: " << local << endl;
        }
    }
}

void DFS_simple_v2(int numOfVertexes, short** adjacencyMatrix) {
    int startVer = 3;
    int verLabels[numOfVertexes];
    
    for(int i = 0; i < numOfVertexes; ++i) {
        verLabels[i] = 0;
    }
    
    stack<int> stackVers;
    stackVers.push(startVer);
    
    cout << "\nDFS version 2: ";
    
    while(!stackVers.empty()) {
        int iVerLabel = stackVers.top();
        bool isNotCont = true;
        
        verLabels[iVerLabel] = 1;
        
        // Print result
        cout << iVerLabel << " ";
        
        for(int i = 0; i < numOfVertexes; ++i) {
            if(adjacencyMatrix[iVerLabel][i] == 1 && verLabels[i] == 0) {
                stackVers.push(i);
                isNotCont = false;
                break;
            }
        }
        
        if(isNotCont) {
            stackVers.pop();
        }
    }
    cout << endl;
    
}










