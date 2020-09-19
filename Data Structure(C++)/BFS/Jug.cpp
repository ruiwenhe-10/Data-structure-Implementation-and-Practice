#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <string>


using namespace std;

#include "Jug.h"

Vertex::Vertex(int volumeA, int volumeB)
{
    previous = -1;
    distance = UINT_MAX;
    unvisited = false;
    this->volumeA = volumeA;
    this->volumeB = volumeB;
}

Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA)
{
    this->Ca = Ca;
    this->Cb = Cb;
    this->N = N;
    this->cfA = cfA;
    this->cfB = cfB;
    this->ceA = ceA;
    this->ceB = ceB;
    this->cpAB = cpAB;
    this->cpBA = cpBA;
}

int Jug::solve(string &solution)
{
    if(Ca < 1 || Cb < 1 || Cb > 1000 || Ca > Cb || N < 0 || N > Cb || cfA < 0 || cfB < 0 || ceA < 0 || ceB < 0 || cpAB < 0 || cpBA < 0)
    {
        solution = "";      //invalid input
        
        return -1;
    }
    
    Vertex empty(0, 0);
    
    vertices.push_back(empty);
    building.push_back(0);
    graph();
    
    string success;
    
    success = shortest();
    if(success.empty() )
    {
        return 0;
    }
    while(!OutPut.empty() )
    {
        solution += (OutPut.top() + '\n');
        OutPut.pop();
    }
    solution += success;
    
    return 1;
}

Jug::~Jug()
{
    
}


void Jug::graph()
{
    while(!building.empty() )
    {
        bool found = false;
        unsigned int cur = building.front();
        
        building.erase(building.begin());
        for(unsigned int i = 0; i < visited.size(); i++)
        {
            if(cur == visited.at(i) )
            {
                found = true;
                
                break;
            }
        }
        if(!found)
        {
            visited.push_back(cur);
            building.push_back(fillA(cur));
            building.push_back(fillB(cur));
            building.push_back(emptyA(cur));
            building.push_back(emptyB(cur));
            building.push_back(pourAB(cur));
            building.push_back(pourBA(cur));
        }
    }
}

unsigned int Jug::fillA(unsigned int cur)
{
    unsigned int index;
    bool found = false;
    Vertex neighbor(Ca, vertices.at(cur).volumeB);
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == neighbor.volumeA && vertices.at(i).volumeB == neighbor.volumeB)
        {
            index = i;
            found = true;
            
            break;
        }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found)
    {
        pairing = make_pair(index, "fill A");
    }
    else
    {
        vertices.push_back(neighbor);
        pairing = make_pair(vertices.size() - 1, "fill A");
    }
    vertices.at(cur).neighbors.push_back(pairing);
    
    return vertices.at(cur).neighbors.back().first;         //the index of neighbor
}

unsigned int Jug::fillB(unsigned int cur)
{
    unsigned int index;
    bool found = false;
    Vertex neighbor(vertices.at(cur).volumeA, Cb);
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == neighbor.volumeA && vertices.at(i).volumeB == neighbor.volumeB)
        {
            index = i;
            found = true;
            
            break;
        }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found)
    {
        pairing = make_pair(index, "fill B");
    }
    else
    {
        vertices.push_back(neighbor);
        pairing = make_pair(vertices.size() - 1, "fill B");
    }
    vertices.at(cur).neighbors.push_back(pairing);
    
    return vertices.at(cur).neighbors.back().first;
}

unsigned int Jug::emptyA(unsigned int cur)
{
    unsigned int index;
    bool found = false;
    Vertex neighbor(0, vertices.at(cur).volumeB);
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == 0 && vertices.at(i).volumeB == neighbor.volumeB)
        {
            index = i;
            found = true;
            
            break;
        }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found)
    {
        pairing = make_pair(index, "empty A");
    }
    else
    {
        vertices.push_back(neighbor);
        pairing = make_pair(vertices.size() - 1, "empty A");
    }
    vertices.at(cur).neighbors.push_back(pairing);
    
    return vertices.at(cur).neighbors.back().first;
}

unsigned int Jug::emptyB(unsigned int cur)
{
    unsigned int index;
    bool found = false;
    Vertex neighbor(vertices.at(cur).volumeA, 0);
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == neighbor.volumeA && vertices.at(i).volumeB == 0)
        {
            index = i;
            found = true;
            
            break;
        }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found)
    {
        pairing = make_pair(index, "empty B");
    }
    else
    {
        vertices.push_back(neighbor);
        pairing = make_pair(vertices.size() - 1, "empty B");
    }
    vertices.at(cur).neighbors.push_back(pairing);
    
    return vertices.at(cur).neighbors.back().first;
}

