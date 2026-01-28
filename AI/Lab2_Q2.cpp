#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem 2: Simple Reflex Agent for Indian Railways Level Crossing
 * 
 * Environment: Double-track railway intersecting a busy highway.
 * 
 * Percepts:
 * 1. Track Sensors: Inbound (Train approaching within 2km) or Outbound.
 * 2. Obstacle Sensors (Yellow Box): Grid sensors detecting stuck vehicles/animals.
 * 3. Manual Emergency Input: Lever pulled by station master.
 * 
 * Actuators:
 * 1. Gate Arm: Lower / Raise
 * 2. Hooter: On / Off
 * 3. Signal to Train: Green (Safe) / Red (Emergency)
 * 
 * Rule Set (Prioritized for Safety):
 * 1. IF Emergency Lever is Active THEN Signal = Red, Hooter = On, Gate = Lower.
 * 2. IF Obstacle Detected in Yellow Box THEN Signal = Red, Hooter = On, Gate = Lower (Keep closed).
 * 3. IF Train Detected AND NO Obstacle THEN Signal = Green, Hooter = On, Gate = Lower.
 * 4. IF NO Train AND NO Obstacle AND NO Emergency THEN Signal = Green, Hooter = Off, Gate = Raise.
 * 
 * Do you need priorities in the rules?
 * Yes. For safety-critical systems, conflicting percepts must be resolved by priority.
 * For example, if a train is coming (rule 3) but there is an obstacle (rule 2), 
 * the obstacle rule MUST take priority to stop the train.
 */

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

    // Test cases
    runSimulation(agent, {false, false, false}, "No Traffic / Normal");
    runSimulation(agent, {true, false, false}, "Train Approaching");
    runSimulation(agent, {true, true, false}, "Train Approaching with Stuck Vehicle");
    runSimulation(agent, {false, false, true}, "Manual Emergency Lever Pulled");
    runSimulation(agent, {true, false, true}, "Train Approaching during Emergency");

    return 0;
}
