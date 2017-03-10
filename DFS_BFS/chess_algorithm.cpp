//
//  chess_algorithm.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/5/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"
#include <cmath>

struct Point {
    int x;
    int y;
};

bool pointIsExists(vector<Point> vp, Point p) {
    
    int len = (int)vp.size();
    
    for(int i = 0; i < len; ++i) {
        if(vp[i].x == p.x && vp[i].y == p.y)
            return true;
    }
    
    return false;
}

void findTheWayKnightFromAtoB_v1() {
    
    // create start and end point in chess
    Point start, end;
    start.x = 1;
    start.y = 1;
    
    end.x = 7;
    end.y = 6;
    
    // create priority the way to go of knight
    Point nextPoint[8];
    nextPoint[0].y = 2;
    nextPoint[0].x = 1;
    
    nextPoint[1].y = 1;
    nextPoint[1].x = 2;
    
    nextPoint[2].y = -1;
    nextPoint[2].x = 2;
    
    nextPoint[3].y = -2;
    nextPoint[3].x = 1;
    
    nextPoint[4].y = -2;
    nextPoint[4].x = -1;
    
    nextPoint[5].y = -1;
    nextPoint[5].x = -2;
    
    nextPoint[6].y = 1;
    nextPoint[6].x = -2;
    
    nextPoint[7].y = 2;
    nextPoint[7].x = -1;
    
    
    // run DFS
    vector<Point> tracking;
    
    stack<Point> stackVers;
    stackVers.push(start);
    
    cout << "List step of knight: " << endl;
    
    while(!stackVers.empty()) {
        Point currentPoint = stackVers.top();
        tracking.push_back(currentPoint);
        
        cout << "x = " << currentPoint.x << " --- y = " << currentPoint.y << endl;
        
        if(currentPoint.x == end.x && currentPoint.y == end.y)
            break;
        
        for(int i = 0; i < 7; ++i) {
            Point desPoint;
            desPoint.x = currentPoint.x + nextPoint[i].x;
            desPoint.y = currentPoint.y + nextPoint[i].y;
            
            if(desPoint.x > 7 || desPoint.x < 0 || desPoint.y > 7 || desPoint.y < 0)
                continue;
            
            if(pointIsExists(tracking, desPoint))
                continue;
            
            stackVers.push(desPoint);
            break;
        }
    }
    
    cout << "End!!!!!!! " << endl << endl;
}


// ----------------------------------------------------------------------

struct Knight {
    Point current;
    Point previous;
};

bool addKnightInStack(Knight k, vector<Knight> &stack) {
    
    for(int i = 0; i < stack.size(); ++i) {
        if(k.current.x == stack[i].current.x && k.current.y == stack[i].current.y)
            return false;
    }
    
    if(k.current.x > 7 || k.current.x < 0 || k.current.y > 7 || k.current.y < 0)
        return false;
    
    stack.push_back(k);
    return true;
}

void addNextPointOfKnight(Point currentPoint, Point end, vector<Knight> &knightInStack) {

    int deltaX = end.x - currentPoint.x;
    int deltaY = end.y - currentPoint.y;
    
    
    Knight nextPosition;
    nextPosition.previous = currentPoint;
    
    //
    if(deltaX < 0) {
        nextPosition.current.x = currentPoint.x - 2;
        
        nextPosition.current.y = currentPoint.y - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.y = currentPoint.y + 1;
        addKnightInStack(nextPosition, knightInStack);
        
    } else if(deltaX > 0) {
        
        nextPosition.current.x = currentPoint.x + 2;
        
        nextPosition.current.y = currentPoint.y - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.y = currentPoint.y + 1;
        addKnightInStack(nextPosition, knightInStack);
    }
    
    //
    if(deltaY < 0) {
        nextPosition.current.y = currentPoint.y - 2;
        
        nextPosition.current.x = currentPoint.x - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.x = currentPoint.x + 1;
        addKnightInStack(nextPosition, knightInStack);
        
    } else if(deltaY > 0) {
        
        nextPosition.current.y = currentPoint.y + 2;
        
        nextPosition.current.x = currentPoint.x - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.x = currentPoint.x + 1;
        addKnightInStack(nextPosition, knightInStack);
    }
}

vector<Knight> numberWayToB(vector<Knight> vtKnightA, vector<Knight> vtKnightB) {
    vector<Knight> result;
    
    for(int i = 0; i < vtKnightA.size(); ++i) {
        for(int j = 0; j < vtKnightB.size(); ++j) {
            int x_distance = abs(vtKnightA[i].current.x - vtKnightB[j].current.x);
            int y_distance = abs(vtKnightA[i].current.y - vtKnightB[j].current.y);
            
            if((x_distance == 1 && y_distance == 2) || (x_distance == 2 && y_distance == 1)) {
                result.push_back(vtKnightA[i]);
                result.push_back(vtKnightB[j]);
                
            }
        }
    }
    
    return result;
}

void findTheWayKnightFromAtoB_v2() {
    // create start and end point in chess
    Point start, end;
    start.x = 1;
    start.y = 1;
    
    end.x = 7;
    end.y = 6;
    
    Knight startKnight, endKnight;
    startKnight.current = start;
    endKnight.current = end;
    
    vector<vector<Knight>> knightFromA, knightFromB;
    vector<Knight> firstElementA, firstElementB;
    
    firstElementA.push_back(startKnight);
    firstElementB.push_back(endKnight);
    knightFromA.push_back(firstElementA);
    knightFromB.push_back(firstElementB);
    
    vector<Knight> wayToB;
    
    while(wayToB.size() == 0) {
        
        vector<Knight> lastPosOfKnightA = knightFromA[knightFromA.size() - 1];
        vector<Knight> lastPosOfKnightB = knightFromB[knightFromB.size() - 1];
        
        wayToB = numberWayToB(lastPosOfKnightA, lastPosOfKnightB);
        
        if(wayToB.size() > 0)
            break;
        
        vector<Knight> newPosKnightA, newPosKnightB;
        
        for(int i = 0; i < lastPosOfKnightA.size(); ++i) {
            addNextPointOfKnight(lastPosOfKnightA[i].current, end, newPosKnightA);
        }
        knightFromA.push_back(newPosKnightA);
            
        for(int i = 0; i < lastPosOfKnightB.size(); ++i) {
            addNextPointOfKnight(lastPosOfKnightB[i].current, start, newPosKnightB);
        }
        knightFromB.push_back(newPosKnightB);
    }
    
    for(int i = 0; i < wayToB.size(); i+=2) {
        cout << wayToB[i].current.x << " - " << wayToB[i].current.y << endl;
        cout << wayToB[i + 1].current.x << " - " << wayToB[i + 1].current.y << endl;
        cout << " ----------------- " << endl;
    }
}









































