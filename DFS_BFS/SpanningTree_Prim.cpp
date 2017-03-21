//
//  SpanningTree_Prim.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/21/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"

struct Edge
{
    int v1, v2; // vertex 1, vertex 2
    float w; // weight of edge
};

void findMinSpanningTree(int numVertexes, short** weightMatrix) {
    
    bool treeVers[numVertexes];
    Edge* edges = new Edge[numVertexes - 1];
    bool haveWeightMin = false, isConnected = true;
    int weightMin = 0;
    int t_v1 = 0, t_v2 = 0;
    int count = 0;
    
    
    for(int i = 0; i < numVertexes; ++i) {
        treeVers[i] = false;
    }
    treeVers[0] = true; // First vertex is approved
    
    // If the graph had spanning tree, it would
    while (count < numVertexes - 1) {
        for(int i = 0; i < numVertexes; ++i) {
            if(treeVers[i]) {
                for(int j = 0; j < numVertexes; ++j) {
                    if(weightMatrix[i][j] != 0 && !treeVers[j]) {
                        if(!haveWeightMin || weightMin > weightMatrix[i][j]) {
                            haveWeightMin = true;
                            weightMin = weightMatrix[i][j];
                            t_v1 = i;
                            t_v2 = j;
                        }
                    }
                    
                    if(weightMatrix[j][i] != 0 && !treeVers[j]) {
                        if(!haveWeightMin || weightMin > weightMatrix[j][i]) {
                            haveWeightMin = true;
                            weightMin = weightMatrix[j][i];
                            t_v1 = i;
                            t_v2 = j;
                        }
                    }
                }
            }
        }
        if(!haveWeightMin) {
            isConnected = false;
            break;
        }
        
        edges[count].v1 = t_v1;
        edges[count].v2 = t_v2;
        edges[count].w = weightMin;
        treeVers[t_v2] = true;
        haveWeightMin = false;
        
        ++count;
    }
    
    if(!isConnected) {
        cout << "The graph is connected" << endl;
    } else {
        float totalWeight = 0;
        
        for(int i = 0; i < numVertexes - 1; ++i) {
            totalWeight += edges[i].w;
            cout << "(" << edges[i].v1 << ", " << edges[i].v2 << ") - " << edges[i].w << endl;
        }
        
        cout << "Total weight of spanning tree: " << totalWeight << endl;
    }
    
    
    
    
}
