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
    std::string filename = "datacsv"; // Replace "data.csv" with the path to your CSV file

    CSVReader reader(filename)

// Note that this is not ideal - readData() should be part of the constructor, but we leave it here for now
    reader.readData();

    double average = reader.calculateAverage();

    std::cout << "Average value of the second column: " << average << std::endl;

    return 0;
}
