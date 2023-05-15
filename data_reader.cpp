#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

double calculateAverage(const std::vector<double>& values) {
    double sum = 0.0;
    for (size_t i = 0; i < values.size(); i++) {
        sum += values[i];
    }
    return sum / values.size();
}

int main() {
    std::ifstream file("data.csv"); // Replace "data.csv" with the path to your CSV file

    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<double> columnData;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;

        // Split the line into cells using comma as the delimiter
        std::getline(ss, cell, ','); // Skip the first column
        std::getline(ss, cell, ','); // Read the second column

        // Convert the cell value to double and store it in the vector
        double value;
        std::istringstream(cell) >> value;
        columnData.push_back(value);
    }

    file.close();

    if (columnData.empty()) {
        std::cerr << "No data found in the second column." << std::endl;
        return 1;
    }

    double average = calculateAverage(columnData);
    std::cout << "Average value of the second column: " << average << std::endl;

    return 0;
}
