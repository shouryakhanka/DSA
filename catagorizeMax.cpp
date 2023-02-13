#include <iostream>
using namespace std;

    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = 0;
        vol = length * width * height;

        if (((length >= 10e4 || width >= 10e4 || height >= 10e4) || vol >= 10e9) and (mass >= 100))
        {
            return "Both";
        }

else if (!((length >= 10e4 || width >= 10e4 || height >= 10e4) || vol >= 10e9) and !(mass >= 100)) {
return "Neither";
}

else if (((length >= 10e4 || width >= 10e4 || height >= 10e4) || vol >= 10e9) and !(mass >= 100)) {
    return "Bulky";
}

else {
    return "Heavy";
}           
    }

int main()
{
    int length = 2909, width = 3968, height = 3272, mass = 727;

    cout << categorizeBox(length, width, height, mass) << endl;
    return 0;
}




