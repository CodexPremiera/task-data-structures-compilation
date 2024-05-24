#ifndef THE_FINALS_REVIEW_VERTEX_H
#define THE_FINALS_REVIEW_VERTEX_H

#endif //THE_FINALS_REVIEW_VERTEX_H

struct Vertex {
    char elem;
    int outgoingCount;
    int incomingCount;
    int* outgoingEdges;
    int* incomingEdges;
};
