#include "AStar.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <queue>
#include <set>
using namespace std;
class Node{
public:
    Node() = default;
    Node(int value){
        this->value = value;
    }
    Node (Node const &input){
        this->value = input.value;
        this->g_cost = input.g_cost;
        this->h_cost = input.h_cost;
        this->f_cost = input.f_cost;
    }
    int value;
    int g_cost;
    //cost according to heuristic, in this case: 0.
    int h_cost = 0;
    //f_cost will likely be g as h is zero.
    int f_cost;
    //node's parent
    int parent;
};
//class NodeCompare{
//public:
//    bool operator()(Node a, Node b)
//    {
//        if (a.f_cost > b.f_cost) {
//            return true;
//        }
//        return false;
//    }
//};
//
//class NodeEqual{
//public:
//    bool operator()(Node a, Node b)
//    {
//        if (a.f_cost == b.f_cost) {
//            return true;
//        }
//        return false;
//    }
//};
//
//
//
//int pqContains(priority_queue<Node> pq, Node e){
//    int pos;
//    priority_queue<Node> newPq = pq;
//    for (int i =0; i< pq.size(); i++) {
//        if (e.f_cost =newPq.top().f_cost)
//            return true;
//    }
//    return false;
//}
class ASTAR {
public:
    vector<vector<int>>AdjList;
    vector<Node>graph;


//    vector<int> reconstruct_path(Node start, Node goal) {
//        vector<int> path;
//        Node current_goal = goal;
////    while(current_goal != start){
////        current_goal = *current_goal.parent;
////    }
//        return path;
//    }

    vector<int> a_star(Node start, Node goal) {
        queue<int, vector<Node>> open_list;
        set<Node> closed_list;

        start.g_cost = 0;
        start.h_cost = 0;
        start.f_cost = start.g_cost + start.h_cost;
        //add the start node
        open_list.push(start);

        //may need is empty function.
        while (!open_list.empty()) {
            Node current_node = open_list.front();
            if (current_node.value == goal.value) {
                return reconstruct_path(start, goal);
            }

////    // Move current node from open list to closed list
////    closed_list.push(current_node);
//
//            // Expand current node's neighbors
//            for (int i = 0; i < current_node->neighbors.size(); i++) {
//                Node *sibling = current_node->neighbors.at(i);
//
////        // Skip neighbor if it's in the closed list
////        if ( closed_list.count(sibling))
////        continue;
//
//                int tenative_g_cost = current_node->g_cost + distance(current_node, sibling);
//
////        if (!open_list.contains (current_node->neighbors))
////            open_list.push(current_node->neighbors);
////        else if (tenative_g_cost > sibling->g_cost)
////            continue;
//
//                //Record it
//                sibling->parent = current_node;
//                sibling->g_cost = tenative_g_cost;
//                sibling->h_cost = 0;
//                sibling->f_cost = sibling->g_cost + sibling->h_cost;
//            }
//            //return null optionally.
//
//        }
//    }

    bool buildAdjList(const string &filename) {
        istringstream iss;
        string input;
        ifstream infile;
        vector<int> vertex;
        infile.open(filename);
        //Node newNode = *new Node;
        if (!infile) {
            cout << "unable to open the file";
            exit(1);
        }
        while (getline(infile, input)) {
            iss.str(input);
            int node;
            while (iss >> node) {
                if (node == -1) {
                    break;
                }
                vertex.push_back(node - 1);
            }
            AdjList.push_back(vertex);
            Node newNode = *new Node(vertex[0]);
            graph.push_back(newNode);
        }
        infile.close();
        return true;
    }
};



