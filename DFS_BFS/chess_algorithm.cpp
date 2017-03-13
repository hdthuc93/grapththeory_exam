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
    
    // create priority the next position knight can arrive
    int nextPointX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int nextPointY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    
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
            desPoint.x = currentPoint.x + nextPointX[i];
            desPoint.y = currentPoint.y + nextPointY[i];
            
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

void addNextPosOfKnight(Point currentPos, Point target, vector<Knight> &knightInStack) {

    int deltaX = target.x - currentPos.x;
    int deltaY = target.y - currentPos.y;
    
    
    Knight nextPosition;
    nextPosition.previous = currentPos;
    
    //
    if(deltaX < 0) {
        nextPosition.current.x = currentPos.x - 2;
        
        nextPosition.current.y = currentPos.y - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.y = currentPos.y + 1;
        addKnightInStack(nextPosition, knightInStack);
        
    } else if(deltaX > 0) {
        
        nextPosition.current.x = currentPos.x + 2;
        
        nextPosition.current.y = currentPos.y - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.y = currentPos.y + 1;
        addKnightInStack(nextPosition, knightInStack);
    }
    
    //
    if(deltaY < 0) {
        nextPosition.current.y = currentPos.y - 2;
        
        nextPosition.current.x = currentPos.x - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.x = currentPos.x + 1;
        addKnightInStack(nextPosition, knightInStack);
        
    } else if(deltaY > 0) {
        
        nextPosition.current.y = currentPos.y + 2;
        
        nextPosition.current.x = currentPos.x - 1;
        addKnightInStack(nextPosition, knightInStack);
        
        nextPosition.current.x = currentPos.x + 1;
        addKnightInStack(nextPosition, knightInStack);
    }
}

vector<Knight> discoverTargetPos(vector<Knight> vtKnightA, vector<Knight> vtKnightB) {
    vector<Knight> result;
    
    for(int i = 0; i < vtKnightA.size(); ++i) {
        for(int j = 0; j < vtKnightB.size(); ++j) {
            int x_distance = abs(vtKnightA[i].current.x - vtKnightB[j].current.x);
            int y_distance = abs(vtKnightA[i].current.y - vtKnightB[j].current.y);
            
            if((x_distance == 1 && y_distance == 2) || (x_distance == 2 && y_distance == 1)) {
                result.push_back(vtKnightA[i]);
                result.push_back(vtKnightB[j]);
                i = (int) vtKnightA.size();
                break;
            }
        }
    }
    
    return result;
}

void findTheWayKnightFromAtoB_v2() {
    // create start and end point in chess
    Point start, end;
    start.x = 3;
    start.y = 3;
    
    end.x = 5;
    end.y = 5;
    
    Knight startKnight, endKnight;
    startKnight.current = start;
    endKnight.current = end;
    
    vector<vector<Knight>> knightFromA, knightFromB;
    vector<Knight> firstElementA, firstElementB;
    
    firstElementA.push_back(startKnight);
    firstElementB.push_back(endKnight);
    knightFromA.push_back(firstElementA);
    knightFromB.push_back(firstElementB);
    
    vector<Knight> subWay;
    
    while(subWay.empty()) {
        
        vector<Knight> lastPosOfKnightA = knightFromA[knightFromA.size() - 1];
        vector<Knight> lastPosOfKnightB = knightFromB[knightFromB.size() - 1];
        
        subWay = discoverTargetPos(lastPosOfKnightA, lastPosOfKnightB);
        
        if(!subWay.empty()) {
            break;
        }
        
        
        vector<Knight> newPosKnightA, newPosKnightB;
        
        for(int i = 0; i < lastPosOfKnightA.size(); ++i) {
            addNextPosOfKnight(lastPosOfKnightA[i].current, end, newPosKnightA);
        }
        knightFromA.push_back(newPosKnightA);
        subWay = discoverTargetPos(newPosKnightA, lastPosOfKnightB);
        
        if(!subWay.empty())
            break;
            
        for(int i = 0; i < lastPosOfKnightB.size(); ++i) {
            addNextPosOfKnight(lastPosOfKnightB[i].current, start, newPosKnightB);
        }
        knightFromB.push_back(newPosKnightB);
    }
    
    vector<Knight> partFromA;
    vector<Knight> partFromB;
    
    partFromA.push_back(subWay[0]);
    partFromB.push_back(subWay[1]);
    
    if(subWay[0].current.x != start.x || subWay[0].current.y != start.y) {
        for(int indexWayA = (int)knightFromA.size() - 2; indexWayA >= 0; --indexWayA) {
            
            Knight currentPos = partFromA[partFromA.size() - 1];
            
            if(currentPos.current.x == start.x && currentPos.current.y == start.y)
                break;
            
            vector<Knight> stepPosOfKnights = knightFromA[indexWayA];
            
            for(int i = 0; i < stepPosOfKnights.size(); ++i) {
                if(currentPos.previous.x == stepPosOfKnights[i].current.x && currentPos.previous.y == stepPosOfKnights[i].current.y) {
                    partFromA.push_back(stepPosOfKnights[i]);
                    break;
                }
            }
        }

    }
    
    if(subWay[1].current.x != start.x || subWay[1].current.y != start.y) {
        
        for(int indexWayB = (int)knightFromB.size() - 2; indexWayB >= 0; --indexWayB) {
            
            Knight currentPos = partFromB[partFromB.size() - 1];
            
            if(currentPos.current.x == end.x && currentPos.current.y == end.y)
                break;
            
            
            vector<Knight> stepPosOfKnights = knightFromB[indexWayB];
            
            for(int i = 0; i < stepPosOfKnights.size(); ++i) {
                if(currentPos.previous.x == stepPosOfKnights[i].current.x && currentPos.previous.y == stepPosOfKnights[i].current.y) {
                    partFromB.push_back(stepPosOfKnights[i]);
                    break;
                }
            }
        }
    }
    
    while (!partFromA.empty()) {
        Knight temp = partFromA[partFromA.size() - 1];
        partFromA.pop_back();
        cout << "(" << temp.current.x << ", " << temp.current.y << ") - ";
    }
    
    while (!partFromB.empty()) {
        Knight temp = partFromB[0];
        partFromB.erase(partFromB.begin());
        cout << "(" << temp.current.x << ", " << temp.current.y << ") - ";
    }
    
    cout << endl;
}









































