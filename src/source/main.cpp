#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> user_input;
    string figure;
    while (getline(cin, figure) && figure != "") {
        user_input.push_back(figure);
    }
    return 0;
}