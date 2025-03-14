#include "dijkstras.h"

int main(int argc, char* argv[]) {
    Graph G;
    file_to_graph(argv[1], G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int v = 0; v < G.numVertices; ++v) {
        print_path(extract_shortest_path(distances, previous, v), distances[v]);
    }
    return 0;
}