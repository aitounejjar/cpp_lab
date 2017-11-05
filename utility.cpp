//
// Created by [Mouhcine] on 2017-09-30.
//

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "utility.hpp"

void mark_multiples(bool*, int, int);

using namespace std;

namespace utils {

    void print_median(vector<int> v) {
        sort(v.begin(), v.end());

        int size = v.size();

        double median;
        if (size%2 == 0) {
            int left = v[size/2-1];
            int right = v[size/2];
            median = (left+ right) / 2.0;
        } else {
            median = v[size/2];
        }

        utils::print_vector(v);
        cout << "Median is: " << median;
    }

    void print_vector(vector<int> v) {

        cout << "[" << v[0];

        for (int i=1; i<v.size(); ++i) {
            cout << ", " << v[i];
        }

        cout << "]" << endl;
    }

    void do_calculation() {
        // operator to string map
        map<string, string> map;
        map["+"] = "The sum of %.2f and %.2f is %.2f";
        map["-"] = "The subtraction of %.2f and %.2f is %.2f";
        map["*"] = "The multiplication of %.2f and %.2f is %.2f";
        map["/"] = "The division of %.2f by %.2f is %.2f";

        // get user input
        string op;
        double left, right;
        cout << "Enter two doubles and an operator: ";
        cin >> left >> right >> op;

        string output = map[op];

        double result;
        if (op == "+") {
            result = left + right;
        } else if (op == "-") {
            result = left - right;
        } else if (op == "*") {
            result = left * right;
        } else if (op == "/") {
            result = left / right;
        } else {
            cerr << "Operator '" << op << "' is not recognized. Expecting a char from {+, -, *, /}";
        }

        std::printf(output.c_str(), left, right, result);
    }

    void print_primes(const int max) {
        bool* arr = new bool[max];
        vector<int> primes = {2};

        for (int i=0; i<max; ++i) {
            arr[i] = false;
        }

        arr[0] = true;
        arr[1] = true;

        for (int n=3; n<max; ++n) {
            // no need to proceed if i has been previously marked as a multiple
            if (arr[n]) {
                continue;
            }

            // we need to check if n is prime
            // n is prime it has no divisors in the range [2, i-1]

            int numDivisors = 0;
            for (int d=2; d<n; ++d) {
                if (n%d == 0) {
                    ++numDivisors;
                }
            }

            if (numDivisors == 0) {
                primes.push_back(n);
            }

            // mark multiples of n as non-primes
            //mark_multiples(arr, n, max);
        }

        delete[] arr;

        print_vector(primes);
    }

    void print_mode(vector<int> nums) {

        // sort
        sort(nums.begin(), nums.end());
        print_vector(nums);


        // loop and count, track one

    }

    int fibonacci(int n) {
        // Complete the function.
        if ( n <= 1) {
            return n;
        } else {
            return fibonacci(n-1) + fibonacci(n-2);
        }
    }

}


void mark_multiples(bool* arr, int n, int size) {
    //cout << "Marked as non-primes: ";
    for (int i=n; i<size; i+=n) {
        //cout << " " << i;
        arr[i] = true;
    }
    //cout << endl;
}

// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97