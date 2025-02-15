#include <iostream>
#include <string>

using namespace std;

class FitnessTracker {
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int stepGoal) {
        userName = name;
        dailyStepGoal = stepGoal;
        stepsTaken = 0;
        caloriesBurned = 0;
    }

    void logSteps(int steps) {
        stepsTaken += steps;
        calculateCalories();
    }

    void calculateCalories() {
        caloriesBurned = stepsTaken * 0.04;
    }

    void displayProgress() {
        cout<<"User: "<<userName<<"\nSteps Taken: "<<stepsTaken<<"\nCalories Burned: "<<caloriesBurned<<"\nStep Goal: "<<dailyStepGoal;
        if (stepsTaken >= dailyStepGoal)
            cout<<"\nGoal Achieved!";
        else
            cout<<"\nKeep Going!";
        cout<<endl;
    }
};

int main() {
    FitnessTracker user1("Laiba", 10000);
    user1.logSteps(5000);
    user1.displayProgress();
    user1.logSteps(6000);
    user1.displayProgress();
    return 0;
}