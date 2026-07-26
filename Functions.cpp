/*
File Name: Functions.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#include "Functions.hpp"

void Functions::functionsMenu() {
    vector<int> domain;
    vector<pair<int, int>> mappings;
    int num, choice;

    cout << "Enter the integers in the domain (-1 to finish):\n";

    while (true) {
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter an integer please: ";
            continue;
        }

        if (num == -1) {
            break;
        }

        domain.push_back(num);
    }

    if (domain.empty()) {
        cout << "The domain cannot be empty.\n";
        return;
    }

    cout << "Enter the mappings as two integers separated by a space.\n";
    cout << "Enter -1 -1 to finish:\n";

    while (true) {
        int domainValue;
        int codomainValue;

        if (!(cin >> domainValue >> codomainValue)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter two integers please: ";
            continue;
        }

        if (domainValue == -1 && codomainValue == -1) {
            break;
        }

        bool inDomain = false;
        for (int value : domain) {
            if (value == domainValue) {
                inDomain = true;
                break;
            }
        }

        if (!inDomain) {
            cout << domainValue << " is not in the domain. Try again.\n";
            continue;
        }

        mappings.push_back(make_pair(domainValue, codomainValue));
    }

    do {
        cout << "\nFunction Checker Menu\n"
                << "1. Check Validity\n"
                << "2. Check Injectivity\n"
                << "3. Check Bijectivity\n"
                << "4. Back to Main Menu\n"
                << "Enter your choice: ";

        while(!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "that... that isn't between 1 and 4... let's try this again";

            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1:
                cout << "Check Validity selected.\n";
                if (isValid(mappings)) {
                    cout << "The mappings form a valid function.\n";
                } else {
                    cout << "The mappings do not form a valid function.\n";
                }
                break;
            case 2:
                cout << "Check Injectivity selected.\n";
                if (isInjective(mappings)) {
                    cout << "The function is injective.\n";
                } else {
                    cout << "The function is not injective.\n";
                }
                break;
            case 3:
                cout << "Check Bijectivity selected.\n";
                if (isBijective(mappings)) {
                    cout << "The function is bijective.\n";
                } else {
                    cout << "The function is not bijective.\n";
                }
                break;
            case 4:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "that... that isn't between 1 and 4... let's try this again\n";
        }
    } while (choice != 4);
}

bool Functions::isValid(const vector<pair<int, int>>& mappings) {
    //tl;dr: if a domain value is mapped to more than one codomain value, then the function is not valid
    map<int, int> seen;

    for (const auto& duo : mappings) {
        int domain = duo.first;
        int codomain = duo.second;

        if (seen.count(domain)) {
            if (seen[domain] != codomain) {
                return false;
            }
        } else {
            seen[domain] = codomain;
        }
    }
     for (const auto& duo : mappings) {
        int domain = duo.first;
        if (seen.count(domain) > 1) {
            return false;
        }
    }

    return true;
}

bool Functions::isInjective(const vector<pair<int, int>>& mappings) {
    // if the function is not valid, it cannot be injective


    if(!isValid(mappings)) return false;
    //tl;dr: if a codomain value is mapped to by more than one domain value, then the function is not injective
    map<int, int> seen;

    for (const auto& duo : mappings) {
        int domain = duo.first;
        int codomain = duo.second;

        if (seen.count(codomain)) {
            if (seen[codomain] != domain) {
                return false;
            }
        } else {
            seen[codomain] = domain;
        }
    }

    return true;
}

bool Functions::isBijective(const vector<pair<int, int>>& mappings) {
    //if the function is valid and injective, then it is bijective
    return isValid(mappings) && isInjective(mappings);
}
