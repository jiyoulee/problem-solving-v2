#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string str;

int main() {
    /*
     * System.
     */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
     * Input.
     */
    cin >> str;

    /*
     * Output.
     */
    if ("NLCS" == str) {
        cout << "North London Collegiate School";
    }
    else if ("BHA" == str) {
        cout << "Branksome Hall Asia";
    }
    else if ("KIS" == str) {
        cout << "Korea International School";
    }
    else {
        cout << "St. Johnsbury Academy";
    }

    return 0;
}