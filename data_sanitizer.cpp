/*
 * Data Sanitizer Utility (C++)
 * Author: Samuel
 * Description: Demonstrates modern C++17 type safety using std::variant
 * to clean and parse an array of messy, unstructured string inputs.
 */

#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <cctype>
#include <algorithm>

// Using C++17 std::variant to safely hold either an int or a string
using CleanedItem = std::variant<int, std::string>;

// Helper function to trim whitespace from a string
std::string trimWhitespace(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// Helper function to check if a string contains only digits
bool isNumeric(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

// Core Sanitization Logic
std::vector<CleanedItem> sanitizeData(const std::vector<std::string>& raw_data) {
    std::vector<CleanedItem> cleaned_data;

    for (const auto& item : raw_data) {
        std::string trimmed = trimWhitespace(item);

        // Skip empty strings
        if (trimmed.empty()) {
            continue; 
        }

        // If numeric, convert to integer
        if (isNumeric(trimmed)) {
            cleaned_data.push_back(std::stoi(trimmed));
        } 
        // Otherwise, capitalize first letter and store as string
        else {
            trimmed[0] = std::toupper(trimmed[0]);
            for (size_t i = 1; i < trimmed.length(); ++i) {
                trimmed[i] = std::tolower(trimmed[i]);
            }
            cleaned_data.push_back(trimmed);
        }
    }
    return cleaned_data;
}

// ==========================================
// Testing the Logic
// ==========================================
int main() {
    // Simulating messy, unstructured data
    std::vector<std::string> messy_input = {"  apple ", "   ", "42", "100", "  BANANA  "};

    std::vector<CleanedItem> results = sanitizeData(messy_input);

    std::cout << "Cleaned Data Output:\n";
    for (const auto& item : results) {
        // Checking the type currently held in the variant
        if (std::holds_alternative<int>(item)) {
            std::cout << "[Integer] " << std::get<int>(item) << "\n";
        } else if (std::holds_alternative<std::string>(item)) {
            std::cout << "[String]  " << std::get<std::string>(item) << "\n";
        }
    }

    return 0;
}
