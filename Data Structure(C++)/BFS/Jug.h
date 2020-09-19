#ifndef JUG_H
#define JUG_H

using namespace std;

//use stack and vector
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <string>
#include <climits>

class Vertex
{
    friend class Jug;
    public:
        Vertex(int, int);
    private:
        int volumeA;
        int volumeB;
        int previous;
        unsigned int distance;
        bool unvisited;
        vector<pair<unsigned int, string> > neighbors;
};

class Jug
{
    public:
        Jug(int, int, int, int, int, int, int, int, int);
        ~Jug();
        //solve is used to check input and find the solution if one exists
        //returns -1 invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &);
    private:
        //anything else you need
        int Ca;
        int Cb;
        int N;
        int cfA;
        int cfB;
        int ceA;
        int ceB;
        int cpAB;
        int cpBA;
        unsigned int fillA(unsigned int);
        unsigned int fillB(unsigned int);
        unsigned int emptyA(unsigned int);
        unsigned int emptyB(unsigned int);
        unsigned int pourAB(unsigned int);
        unsigned int pourBA(unsigned int);
        int getCost(string) const;
        vector<unsigned int> building;
        vector<unsigned int> visited;
        vector<Vertex> vertices;
        stack<string> OutPut;
        void graph();
        string shortest();
        
};

#endif