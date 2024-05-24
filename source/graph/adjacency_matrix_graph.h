#ifndef THE_FINALS_REVIEW_ADJACENCY_MATRIX_GRAPH_H
#define THE_FINALS_REVIEW_ADJACENCY_MATRIX_GRAPH_H

#endif //THE_FINALS_REVIEW_ADJACENCY_MATRIX_GRAPH_H

#include <cstdlib>
#include <iostream>

class AdjacencyMatrixGraph : public Graph {
    int matrix[10][10]{};
    char s_vertices[10]{};
    int num_vert;
    int s_edges[100]{};
    int num_edge;

public:
    AdjacencyMatrixGraph() {
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

        return matrix[uIndex][vIndex];
    }

    int getIndexOfVertex(char vertex) {
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i] == vertex)
                return i;
        }

        return -1;
    }

    char* endVertices(int e)  {
        for (int i = 0; i < num_vert; i++) {
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] == e) {
                    char* endVerts = new char[2];
                    endVerts[0] = s_vertices[i];
                    endVerts[1] = s_vertices[j];
                    return endVerts;
                }
            }
        }

        return nullptr;
    }

    char opposite(char v, int e)  {
        int vIndex = getIndexOfVertex(v);

        for (int i = 0; i < num_vert; i++) {
            if (matrix[vIndex][i] == e)
                return s_vertices[i];
        }

        for (int i = 0; i < num_vert; i++) {
            if (matrix[i][vIndex] == e)
                return s_vertices[i];
        }

        return '-';
    }

    int outDegree(char v)  {
        int vIndex = getIndexOfVertex(v);
        int count = 0;

        for (int i = 0; i < num_vert; i++) {
            if (matrix[vIndex][i] != 0)
                count++;
        }

        return count;
    }

    int inDegree(char v)  {
        int vIndex = getIndexOfVertex(v);
        int count = 0;

        for (int i = 0; i < num_vert; i++) {
            if (matrix[i][vIndex] != 0)
                count++;
        }

        return count;
    }

    int* outgoingEdges(char v) {
        int vIndex = getIndexOfVertex(v);
        int count = 0;
        int* edges = new int[num_edge];

        for (int i = 0; i < num_vert; i++) {
            if (matrix[vIndex][i] != 0)
                edges[count++] = matrix[vIndex][i];
        }

        return edges;
    }

    int* incomingEdges(char v) {
        int vIndex = getIndexOfVertex(v);
        int count = 0;
        int* edges = new int[num_edge];

        for (int i = 0; i < num_vert; i++) {
            if (matrix[i][vIndex] != 0)
                edges[count++] = matrix[i][vIndex];
        }

        return edges;
    }

    bool insertVertex(char x)  {
        if (getIndexOfVertex(x) != -1)
            return false;

        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        int uIndex = getIndexOfVertex(u);
        int vIndex = getIndexOfVertex(v);

        if (uIndex == -1 || vIndex == -1 || matrix[uIndex][vIndex])
            return false;

        matrix[uIndex][vIndex] = x;
        s_edges[num_edge++] = x;
        return true;
    }


    int removeVertex(char v) {
        int vIndex = getIndexOfVertex(v);
        int countEdgesRemoved = 0;

        // remove outgoing edges
        for (int i = 0; i < num_vert; i++) {
            if (matrix[vIndex][i] != 0) {
                removeEdgeFromList(matrix[vIndex][i]);
                countEdgesRemoved++;
            }
        }

        // remove incoming edges
        for (int i = 0; i < num_vert; i++) {
            if (matrix[i][vIndex] != 0) {
                removeEdgeFromList(matrix[i][vIndex]);
                countEdgesRemoved++;
            }
        }

        // remove matrix row and col
        removeMatrixRow(vIndex);
        removeMatrixCol(vIndex);


        for (int k = vIndex; k < num_vert - 1; k++)
            s_vertices[k] = s_vertices[k + 1];

        num_vert--;
        return countEdgesRemoved;
    }

    void removeMatrixRow(int row) {
        for (int i = row; i <= num_vert; i++) {
            for(int j = 0; j < num_vert; j++)
                matrix[i][j] = matrix[i+1][j];
        }
    }
    void removeMatrixCol(int col) {
        for (int i = col; i <= num_vert; i++) {
            for(int j = 0; j < num_vert; j++)
                matrix[j][i] = matrix[j][i+1];
        }
    }

    bool removeEdge(int e)  {
        for (int i = 0; i < num_vert; i++) {
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != e)
                    continue;

                matrix[i][j] = 0;

                removeEdgeFromList(e);
                return true;
            }
        }

        return false;
    }

    void removeEdgeFromList(int edge) {
        int edge_index;
        for(edge_index = 0; edge_index < num_edge; edge_index++)
            if (s_edges[edge_index] == edge) break;

        for (int k = edge_index; k < num_edge - 1; k++)
            s_edges[k] = s_edges[k + 1];

        num_edge--;
    }


    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};