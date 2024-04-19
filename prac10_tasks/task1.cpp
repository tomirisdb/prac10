#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> values {2, 5};
   
    values.insert(values.end(), 3);
    values.insert(values.end(), 4);

    // Create a second vector and insert its contents at the beginning of the first vector
    vector<int> initialValues {0, 1};
    values.insert(values.begin(), initialValues.begin(), initialValues.end());

    // Create a third vector and insert the contents of the first vector in reverse
    vector<int> reversedValues;
    for (auto i = values.rbegin(); i != values.rend(); ++i) {
        reversedValues.push_back(*i);
    }

    for (int value : reversedValues) {
        cout << value << ' ';
    }
    cout << endl;

    return 0;
}
