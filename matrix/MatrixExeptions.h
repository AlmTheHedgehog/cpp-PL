#pragma once
#include <exception>
#include <string>

class InvalidMatrixSizeException : public std::exception {
    public:
        std::string what () {
            return "Invalid Matrix Size Exception";
        }
};

class InvalidAllocationException : public std::exception {
    public:
        std::string what () {
            return "Allocation problem!";
        }
};

class IndexOutOfBoundExeption : public std::exception {
    public:
        std::string what () {
            return "Accessing index is out of bound";
        }
};