#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"


TEST(WordLadderTest, NoLadderExists) {
    set<string> word_list = {"chevy", "nissan"};
    vector<string> ladder = generate_word_ladder("chevy", "nissan", word_list);
    EXPECT_TRUE(ladder.empty());
}

TEST(DijkstraTest, Disconnected) {
    Graph G;
    G.numVertices = 3;
    G.resize(3);
    G[0].push_back({0, 1, 5});
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    EXPECT_EQ(distances[2], INF);
}

TEST(DijkstraTest, Shortest) {
    vector<int> previous = {-1, 0, 1};
    vector<int> distances = {0, 3, 5};
    vector<int> path = extract_shortest_path(distances, previous, 2);
    vector<int> expected = {0, 1, 2};
    EXPECT_EQ(path, expected);
}

TEST(DijkstraTest, Print) {
    vector<int> path = {0, 3, 1};
    testing::internal::CaptureStdout();
    print_path(path, 3);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 3 1 \nTotal cost is 3\n");
}