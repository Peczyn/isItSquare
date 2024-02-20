#include <iostream>

using namespace std;



bool isSquare(const string& S) {
    //add directions and how many times they appeared to map
    unordered_map<char, int> map;
    for(auto direction : S) {
        map[direction]++;
    }

    //check if there are 4 directions
    if(map.size()<4) return false;

    //check if every directions appears the same amount of times
    int temp = 0;
    for(auto element : map) {
        if(temp == 0) temp = element.second;
        else if(element.second != temp) return false;
    }

    //check if directions are in good order
    int checkSwitches = 0;
    char lastChar = ' ';
    for(char letter : S) {
        if(lastChar==' ') {
            lastChar = letter;
        }
        else if(lastChar!=letter) {
            if(((lastChar=='v' || lastChar=='^') && (letter=='v' || letter=='^')) ||
                ((lastChar=='<' || lastChar=='>') && (letter=='<' || letter=='>'))) return false;
            lastChar = letter;
            checkSwitches++;
        }
    }
    if(checkSwitches==3 || (checkSwitches==4 && S[0] == S[S.size()-1])) return true;

    return false;
}



int main()
{
    cout << "Test1 (true): " << isSquare(">>^^<<vv") << endl;
    cout << "Test2 (false): " << isSquare("<>^^><vv") << endl;
    cout << "Test3 (true): " << isSquare("v>>^^<<v") << endl;
    cout << "Test3 (false): " << isSquare(">>^^<<") << endl;
    cout << "Test4 (true): " << isSquare(">>^^^^<<<<vvvv>>") << endl;
    cout << "Test5 (false): " << isSquare(">>^^vv^v<<<>") << endl;
    cout << "Test6 (true): " << isSquare("v>^<") << endl;
    cout << "Test7 (false): " << isSquare("><v^<v") << endl;


    return 0;
}
