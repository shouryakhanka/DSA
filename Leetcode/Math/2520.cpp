// #include<iostream>
// using namespace std;

// int main() {
//     int num = 7;

//     int countDigits(int num) {
//         int count = 0;

//         while (num > 0) {

//         int digit = num / 10;

//         if (num % digit == 0) {
//             count++;
//         }

//         num /= 10;
//     }
//         return count;
//     }
// };

// int countDigits(int n) {
//     int originalN = n;
//     int count = 0;
//     while (n > 0) {
//         int digit = n % 10;
//         if (digit != 0 && originalN % digit == 0) count++;
//         n /= 10;
//     }
//     return count;
// }
