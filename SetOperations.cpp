/*
File Name: SetOperations.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-19
*/

#include "SetOperations.hpp"
void SetOperations::setMenu() {
    // Implementation for setting the menu
        int a, b;
        int choice;
        vector<int> setA, setB;

        cout << "Enter the number of elements in Set A: ";
        while(!(cin >> a) || a < 0) {
            cout << "Please enter a non-negative integer ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Enter the elements of Set A: ";
        for(int i = 0; i < a; i++) {
            int element;
            cin >> element;
            setA.push_back(element);
        }

        cout << "Enter the number of elements in Set B: ";
        while(!(cin >> b) || b < 0) {
            cout << "Please enter a non-negative integer ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Enter the elements of Set B: ";
        for(int i = 0; i < b; i++) {
            int element;
            cin >> element;
            setB.push_back(element);
        }

    do {
        cout << "\nSet Operations Menu\n"
                << "1. Union\n"
                << "2. Intersection\n"
                << "3. Difference\n"
                << "4. Cartesian Product\n"
                << "5. Back to Main Menu\n"
                << "Enter your choice: ";

        while(!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "that... that isn't between 1 and 5... let's try this again";

            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice) {
            case 1: {
                cout << "Union selected.\n";
                set<int> unionResult = unionOp(setA, setB); 

                cout << "Union of Set A and Set B: ";
                for (int num : unionResult) {
                    cout << num << " ";
                }
                cout << "\n";
                break;
            }

            case 2: {
                cout << "Intersection selected.\n";
                set<int> intersectionResult = intersectionOp(setA, setB);

                cout << "Intersection of Set A and Set B: ";
                for (int num : intersectionResult) {
                    cout << num << " ";
                }
                cout << "\n";
                break;
            }


            case 3: {
                cout << "Difference selected.\n";
                set<int> differenceResult = differenceOp(setA, setB);

                cout << "Difference of Set A and Set B: ";
                for (int num : differenceResult) {
                    cout << num << " ";
                }
                cout << "\n";
                break;
            }
            case 4: {
                cout << "Cartesian Product selected.\n";
                set<pair<int, int>> cartesianResult = cartesianProductOp(setA, setB);

                cout << "Cartesian Product of Set A and Set B: ";
                for (const auto& pair : cartesianResult) {
                    cout << "(" << pair.first << ", " << pair.second << ") ";
                }
                cout << "\n";
                
                break;
            }

            case 5:
                cout << "Returning to Main Menu.\n";

                break;
            default:
                cout << "that... that isn't between 1 and 5... let's try this again\n";
        }
    } while (choice != 5);
}

        

        

set<int> SetOperations::unionOp(vector<int>& setA, vector<int>& setB) {
    // Implementation for union operation
    set<int> res;
    for (int num : setA) {
        res.insert(num);
    }
    for (int num : setB) {
        res.insert(num);
    }

    return res;
}


set<int> SetOperations::intersectionOp(vector<int>& setA, vector<int>& setB) {
    // Implementation for intersection operation
    set<int> res;
    for (auto num : setA){
        // to find if whatever numebr is in A is also in B, if it is then add it to the result set
        if (find(setB.begin(), setB.end(), num) != setB.end()){
            res.insert(num);
        }
    }
    return res;
}   

set<int> SetOperations::differenceOp(vector<int>& setA, vector<int>& setB) {
    // Implementation for difference operation
        set<int> res;
    for (auto num : setA){
        // to find if whatever numebr is in A is also in B, if it is not then add it to the result set
        if (find(setB.begin(), setB.end(), num) == setB.end()){
            res.insert(num);
        }
    }
    return res;

}   


set<pair<int, int>> SetOperations::cartesianProductOp(vector<int>& setA, vector<int>& setB) {
    // Implementation for cartesian product operation
    set<pair<int, int>> res;

    for (auto numA : setA){
        
        for (auto numB : setB){
            res.insert(make_pair(numA, numB));
        }
    }
    return res;
}
