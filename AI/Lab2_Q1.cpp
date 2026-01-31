#include <bits/stdc++.h>
using namespace std;

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
