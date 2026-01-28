#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * Problem 1: Simple Reflex Agent for Vacuum Cleaner
 * 
 * Rationality: 
 * A rational agent is one that does the right thing, conceptually, every entry in the table
 * for the agent function is filled out correctly. For a vacuum cleaner, rationality means
 * maximizing the cleanliness of the rooms while minimizing unnecessary movement. 
 * An agent is rational if, given its percept history and internal knowledge, it chooses 
 * an action that is expected to maximize its performance measure.
 * 
 * Performance Cost:
 * 1. +10 points for each room cleaned (Suck action on Dirty room).
 * 2. -1 point for each movement (Move Left/Right/Stay).
 * 3. -5 points if a room remains Dirty in a time step.
 * 
 * Rule Table:
 * Percept (Location, Status) -> Action
 * (A, Dirty) -> Suck
 * (A, Clean) -> Move Right
 * (B, Dirty) -> Suck
 * (B, Clean) -> Move Right (or Left, strategy dependent)
 * (C, Dirty) -> Suck
 * (C, Clean) -> Move Left
 * 
 * Priority: 
 * In a simple reflex agent, rules are usually checked in order. "Suck" generally has 
 * higher priority than "Move" if the current location is dirty.
 */

enum Status { CLEAN, DIRTY };
enum Action { SUCK, MOVE_LEFT, MOVE_RIGHT, NO_OP };

string statusToString(Status s) {
    return (s == CLEAN) ? "Clean" : "Dirty";
}

string actionToString(Action a) {
    switch (a) {
        case SUCK: return "Suck";
        case MOVE_LEFT: return "Move Left";
        case MOVE_RIGHT: return "Move Right";
        case NO_OP: return "No-op";
        default: return "Unknown";
    }
}

class VacuumAgent {
    map<pair<char, Status>, Action> ruleTable;

public:
    VacuumAgent() {
        // Define the Rule Table
        ruleTable[{'A', DIRTY}] = SUCK;
        ruleTable[{'A', CLEAN}] = MOVE_RIGHT;
        
        ruleTable[{'B', DIRTY}] = SUCK;
        ruleTable[{'B', CLEAN}] = MOVE_RIGHT; // Could alternate or prefer one side
        
        ruleTable[{'C', DIRTY}] = SUCK;
        ruleTable[{'C', CLEAN}] = MOVE_LEFT;
    }

    Action getAction(char location, Status status) {
        return ruleTable[{location, status}];
    }
};

struct Environment {
    map<char, Status> rooms;
    char agentLocation;
    int performanceScore;

    Environment() {
        rooms['A'] = DIRTY;
        rooms['B'] = CLEAN;
        rooms['C'] = DIRTY;
        agentLocation = 'A';
        performanceScore = 0;
    }

    void simulateStep(VacuumAgent& agent) {
        Status currentStatus = rooms[agentLocation];
        Action action = agent.getAction(agentLocation, currentStatus);

        cout << "Location: " << agentLocation 
             << " | Percept: " << statusToString(currentStatus) 
             << " | Action: " << actionToString(action) << endl;

        // Apply Action
        if (action == SUCK) {
            if (rooms[agentLocation] == DIRTY) {
                rooms[agentLocation] = CLEAN;
                performanceScore += 10;
            }
        } else if (action == MOVE_RIGHT) {
            performanceScore -= 1;
            if (agentLocation == 'A') agentLocation = 'B';
            else if (agentLocation == 'B') agentLocation = 'C';
        } else if (action == MOVE_LEFT) {
            performanceScore -= 1;
            if (agentLocation == 'C') agentLocation = 'B';
            else if (agentLocation == 'B') agentLocation = 'A';
        }

        // Penalty for dirty rooms
        for (auto const& it : rooms) {
            if (it.second == DIRTY) performanceScore -= 5;
        }
    }
};

int main() {
    VacuumAgent agent;
    Environment env;

    cout << "--- Vacuum Cleaner Simulation (3 Rooms: A, B, C) ---" << endl;
    for (int i = 0; i < 6; ++i) {
        env.simulateStep(agent);
    }
    cout << "Final Performance Score: " << env.performanceScore << endl;

    return 0;
}
