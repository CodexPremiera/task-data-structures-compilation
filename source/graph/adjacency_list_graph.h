#ifndef THE_FINALS_REVIEW_ADJACENCY_MATRIX_GRAPH_H
#define THE_FINALS_REVIEW_ADJACENCY_MATRIX_GRAPH_H

#endif //THE_FINALS_REVIEW_ADJACENCY_MATRIX_GRAPH_H

#include <cstdlib>
#include <iostream>

using namespace std;

class AdjacencyListGraph : public Graph {
    char s_vertices[10]{};
    Vertex* vertexList [10]{};
    int num_vert;

    int s_edges[100]{};
    Edge* edgeList[100]{};
    int num_edge;

public:
    AdjacencyListGraph() {
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        return s_edges;
    }


    int getEdge(char u, char v)  {
        int uIndex = getIndexOfVertex(u);
        int vIndex = getIndexOfVertex(v);

        Vertex* uVertex = vertexList[uIndex];
        Vertex* vVertex = vertexList[vIndex];

        for (int i = 0; i < uVertex->outgoingCount; i++) {
            int outEdge = uVertex->outgoingEdges[i];

            for (int j = 0; j < vVertex->incomingCount; j++) {
                if (outEdge == vVertex->incomingEdges[j])
                    return outEdge;
            }
        }

        return 0;
    }

