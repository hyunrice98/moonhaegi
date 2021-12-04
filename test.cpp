#include <iostream>

using namespace std;

int main() {
    while (true) {
        int persons;
        int pizza_slices;
        try {
            cin >> pizza_slices;
            cin >> persons;

            if (persons < 0) throw "negative";
            if (persons == 0) throw persons;
            double slices_per_person = (double)pizza_slices / persons;
            cout << "NO EXCEPTION: " << slices_per_person << endl;
        } catch (const char *e) {
            cout << e << endl;
        } catch (int e) {
            cout << e << endl;
        }
    }

    return 0;
}