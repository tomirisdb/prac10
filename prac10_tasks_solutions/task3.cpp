#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

const int MAX_P = 1000;
const int MAX_N = 500; // 1000 divided by 2 

template <typename SOME_VECTOR>
void PrintTriangle(const SOME_VECTOR& vec) {
    for (const auto& myTuple : vec) {
        cout << "(" << get<0>(myTuple) << ", " 
                    << get<1>(myTuple) << ", " 
                    << get<2>(myTuple) << "), "
                    << get<3>(myTuple) << "), ";
    }
    cout << endl;
}

int main() {
    map<int, vector<tuple<int, int, int, int>>> res;
    int best_len = 1;
    int best_p = -1;

    for (int a = 1; a <= MAX_N; ++a) {
        for (int b = a; b <= MAX_N; ++b) {
            double c =sqrt(a * a + b * b);
            int ic = static_cast<int>(c); 
            if (c == ic) { // Check if c is an integer
                int p = a + b + ic;
                if (p > MAX_P) {
                    continue;
                }
                res[p].push_back(make_tuple(a, b, ic, p));

                int new_len = res[p].size();
                if (new_len > best_len) {
                    best_len = new_len;
                    best_p = p;
                    PrintTriangle(res[p]);
                }
            }
        }
    }

    if (best_p != -1) {
        PrintTriangle(res[best_p]);
        cout << "Best length: " << best_len << endl;
        cout << "DONE!" << endl;
    }

    return 0;

   
}