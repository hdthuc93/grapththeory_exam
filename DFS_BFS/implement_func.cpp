//
//  implement_func.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "implement_func.hpp"
#include <fstream>

using namespace std;

bool readData(string fileName, int &numOfVertexes, short** &adjacencyMatrix) {
    
    ifstream fileData(fileName, ios::in);
    
    if(fileData.is_open()) {
        fileData >> numOfVertexes;
        
        adjacencyMatrix = new short*[numOfVertexes];
        
        for(int i = 0; i < numOfVertexes; ++i) {
            adjacencyMatrix[i] = new short[numOfVertexes];
            
            for(int j = 0; j < numOfVertexes; ++j) {
                fileData >> adjacencyMatrix[i][j];
            }
        }
        
        fileData.close();
        return true;
    }
    
    return false;
}

void DFS_simple_v1(int local, bool trackingPoint[], int numOfVertexs, short** adjacencyMatrix) {
    trackingPoint[local] = true;
    
    for(int i = 0; i < numOfVertexs; ++i) {
        cout << trackingPoint[i] << " ";
    }
    cout << endl;
    
    
    for(int i = 0; i < numOfVertexs; ++i) {
        if(adjacencyMatrix[local][i] == 1 && !trackingPoint[i]) {
            DFS_simple_v1(i, trackingPoint, numOfVertexs, adjacencyMatrix);
            cout << "Back to point: " << local << endl;
        }
    }
}


