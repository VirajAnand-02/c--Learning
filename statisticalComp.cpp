#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

class Statistics {
public:
    static double computeMean(const vector<double>& data);
    static double computeMedian(vector<double> data); // Copy intended for sorting
    static double computeMode(const vector<double>& data);
    static double computeStandardDeviation(const vector<double>& data);
    static double computeVariance(const vector<double>& data);
    static double computeFirstOrderMoment(const vector<double>& data);
};

double Statistics::computeMean(const vector<double>& data) {
    return accumulate(data.begin(), data.end(), 0.0) / data.size();
}

double Statistics::computeMedian(vector<double> data) {
    size_t size = data.size();
    sort(data.begin(), data.end());
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2;
    } else {
        return data[size / 2];
    }
}

double Statistics::computeMode(const vector<double>& data) {
    map<double, int> countMap;
    for (double num : data) {
        countMap[num]++;
    }

    int maxCount = 0;
    double mode = data[0];
    for (const auto& elem : countMap) {
        if (elem.second > maxCount) {
            maxCount = elem.second;
            mode = elem.first;
        }
    }
    return mode;
}

double Statistics::computeStandardDeviation(const vector<double>& data) {
    double mean = computeMean(data);
    double sqSum = 0.0;
    for (double num : data) {
        sqSum += pow(num - mean, 2);
    }
    return sqrt(sqSum / data.size());
}

double Statistics::computeVariance(const vector<double>& data) {
    return computeStandardDeviation(data) * computeStandardDeviation(data);
}

double Statistics::computeFirstOrderMoment(const vector<double>& data) {
    return computeMean(data);
}

class Regression {
public:
    static pair<double, double> computeCoefficients(const vector<double>& xData, const vector<double>& yData);
};

pair<double, double> Regression::computeCoefficients(const vector<double>& xData, const vector<double>& yData) {
    double xMean = Statistics::computeMean(xData);
    double yMean = Statistics::computeMean(yData);
    double numerator = 0.0, denominator = 0.0;
    
    for (size_t i = 0; i < xData.size(); ++i) {
        numerator += (xData[i] - xMean) * (yData[i] - yMean);
        denominator += pow(xData[i] - xMean, 2);
    }
    
    double b1 = numerator / denominator;
    double b0 = yMean - b1 * xMean;
    
    return {b0, b1};
}

int main() {
    vector<double> data, xData, yData;
    int choice;
    do {
        cout << "Statistical Computation Program\n";
        cout << "1. Compute Mean\n";
        cout << "2. Compute Median\n";
        cout << "3. Compute Mode\n";
        cout << "4. Compute Standard Deviation\n";
        cout << "5. Compute Variance\n";
        cout << "6. Compute First Order Moment\n";
        cout << "7. Compute Regression\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= 6) {
            cout << "Enter the number of elements: ";
            size_t n;
            cin >> n;
            data.resize(n);
            cout << "Enter " << n << " numbers: ";
            for (size_t i = 0; i < n; ++i) {
                cin >> data[i];
            }
        } else if (choice == 7) {
            size_t n;
            cout << "Enter the number of elements for x dataset: ";
            cin >> n;
            xData.resize(n);
            cout << "Enter " << n << " numbers for x dataset: ";
            for (size_t i = 0; i < n; ++i) {
                cin >> xData[i];
            }
            cout << "Enter the same number of elements for y dataset: ";
            yData.resize(n);
            cout << "Enter " << n << " numbers for y dataset: ";
            for (size_t i = 0; i < n; ++i) {
                cin >> yData[i];
            }
        }

        switch (choice) {
            case 1:
                cout << "Mean: " << Statistics::computeMean(data) << endl;
                break;
            case 2:
                cout << "Median: " << Statistics::computeMedian(data) << endl;
                break;
            case 3:
                cout << "Mode: " << Statistics::computeMode(data) << endl;
                break;
            case 4:
                cout << "Standard Deviation: " << Statistics::computeStandardDeviation(data) << endl;
                break;
            case 5:
                cout << "Variance: " << Statistics::computeVariance(data) << endl;
                break;
            case 6:
                cout << "First Order Moment: " << Statistics::computeFirstOrderMoment(data) << endl;
                break;
            case 7: {
                auto [b0, b1] = Regression::computeCoefficients(xData, yData);
                cout << "Regression Coefficients: b0 = " << b0 << ", b1 = " << b1 << endl;
                break;
            }
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    } while (choice != 8);

    return 0;
}
