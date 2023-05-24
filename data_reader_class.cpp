#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVReader {
private:
    std::string filename;
    std::vector<double> columnData;

public:
    CSVReader(const std::string& filename) : filename(filename) {}

    bool readData() {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open the file." << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string cell;

            // Skip the first column
            if (std::getline(ss, cell, ',') && std::getline(ss, cell, ',')) {
                double value;
                std::istringstream(cell) >> value;
                columnData.push_back(value);
            }
        }

        file.close();

        if (columnData.empty()) {
            std::cerr << "No data found in the second column." << std::endl;
            return false;
        }

        return true;
    }

    double calculateAverage() const {
        double sum = 0.0;
        for (double value : columnData) {
            sum += value;
        }
        return sum / columnData.size();
    }
};

int main() {
    std::string filename = "data.csv"; // Replace "data.csv" with the path to your CSV file

    CSVReader reader(filename);
    if (!reader.readData()) {
        return 1;
    }

    double average = reader.calculateAverage();
    std::cout << "Average value of the second column: " << average << std::endl;

    return 0;
}
