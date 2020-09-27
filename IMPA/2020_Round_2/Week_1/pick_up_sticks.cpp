#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum State
{
    UNMARKED, // The node have not been visited yet
    TEMPMARK, // The node are currently being visited
    PERMMARK  // The node have been visited
};

struct Node
{
    int id;
    set<Node *> children;
    State state = UNMARKED;
};

/**
 * Visit the specified node, called recursively upon it's children
 */
void visitNode(vector<int> *sortedNodes, Node *node)
{
    if (node->state == PERMMARK) // Node have already been visited
    {
        return;
    }
    else if (node->state == TEMPMARK) // Cycle detected, no solution possible
    {
        throw "IMPOSSIBLE";
    }

    node->state = TEMPMARK;

    // Visit children
    for (Node *child : node->children)
    {
        visitNode(sortedNodes, child);
    }

    node->state = PERMMARK;
    sortedNodes->push_back(node->id);
}

/**
 * Search for a solution to the graph using dfs, the result is stored in sortedNodes
 */
void topological_sort(vector<Node> *sticks, vector<int> *sortedNodes)
{
    // Find next node that havn't been permanently marked as visited and visit it
    for (vector<Node>::iterator it = sticks->begin(); it != sticks->end(); it++)
    {
        if (it->state != PERMMARK)
        {
            visitNode(sortedNodes, &*it);
        }
    }
}

int main()
{
    int nrOfSticks, nrOfRelations;

    // Continue while more cases exists
    while (scanf("%d %d", &nrOfSticks, &nrOfRelations) && !(nrOfSticks == 0 && nrOfRelations == 0))
    {
        vector<Node> sticks(nrOfSticks); // Vector of all nodes
        vector<int> res;                 // Vector of sorted nodes

        // Set id of all nodes
        for (size_t i = 0; i < nrOfSticks; i++)
        {
            sticks[i].id = i + 1;
        }

        // Generate graph from input
        int parrent, child;
        for (size_t i = 0; i < nrOfRelations; i++)
        {
            scanf("%d %d", &parrent, &child);
            sticks[child - 1].children.insert(&sticks.at(parrent - 1));
        }

        // Generate result
        try
        {
            topological_sort(&sticks, &res);
        }
        catch (const char *e) // Cycle detected
        {
            printf("%s\n", e);
        }

        // Output result
        for (int i = 0; i < res.size(); i++)
        {
            printf("%d\n", res.at(i));
        }

        // Reset variables
        nrOfSticks = 0;
        nrOfRelations = 0;
    }
}
