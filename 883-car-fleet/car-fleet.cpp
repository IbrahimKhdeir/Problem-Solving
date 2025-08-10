class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        // Calculate time to reach the target for each car
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        // Sort cars by starting position in descending order (from closest to target)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double currentFleetTime = 0;

        for (const auto& car : cars) {
            if (car.second > currentFleetTime) {
                // This car forms a new fleet
                fleets++;
                currentFleetTime = car.second;
            }
            // Else, this car joins the fleet ahead (no increment)
        }

        return fleets;
    }
};