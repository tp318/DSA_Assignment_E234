#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* heights = new int[n];
    int* result = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        
        while (!s.empty() && s.top() <= heights[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(heights[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] heights;
    delete[] result;

    return 0;
}