    int getIndexOfVertex(char vertex) {
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i] == vertex)
                return i;
        }

        return -1;
    }

    char* endVertices(int e)  {
        char out = ' ', in = ' ';

        for (int i = 0; i < num_vert; i++) {
            // find out
            if (out == ' ') {
                Vertex* outVert = vertexList[i];
                for (int j = 0; j < outVert->outgoingCount; j++) {
                    if (outVert->outgoingEdges[j] == e) {
                        out = outVert->elem;
                        break;
                    }
                }
            }

            // find in
            if (in == ' ') {
                Vertex* inVert = vertexList[i];
                for (int j = 0; j < inVert->incomingCount; j++) {
                    if (inVert->incomingEdges[j] == e) {
                        in = inVert->elem;
                        break;
                    }
                }
            }

            // return vertex array
            if (out != ' ' && in != ' ') {
                char* endVertices = new char[2];
                endVertices[0] = out;
                endVertices[1] = in;
                return endVertices;
            }
        }

        return nullptr;
    }

    char opposite(char v, int e)  {
        int vIndex = getIndexOfVertex(v);
        Vertex* vVertex = vertexList[vIndex];

        // check if v has edge e
        bool vHasEdgeE = false;
        for (int j = 0; j < vVertex->outgoingCount; j++) {
            if (vVertex->outgoingEdges[j] == e) {
                vHasEdgeE = true;
                break;
            }
        }
        if (!vHasEdgeE)
            return '-';

        // travers vertices
        for (int j = 0; j < num_vert; j++) {
            Vertex* currVert = vertexList[j];

            // find opposite vertex
            for (int k = 0; k < currVert->incomingCount; k++) {
                if (currVert->incomingEdges[k] == e)
                    return currVert->elem;
            }
        }

        // none is found
        return '-';
    }

    int outDegree(char v) {
        int vIndex = getIndexOfVertex(v);

        if (vIndex != -1)
            return vertexList[vIndex]->outgoingCount;

        return 0;
    }

    int inDegree(char v)  {
        int vIndex = getIndexOfVertex(v);

        if (vIndex != -1)
            return vertexList[vIndex]->incomingCount;

        return 0;
    }

    int* outgoingEdges(char v) {
        int vIndex = getIndexOfVertex(v);

        if (vIndex != -1)
            return vertexList[vIndex]->outgoingEdges;

        return nullptr;
    }

    int* incomingEdges(char v) {
        int vIndex = getIndexOfVertex(v);

        if (vIndex != -1)
            return vertexList[vIndex]->incomingEdges;

        return nullptr;
    }

    bool insertVertex(char x) {
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i] == x)
                return false;
        }

        vertexList[num_vert] = new Vertex{x, 0, 0,
                                          new int[10], new int[10]};
        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        int uIndex = getIndexOfVertex(u);
        int vIndex = getIndexOfVertex(v);

        // any vertex doesn't exist
        if (uIndex == -1 || vIndex == -1)
            return false;

        Vertex* uVertex = vertexList[uIndex];
        Vertex* vVertex = vertexList[vIndex];

        // check if already has edge
        if (getEdge(u, v) != 0)
            return false;

        // add edge
        uVertex->outgoingEdges[uVertex->outgoingCount++] = x;
        vVertex->incomingEdges[vVertex->incomingCount++] = x;
        edgeList[num_edge] = new Edge{x};
        s_edges[num_edge++] = x;

        return true;
    }


    int removeVertex(char v) {
        int vIndex = getIndexOfVertex(v);

        if (vIndex == -1)
            return 0;

        int edgesRemoved = 0;
        Vertex* vVertex = vertexList[vIndex];

        // remove edges
        int outCount = vVertex->outgoingCount;
        for (int i = 0; i < outCount; i++) {
            removeEdge(vVertex->outgoingEdges[0]);
            vVertex->outgoingCount--;
            edgesRemoved++;
        }

        int intCount = vVertex->incomingCount;
        for (int i = 0; i < intCount; i++) {
            removeEdge(vVertex->incomingEdges[0]);
            vVertex->incomingCount--;
            edgesRemoved++;
        }

        // remove vertex from list
        for (int i = vIndex; i < num_vert - 1; i++) {
            vertexList[i] = vertexList[i + 1];
            s_vertices[i] = s_vertices[i + 1];
        }
        num_vert--;

        return edgesRemoved;
    }


    bool removeEdge(int edge) {
        int edgeIndex = -1;
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i] == edge)
                edgeIndex = i;
        }

        // edge not found
        if (edgeIndex == -1)
            return false;

        // remove edge from list
        for (int i = edgeIndex; i < num_edge - 1; i++) {
            s_edges[i] = s_edges[i+1];
            delete edgeList[i];
            edgeList[i] = edgeList[i+1];
        }

        // remove edge from vertices
        char outVertexElem = ' ', inVertexElem = ' ';
        for (int i = 0; i < num_vert; i++) {
            // find outVertexElem
            if (outVertexElem == ' ') {
                Vertex* outVertex = vertexList[i];

                for (int j = 0; j < outVertex->outgoingCount; j++) {
                    if (outVertex->outgoingEdges[j] == edge) {
                        outVertexElem = outVertex->elem;

                        // remove edge from outgoing vertex list
                        for (int k = j; k < outVertex->outgoingCount - 1; k++) {
                            outVertex->outgoingEdges[k] = outVertex->outgoingEdges[k + 1];
                        }
                        outVertex->outgoingCount--;

                        break;
                    }
                }
            }

            // find inVertexElem
            if (inVertexElem == ' ') {
                Vertex* inVertex = vertexList[i];

                for (int j = 0; j < inVertex->incomingCount; j++) {
                    if (inVertex->incomingEdges[j] == edge) {
                        inVertexElem = inVertex->elem;

                        // remove edge from incoming vertex list
                        for (int k = j; k < inVertex->incomingCount - 1; k++) {
                            inVertex->incomingEdges[k] = inVertex->incomingEdges[k + 1];
                        }
                        inVertex->incomingCount--;

                        break;
                    }
                }
            }

            if (inVertexElem != ' ' && outVertexElem != ' ')
                break;
        }

        num_edge--;
        return true;
    }



    void print() override {
        cout << "Adjacency List" << endl;
        for (int i = 0; i < num_vert; i++) {
            Vertex* current = vertexList[i];
            cout << current->elem << " ---> ";

            // Print outgoing
            cout << "Out: [";
            for (int j = 0; j < current->outgoingCount; j++) {
                cout << current->outgoingEdges[j] << " ";
            }
            cout << "]  ";

            // Print incoming
            cout << "In: [";
            for (int j = 0; j < current->incomingCount; j++) {
                cout << current->incomingEdges[j] << " ";
            }
            cout << "]  ";
            cout << endl;
        }
    }
};