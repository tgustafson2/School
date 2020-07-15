
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    float gastank, tmpg, hmpg, distance;
    cout << "What is the size of the car's gas tank?\n";
    cin >> gastank;
    cout << "What is the mpg in the city?\n";
    cin >> tmpg;
    cout << "What is the mpg on the highway?\n";
    cin >> hmpg;
    distance=tmpg*gastank;
    cout << "The car can drive " << distance << " miles in the city.\n";
    distance=hmpg*gastank;
     cout << "The car can drive " << distance << " miles on the highway.\n";
    return 0;
}

