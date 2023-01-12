#pragma once
#include <iostream>
#include <string>

class ElementNotFoundException{};
class ElementAlreadyExistsException{};

template <class KEY, class VAL>
class Map{
    public:
        Map(){
            elementsArr = NULL;
            elementsArrSize = 0;
        }

        Map(const Map &parent){
            copyMap(parent);
        }
        
        Map& operator=(const Map &parent){
            delete[] elementsArr;
            copyMap(parent);
            return *this;
        }

        ~Map(){
            delete[] elementsArr;
        }

        void add(KEY newKey, VAL newValue){
            //insert in right place to create ASC sorted arr for bin search;
            if(elementsArrSize == 0){
                elementsArrSize++;
                elementsArr = new MapElement[elementsArrSize];
                elementsArr->key = newKey;
                elementsArr->val = newValue;
                return;
            }
            try{
                find(newKey);
            }catch(ElementNotFoundException&){
                int index = 0;
                while((index < elementsArrSize) && (newKey > elementsArr[index].key)){
                    index++;
                }
                insertElAtIndex(index, MapElement(newKey, newValue));
                return;
            }
            throw ElementAlreadyExistsException();
        }

        friend std::ostream& operator<<(std::ostream& stream, const Map& dispMap){
            for(int i = 0; i < dispMap.elementsArrSize; i++){
                stream << dispMap.elementsArr[i] << std::endl;
            }
            return stream;
        }

        VAL* find(KEY searchingKey){
            return binarySearch(searchingKey, 0, elementsArrSize-1);
        }

    private:
        class MapElement{
            public:
                KEY key;
                VAL val;
                MapElement(){};
                MapElement(KEY newKey, VAL newValue):key(newKey), val(newValue){}
                MapElement(const MapElement &parent){
                    key = parent.key;
                    val = parent.val;
                }
                friend std::ostream& operator<<(std::ostream& stream, const MapElement& dispEl){
                    return stream << dispEl.key << " - " << dispEl.val;
                }
        };

        void copyMap(const Map &parent){
            elementsArrSize = parent.elementsArrSize;
            elementsArr = new MapElement[elementsArrSize];
            for(int i = 0; i < elementsArrSize; i++){
                elementsArr[i] = parent.elementsArr[i];
            }
        }

        void insertElAtIndex(int index, MapElement element){
            elementsArrSize++;
            MapElement *newElementsArr = new MapElement[elementsArrSize];
            for(int i = 0; i < index; i++){
                newElementsArr[i] = elementsArr[i];
            }
            newElementsArr[index] = element;
            for(int i = index+1; i < elementsArrSize; i++){
                newElementsArr[i] = elementsArr[i-1];
            }
            delete[] elementsArr;
            elementsArr = newElementsArr;
        }

        VAL* binarySearch(const KEY &searchingKey, int leftBorder, int rightBorder){
            if(leftBorder > rightBorder){
                throw ElementNotFoundException();
            }
            int middleIndex = (leftBorder + rightBorder) / 2;
            if(searchingKey == elementsArr[middleIndex].key){
                return &elementsArr[middleIndex].val;
            }else if(searchingKey > elementsArr[middleIndex].key){
                return binarySearch(searchingKey, middleIndex+1, rightBorder);
            }else{
                return binarySearch(searchingKey, leftBorder, middleIndex-1);
            }
        }

        MapElement *elementsArr;
        int elementsArrSize;      
};
