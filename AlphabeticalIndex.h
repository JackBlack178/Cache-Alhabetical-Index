//
// Created by Ilyas on 05.12.2021.
//

#ifndef LAB2_ALPHABETICALINDEX_H
#define LAB2_ALPHABETICALINDEX_H

#include "arraySequence.h"
#include "Element.h"
#include "errors.h"

class WordInfo{
private:
    int pageNumber = 0;
    int numberOfThisWordOnThePage = 0;
public:
    WordInfo() = default;

    WordInfo(int newPageNumber, int newNumberOfElementInThePage){
        numberOfThisWordOnThePage = newNumberOfElementInThePage;
        pageNumber = newPageNumber;
    }

    friend std::ostream& operator<< (std::ostream &print, WordInfo &word1){
        return std::cout << "Page " << word1.pageNumber << " Number is " << word1.numberOfThisWordOnThePage;
    }
    
    int getPageNumber() const{
        return pageNumber;
    }
    
    int getNumberOfItemOnThePage() const{
        return numberOfThisWordOnThePage;
    }
};




class AlphabeticalIndex {
private:
    int numberOfPages = 0;     // -1 means value not defined for printing out
    int numberOfElementsInThePage = 0 ;
    arraySequence<Element<std::string,WordInfo>>wordDictionary;


    arraySequence<std::string> splitIntoWords(const std::string& allText){
        arraySequence<std::string>array;
        std::string str;
        for (int i = 0; i < allText.size(); i++){
            if (allText[i] == ' '){
                if (str.size() != 0) {
                    array.append(str);

                }
                str = "";
                continue;
            }
            str+=allText[i];


        }
        if (str.size() != 0)
            array.append(str);

        return array;
    }

    int numberOfWordsInThePage(arraySequence<std::string> word, int startWord, int page) const{
        int numberOfWordsAcceptable;
        if (page == 1){
            numberOfWordsAcceptable = numberOfElementsInThePage / 2;
        }
        else if (page % 10 == 0){
            numberOfWordsAcceptable = numberOfElementsInThePage * 3/4;
        }
        else{
            numberOfWordsAcceptable = numberOfElementsInThePage;
        }

        int numberOfWords = 0;
        int numberOfCalculatedSymbols = 0;
        for (int i = startWord; i < word.getLength(); i++){
            numberOfCalculatedSymbols+= word.get(i).size();
            if (numberOfCalculatedSymbols <= numberOfWordsAcceptable){
                numberOfWords++;
                numberOfCalculatedSymbols++;
            }
        }
        return numberOfWords;
    }

    int checkWordsSize(std::string myWord){
        return numberOfElementsInThePage >= myWord.size();
    }

    void fillWordsArray(arraySequence<std::string>word){
        int page = 1;
        int counter = 1;
        for (int i = 0; i < word.getLength();){  //

            if (not checkWordsSize(word.get(i))){
                throw SomeWordsCanNotBePlacedOnThePage();
            }

            int numberOfElements = numberOfWordsInThePage(word,i, page);

            if (numberOfElements == 0){
                page++;
                counter = 1;
                numberOfElements = numberOfWordsInThePage(word,i, page);

            }

            for (int j = i; j < numberOfElements + i; j++){
                WordInfo newWordInfo(page,counter);
                Element<std::string,WordInfo>newWordElement(word.get(j),newWordInfo);
                wordDictionary.append(newWordElement);
                counter++;
            }

            i+=numberOfElements;
            counter = 1;
            page++;
        }
        numberOfPages = page;
    }

    void writeWordsPrivateByNumberOfSymbols(const std::string& allText){
        arraySequence<std::string> word = splitIntoWords(allText);// Array of wordDictionary
        fillWordsArray(word);
    }



public:
    explicit AlphabeticalIndex(const std::string& allText,int numberOfElements){
        numberOfElementsInThePage = numberOfElements;
        writeWordsPrivateByNumberOfSymbols(allText);
    }

    AlphabeticalIndex() = default;

    void printAlphabeticalIndex(){
        std::cout << wordDictionary;
    };
    
    void freeAlphabeticalIndex(){
        numberOfPages = 0;
        wordDictionary.remove();
    }
    
    int getNumberOfPages() const{
        return numberOfPages;
    }
    
    int getNumberOfElementsInThePage() const{
        return numberOfElementsInThePage;
    }
    
    void setNumberOfPages(int newNumberOfPages){
        numberOfPages = newNumberOfPages;
        int counter = 0;
        for(int i = 0; i < wordDictionary.getLength(); i++){
            if (wordDictionary.get(i).getValue().getPageNumber() > newNumberOfPages){
                counter++;
            }
        }
        for(int i = 0; i < counter; i++){
            wordDictionary.pop();
        }
    }

    void setNumberOfElementsOnThePage(int newNumberOfElementsOnThePage){
        numberOfElementsInThePage = newNumberOfElementsOnThePage;
        arraySequence<std::string>array;
        for(int i = 0; i < wordDictionary.getLength(); i++){
            array.append(wordDictionary.get(i).getKey());
        }
        wordDictionary.remove();
        fillWordsArray(array);
    }

    void setNewString(const std::string& allText){
        arraySequence<std::string> word = splitIntoWords(allText);// Array of wordDictionary
        fillWordsArray(word);
    }
};


#endif //LAB2_ALPHABETICALINDEX_H
