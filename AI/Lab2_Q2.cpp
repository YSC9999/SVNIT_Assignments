#include <bits/stdc++.h>
using namespace std;

struct Percept {
    bool trainDetected;
    bool obstacleDetected;
    bool emergencyActive;
};

struct Action {
    string gate;
    string hooter;
    string signal;
};

class LevelCrossingAgent {
public:
    Action decideAction(Percept p) {
        // Priority 1: Emergency Lever
        if (p.emergencyActive) {
            return {"Lower", "On", "Red (Emergency Stop)"};
        }
        
        // Priority 2: Obstacle on Track
        if (p.obstacleDetected) {
            return {"Lower", "On", "Red (Emergency Stop)"};
        }
        
        // Priority 3: Normal Train Passage
        if (p.trainDetected) {
            return {"Lower", "On", "Green (Safe)"};
        }
        
        // Priority 4: Normal Road Traffic
        return {"Raise", "Off", "Green (Safe)"};
    }
};

void runSimulation(LevelCrossingAgent& agent, Percept p, string scenario) {
    Action a = agent.decideAction(p);
    cout << "Scenario: " << scenario << endl;
    cout << "Percepts: [Train: " << (p.trainDetected ? "Yes" : "No")
         << ", Obstacle: " << (p.obstacleDetected ? "Yes" : "No")
         << ", Emergency: " << (p.emergencyActive ? "Yes" : "No") << "]" << endl;
    cout << "Actions : [Gate: " << a.gate 
         << ", Hooter: " << a.hooter 
         << ", Signal: " << a.signal << "]" << endl;
    cout << "----------------------------------------------------" << endl;
}

int main() {
    LevelCrossingAgent agent;

    cout << "--- Indian Railways Level Crossing Simulation ---" << endl;
    cout << "----------------------------------------------------" << endl;

    runSimulation(agent, {false, false, false}, "No Traffic / Normal");
    runSimulation(agent, {false, false, true}, "Manual Emergency Lever Pulled");
    runSimulation(agent, {false, true, false}, "Obstacle on Track without Train");
    runSimulation(agent, {false, true, true}, "Obstacle on Track with Emergency");
    runSimulation(agent, {true, false, false}, "Train Approaching");
    runSimulation(agent, {true, false, true}, "Train Approaching during Emergency");
    runSimulation(agent, {true, true, false}, "Train Approaching with Stuck Vehicle");
    runSimulation(agent, {true, true, true}, "Train and Obstacle with Emergency");

    return 0;
}
