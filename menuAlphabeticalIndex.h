//
// Created by Ilyas on 06.12.2021.
//

#ifndef LAB2_MENUALPHABETICALINDEX_H
#define LAB2_MENUALPHABETICALINDEX_H
#include "AlphabeticalIndex.h"
#include "menuFunc.h"
using namespace std;

void printMenu(){
    cout << "to fill alphabetical index manually - 1" << endl;
    cout << "to fill alphabetical index automatically - 2" << endl;
    cout << "to free alphabetical index - 3" << endl;
    cout << "to set number of pages - 4 (extra pages will be deleted)" << endl;
    cout << "to set number of elements - 5" << endl;
    cout << "to print alphabetical index - 6" << endl;
    cout << "to quit - 7" << endl;
}


void fillAlphabeticalIndexManually(AlphabeticalIndex& alphabeticalIndex){
    std::string inputString;
    int numberOfElementsInThePage;

    cout << "Enter your string" << endl;
    getline(cin, inputString);
    getline(cin, inputString);

    cout << "Enter number of elements in the page\n";
    std::cin >> numberOfElementsInThePage;

    alphabeticalIndex.freeAlphabeticalIndex();
    alphabeticalIndex.setNumberOfElementsOnThePage(numberOfElementsInThePage);
    alphabeticalIndex.setNewString(inputString);

}

void fillAlphabeticalIndexAutomatically(AlphabeticalIndex& alphabeticalIndex){

    std::string inputString;
    int numberOfElementsInThePage;

    inputString = randomStringWithSpace(20);
    numberOfElementsInThePage = randomLengthInRange(40,maxNumberOfElementsOnThePage);

    alphabeticalIndex.setNumberOfElementsOnThePage(numberOfElementsInThePage);
    alphabeticalIndex.setNewString(inputString);
    cout << "Random string is " << inputString << endl;


}


void setNumberOfPages(AlphabeticalIndex& alphabeticalIndex){
    if (alphabeticalIndex.getNumberOfPages() == 0){
        cout << "Firstly set the number of elements on the page" << endl;
        return;
    }
    int numberOfPages;
    cout << "Enter number of pages" << endl;
    std::cin >> numberOfPages;
    alphabeticalIndex.setNumberOfPages(numberOfPages);
}

void setNumberOfElements(AlphabeticalIndex& alphabeticalIndex){
    int numberOfElements;
    cout << "Enter number of elements on the page" << endl;
    std::cin >> numberOfElements;
    alphabeticalIndex.setNumberOfElementsOnThePage(numberOfElements);
}





void menuAlphabeticalIndex(){
    AlphabeticalIndex alphabeticalIndex;
    int manageNumber;
    while(true){
        printMenu();
        manageNumber = getNumberInRange(1,7);
        switch(manageNumber){
            case 1:fillAlphabeticalIndexManually(alphabeticalIndex);break;
            case 2:fillAlphabeticalIndexAutomatically(alphabeticalIndex);break;
            case 3:alphabeticalIndex.freeAlphabeticalIndex();break;
            case 4:setNumberOfPages(alphabeticalIndex);break;
            case 5:setNumberOfElements(alphabeticalIndex);break;
            case 6:alphabeticalIndex.printAlphabeticalIndex();break;
            case 7:return;
        }
    }
}


#endif //LAB2_MENUALPHABETICALINDEX_H
