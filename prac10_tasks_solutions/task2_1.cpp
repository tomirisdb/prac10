#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename Matcher, typename MatchHandler>
void findMatches(const vector<int>& values1, const vector<int>& values2,
    Matcher matcher, MatchHandler handler)
{
    if (values1.size() != values2.size()) { return; } // Both vectors must be same size.

    for (size_t i = 0; i < values1.size(); ++i) {
        if (matcher(values1[i], values2[i])) {
            handler(i, values1[i], values2[i]);
        }
    }
}

void printMatch(size_t position, int value1, int value2)
{
    cout << "Match found at position = " << position << endl;
    cout << "value1 = "  << value1 << endl;
    cout << "value2 = "  << value2 << endl;
}

int main()
{
    vector<int> values1{ 2, 500, 6, 9, 10, 101, 1 };
    vector<int> values2{ 4, 4, 2, 9, 0, 300, 1 };

    auto matcher = [](int value1, int value2) { // the stateless lambda matcher checks if both values are greater than 100 directly
        return value1 > 100 && value2 > 100;
    };

    findMatches(values1, values2, matcher, printMatch);
}