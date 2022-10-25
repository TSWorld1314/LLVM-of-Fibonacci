#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv) {
    int n = argc > 1 ? atol(argv[1]) : 24;
    auto start = high_resolution_clock::now();
    int res = fibonacci(n);
    std::cout << "fibonacci result: " << res << std::endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count()/1000 << " millisecond" << endl;
    return 0;
}