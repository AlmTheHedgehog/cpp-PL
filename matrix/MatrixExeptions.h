#pragma once
#include <exception>
#include <string>

class InvalidMatrixSizeException : public std::exception {
    public:
        std::string what () {
            return "Invalid Matrix Size Exception";
        }
};

class DifferentMatrixSizeException : public std::exception {
    public:
        std::string what () {
            return "Impossible to compare matrix with different size";
        }
};

class InvalidAllocationException : public std::exception {
    public:
        std::string what () {
            return "Allocation problem!";
        }
};

class IndexOutOfBoundException : public std::exception {
    public:
        std::string what () {
            return "Accessing index is out of bound";
        }
};

class WrongInputMatrixDataException : public std::exception {
    public:
        std::string what () {
            return "Impossible to read matrix from file. \
            Wrong matrix data in file or way of reading it";
        }
};

class IOException : public std::exception {
    public:
        std::string what () {
            return "File accessing exeption";
        }
};