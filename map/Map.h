/*
*Elements of map have to be sorted by key in ASC order.keys are uniq!
* */

#pragma once
#include <iostream>
#include <string>

template <class KEY, class VAL>
class Map{
    public:
        Map(){
            elementsArr = NULL;
            elementsArrSize = 0;
        }

        Map(const Map &parent){
            elementsArrSize = parent.elementsArrSize;
            elementsArr = new mapElement[elementsArrSize];
            for(int i = 0; i < elementsArrSize; i++){
                elementsArr[i] = parent.elementsArr[i];
            }
        }

        ~Map(){
            delete[] elementsArr;
        }



        void add(KEY newKey, VAL newValue){
            //insert in right place to create ASC sorted arr for bin search;
        }

    private:
        class mapElement{
            public:
                KEY key;
                VAL val;
                mapElement(){};
                mapElement(KEY newKey, VAL newValue):key(newKey), val(newValue){}
                mapElement(const mapElement &parent){
                    key = parent.key;
                    val = parent.val;
                }
        };

        mapElement *elementsArr;
        int elementsArrSize;      
};