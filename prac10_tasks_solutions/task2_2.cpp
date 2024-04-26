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

class IsLargerThan
{
public:
    explicit IsLargerThan(int value) : m_value{ value } {}

    bool operator()(int value1, int value2) const {
        return value1 > m_value && value2 > m_value;
    }

private:
    int m_value;
};

int main()
{
    vector<int> values1{ 2, 500, 6, 9, 10, 101, 1 };
    vector<int> values2{ 4, 4, 2, 9, 0, 300, 1 };
    int threshold = 100;

    auto matcher = [threshold](int value1, int value2) {
        return value1 > threshold && value2 > threshold;
    };

    findMatches(values1, values2, matcher, printMatch);
}
