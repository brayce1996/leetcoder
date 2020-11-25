class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> distances;
        for (auto point: points) {
            distances.push_back(point[0] * point[0] + point[1] * point[1]);
        }

        int left = 0;
        int right = points.size() - 1;

        while (left < right) {
            int pivotIndex = partition(points, distances, left, right);
            if (pivotIndex == K) {
                break;
            } else if (pivotIndex > K) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }

        return vector<vector<int>> (points.begin(), points.begin() + K);
    }

private:
    int partition(vector<vector<int>>& points, vector<int>& distances, int left, int right) {
        int pivot = right;
        int smallerIndex = left;

        for (int i = left; i < right; i++) {
            if (distances[i] <= distances[pivot]) {
                swap(distances[smallerIndex], distances[i]);
                swap(points[smallerIndex], points[i]);
                smallerIndex++;
            }
        }
        swap(distances[smallerIndex], distances[pivot]);
        swap(points[smallerIndex], points[pivot]);

        return smallerIndex;
    }
};
