#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int x, int n, vector<int> arr) {
	if ((x*x + 1) % n == 0) {
    	arr.push_back(x);
    } else if (x == n) {
    	return arr;
    }
    return solve(x + 1, n, arr);
}

int checkPrime(int a, int b) {
	if (a % b != 0) {
    	return checkPrime(a, b + 1);
    }
	else {
    	return b;
    }
}

void printIntruc() {
    cout << "How it works: For any positive integer n, the calculator will " << endl 
    << "calculate all the prime numbers p, where 2 ≤ p ≤ n and determine" << endl 
    << "all solutions of x such that x * x + 1 = 0 (mod p) for every p " << endl 
    << "that has a solution. " << endl << endl;
}

int main() {

    cout << endl;
    cout << "*************************************************************" << endl;
    cout << "********** Welcome to the Mod Solutions Calculator **********" << endl;
    cout << "*************************************************************" << endl << endl;
    printIntruc();
    cout << "Enter a positive integer: ";

    string input;
    cin >> input;
    while (input != "quit") {
        int num = stoi(input);
        vector<int> primes;
        for (int i = 2; i < num + 1; i++) {
            if (checkPrime(i, 2) == i) {
                primes.push_back(i);
            }
        }
        
        int prime_size = primes.size();
        for (int i = 0; i < prime_size; i++) {
            vector<int> arr;
            arr = solve(1, primes.at(i), arr);
            int size = arr.size();
            
            cout << primes.at(i) << ": ";
            if (size == 0) {
                cout << "No solution" << endl;
            } else {
            for (int j = 0; j < size; j++) {
                cout << arr.at(j) << " ";
            }
            cout << endl;
            }
        }
        cout << endl << "Enter a new integer, \"quit\", or \"help\": ";
        cin >> input;
        if(input == "help") {
            cout << endl;
            printIntruc();
            cout << "Enter a new integer or \"quit\": ";
            cin >> input;
        }
    }
    return 0;
}