unsigned int Jug::pourAB(unsigned int cur)
{
    unsigned int index;
    bool found = false;
    int neighborA = vertices.at(cur).volumeA;
    int neighborB = vertices.at(cur).volumeB;
    
    while(neighborA > 0 && neighborB < Cb)
    {
        neighborA--;
        neighborB++;
    }
    
    Vertex neighbor(neighborA, neighborB);
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == neighbor.volumeA && vertices.at(i).volumeB == neighbor.volumeB)
        {
            index = i;
            found = true;
            
            break;
        }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found)
    {
        pairing = make_pair(index, "pour A B");
    }
    else
    {
        vertices.push_back(neighbor);
        pairing = make_pair(vertices.size() - 1, "pour A B");
    }
    vertices.at(cur).neighbors.push_back(pairing);
    
    return vertices.at(cur).neighbors.back().first;
}

unsigned int Jug::pourBA(unsigned int cur)
{
    unsigned int index;
    bool found = false;
    int neighborA = vertices.at(cur).volumeA;
    int neighborB = vertices.at(cur).volumeB;
    
    while(neighborA < Ca && neighborB > 0)
    {
        neighborA++;
        neighborB--;
    }
    
    Vertex neighbor(neighborA, neighborB);
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == neighbor.volumeA && vertices.at(i).volumeB == neighbor.volumeB)
        {
            index = i;
            found = true;
            
            break;
        }
    }
    
    pair<unsigned int, string> pairing;
    
    if(found)
    {
        pairing = make_pair(index, "pour B A");
    }
    else
    {
        vertices.push_back(neighbor);
        pairing = make_pair(vertices.size() - 1, "pour B A");
    }
    vertices.at(cur).neighbors.push_back(pairing);
    
    return vertices.at(cur).neighbors.back().first;
}

int Jug::getCost(string value) const
{
    if(value == "fill A")
    {
        return cfA;
    }
    else if(value == "fill B")
    {
        return cfB;
    }
    else if(value == "empty A")
    {
        return ceA;
    }
    else if(value == "empty B")
    {
        return ceB;
    }
    else if(value == "pour A B")
    {
        return cpAB;
    }
    else
    {
        return cpBA;
    }
}



string Jug::shortest()
{
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == 0 && vertices.at(i).volumeB == N)
        {
            break;
        }
        else if(i == vertices.size() - 1)
        {
            return "";
        }
    }
    
    vector<Vertex *> unvisited;
    unsigned index;
    
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        Vertex *pointer = &vertices.at(i);
        
        unvisited.push_back(pointer);
    }
    unvisited.at(0)->distance = 0;
    while(!unvisited.empty() )
    {
        unsigned int minimum = 0;
        
        for(unsigned int i = 0; i < unvisited.size(); i++)      // extract minimum
        {
            if(unvisited.at(i)->distance < unvisited.at(minimum)->distance)
            {
                minimum = i;
            }
        }
        for(unsigned int i = 0; i < vertices.size(); i++)
        {
            if(vertices.at(i).volumeA == unvisited.at(minimum)->volumeA && vertices.at(i).volumeB == unvisited.at(minimum)->volumeB)    
            {
                index = i;          // confirm the index of the minimum
            }
        }
        for(unsigned i = 0; i < unvisited.at(minimum)->neighbors.size(); i++)
        {
            unsigned int alternate = unvisited.at(minimum)->distance + getCost(unvisited.at(minimum)->neighbors.at(i).second);
            
            if(vertices.at(unvisited.at(minimum)->neighbors.at(i).first).distance > alternate)
            {
                vertices.at(unvisited.at(minimum)->neighbors.at(i).first).distance = alternate;
                vertices.at(unvisited.at(minimum)->neighbors.at(i).first).previous = index;
            }
        }
        unvisited.erase(unvisited.begin() + minimum);   //join the cloud
    }
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).volumeA == 0 && vertices.at(i).volumeB == N)
        {
            index = i;
            
            break;
        }
    }
    unsigned int shortest = vertices.at(index).distance;
    
    while(vertices.at(index).previous != -1)
    {
        for(unsigned int i = 0; i < vertices.at(vertices.at(index).previous).neighbors.size(); i++)
        {
            if(vertices.at(vertices.at(index).previous).neighbors.at(i).first == index)
            {
                OutPut.push(vertices.at(vertices.at(index).previous).neighbors.at(i).second);
                
                break;
            }
        }
        index = vertices.at(index).previous;
    }
    
    stringstream ss;
    ss << shortest;
    
    return "success " + ss.str();
}



