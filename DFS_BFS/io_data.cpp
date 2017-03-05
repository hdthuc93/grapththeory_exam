//
//  io_data.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/5/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"

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
