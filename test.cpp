#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// Define infinity as a large number to represent unreachable nodes
const int INFINITY = INT_MAX;
const int MAX_TIME_ROUTE = 120;  // Time-to-live for each route

// Define the routing table for router A
struct Route {
    string next_hop;
    int cost;
    int time_route;
};

map<string, Route> routing_table = {
    {"A", {"A", 0, MAX_TIME_ROUTE}},
    {"B", {"B", 1, MAX_TIME_ROUTE}},
    {"C", {"C", 1, MAX_TIME_ROUTE}},
    {"E", {"E", 1, MAX_TIME_ROUTE}},
    {"F", {"F", 1, MAX_TIME_ROUTE}},
    {"D", {"-", INFINITY, 0}},  // Initially unreachable
    {"G", {"-", INFINITY, 0}}   // Initially unreachable
};

// Function to print the current routing table of router A
void printRoutingTable() {
    cout << "Routing table at A:" << endl;
    cout << "Destination\tNextHop\tCost" << endl;
    for (const auto& entry : routing_table) {
        cout << entry.first << "\t\t" << entry.second.next_hop << "\t" << entry.second.cost << endl;
    }
    cout << endl;
}

// Function to merge a new route into the routing table of A
bool mergeRoute(const string& destination, const string& next_hop, int cost) {
    if (routing_table.find(destination) != routing_table.end()) {
        int current_cost = routing_table[destination].cost;
        if (cost + 1 < current_cost) {
            // Found a better route
            routing_table[destination] = {next_hop, cost + 1, MAX_TIME_ROUTE};
            return true;
        } else if (routing_table[destination].next_hop == next_hop) {
            // Update the cost for the same next-hop if metric has changed
            routing_table[destination].cost = cost + 1;
            routing_table[destination].time_route = MAX_TIME_ROUTE;
            return false;
        }
        return false;  // No change if the route is uninteresting
    } else {
        // Completely new route
        routing_table[destination] = {next_hop, cost + 1, MAX_TIME_ROUTE};
        return true;
    }
}

// Function to update the routing table with routes received from a neighbor
bool updateRoutingTable(const vector<tuple<string, string, int>>& neighbor_routes) {
    bool updated = false;
    for (const auto& route : neighbor_routes) {
        string destination = get<0>(route);
        string next_hop = get<1>(route);
        int cost = get<2>(route);
        if (mergeRoute(destination, next_hop, cost)) {
            updated = true;
        }
    }
    return updated;
}

// Simulate receiving distance vectors from neighbors and updating the routing table
void simulateRound(const map<string, vector<tuple<string, string, int>>>& neighbor_vectors) {
    for (const auto& neighbor : neighbor_vectors) {
        cout << "Received distance vector from neighbor " << neighbor.first << ":" << endl;
        for (const auto& route : neighbor.second) {
            cout << "Dest: " << get<0>(route) << ", Cost: " << get<2>(route) << endl;
        }
        cout << endl;
        if (updateRoutingTable(neighbor.second)) {
            cout << "Routing table of A updated with routes from " << neighbor.first << endl;
        }
    }
    printRoutingTable();
}

// Main Simulation
int main() {
    cout << "Initial distance vector of A:" << endl;
    printRoutingTable();

    // Define distance vectors received from neighbors in the first round
    map<string, vector<tuple<string, string, int>>> neighbor_vectors_round1 = {
        {"B", {{"A", "B", 1}, {"C", "B", 1}, {"D", "B", 2}}},
        {"C", {{"A", "C", 1}, {"D", "C", 1}, {"G", "C", 2}}},
        {"E", {{"A", "E", 1}, {"F", "E", 1}}},
        {"F", {{"A", "F", 1}, {"G", "F", 1}}}
    };

    // Run rounds until the routing table at A converges
    int round_num = 1;
    bool changes = true;
    while (changes) {
        cout << "--- Round " << round_num << " ---" << endl;
        simulateRound(neighbor_vectors_round1);
        round_num++;

        // Check if routing table changes; if not, it has converged
        changes = updateRoutingTable(neighbor_vectors_round1["B"]) ||
                  updateRoutingTable(neighbor_vectors_round1["C"]) ||
                  updateRoutingTable(neighbor_vectors_round1["E"]) ||
                  updateRoutingTable(neighbor_vectors_round1["F"]);
    }

    cout << "Final distance vector of A:" << endl;
    printRoutingTable();

    return 0;
}
