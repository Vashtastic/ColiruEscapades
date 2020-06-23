#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <climits>
namespace
{
}

//C++ classes are based off from C-Structs
class Review
{
public:
    Review()
    :dataMember1(),
     dataMember2()//default
    {}

    Review(uint8_t a, uint8_t b)
    :dataMember1(a),
     dataMember2(b)
    {}

    ~Review()
    {}

    Review(const Review& review)
    :dataMember1(review.getDataMember1()),
     dataMember2(review.getDataMember2())
    {
        //copy constructor
    }

    Review (Review&& rValueReview)
    {
        //Move Constructor
    }

    const uint8_t getDataMember1() const
    {
        return dataMember1;
    }

    uint8_t getDataMember2() const
    {
        return dataMember2;
    }

     operator std::string() const
     {
         return "[OwO]" + std::to_string(dataMember1) + std::to_string(dataMember2);
     }

    Review& operator++()
    {
        this->dataMember1 += 1;
        this->dataMember2 += 1;
        return *this;
    }

    Review operator++(int) //this
    {
        auto ptr = *this;
        this->dataMember1 += 1;
        this->dataMember2 += 1;
        return ptr;
    }


private:
    uint8_t dataMember1 {};
    uint8_t dataMember2 {};
};


struct x
{
    int y = 0;
    int z = 1;
};

struct another
{
    uint8_t k;
    uint8_t y;
};


void assignPtr(x* ptr)
{
    (*ptr).y = 1;
    (*ptr).z = 2;
}

void qwer(uint64_t g)
{
    uint8_t k[3];
    std::memset(k, 0, sizeof(k));
    memcpy(k, &g, sizeof(k));

    std::cout << "first index is : " << (int)k[0] << std::endl;
}

void qwer(another parmas)
{
    uint8_t k[2];
    std::memset(k, 0, sizeof(k));
    memcpy(k, &parmas, sizeof(k));

    another* key = reinterpret_cast<another*>(k);
    std::cout << (int)key->k << " " << (int)key->y << std::endl;
}

int merge(std::vector<int>& vect, uint32_t l, uint32_t m, uint32_t r)
{
    std::vector<int> leftTemporary(&vect[l], &vect[m + 1]);
    std::vector<int> rightTemporary(&vect[m+1], &vect[r + 1]);

    uint32_t leftIndex = 0;
    uint32_t rightIndex = 0;
    uint32_t initialIndexOfMergedArray = l;
    int numOfInversions = 0;

    while (leftIndex < leftTemporary.size()
           && rightIndex < rightTemporary.size())
    {
        if(leftTemporary[leftIndex] <= rightTemporary[rightIndex])
        {
            vect[initialIndexOfMergedArray] = leftTemporary[leftIndex];
            ++leftIndex;
        }
        else
        {
            vect[initialIndexOfMergedArray] = rightTemporary[rightIndex];
            ++rightIndex;
            numOfInversions += (m - leftIndex);
        }
        ++initialIndexOfMergedArray;
    }

    while(leftIndex < leftTemporary.size())
    {
        vect[initialIndexOfMergedArray] = leftTemporary[leftIndex];
        ++initialIndexOfMergedArray;
        ++leftIndex;
    }

    while(rightIndex < rightTemporary.size())
    {
        vect[initialIndexOfMergedArray] = rightTemporary[rightIndex];
        ++initialIndexOfMergedArray;
        ++rightIndex;
    }

    return numOfInversions;
}

int mergeSort(std::vector<int>& vect, int leftMostIndex, int rightMostIndex)
{
    int numOfInversion = 0;
    if (leftMostIndex < rightMostIndex)
    {
        int midIndex = (leftMostIndex + (rightMostIndex)) / 2;
        numOfInversion += mergeSort(vect, leftMostIndex, midIndex);
        numOfInversion += mergeSort(vect, midIndex+1, rightMostIndex);
        numOfInversion += merge(vect, leftMostIndex, midIndex, rightMostIndex);
    }

    return numOfInversion;
}

std::vector<int> myMerge(std::vector<std::vector<int>>& vect, int firstTupleIndex, int secondTupleIndex, int& inversions)
{
    std::vector<int> OwO;
    int sizeOfFirstTuple = vect[firstTupleIndex].size();
    int sizeOfSecondTuple = vect[secondTupleIndex].size();

    uint8_t countForFirstTuple = 0;
    uint8_t countForSecondTuple = 0;

    std::vector<int> const& firstTuple = vect[firstTupleIndex];
    std::vector<int> const& secondTuple = vect[secondTupleIndex];

    while (countForFirstTuple < sizeOfFirstTuple && countForSecondTuple < sizeOfSecondTuple)
    {
        if (firstTuple[countForFirstTuple] <= secondTuple[countForSecondTuple])
        {
            OwO.emplace_back(firstTuple[countForFirstTuple]);
            ++countForFirstTuple;
        }
        else
        {
            OwO.emplace_back(secondTuple[countForSecondTuple]);
            ++countForSecondTuple;
            ++inversions;
        }
    }

     while (countForFirstTuple < sizeOfFirstTuple)
     {
        OwO.emplace_back(firstTuple[countForFirstTuple]);
        ++countForFirstTuple;
     }

     while (countForSecondTuple < sizeOfSecondTuple)
     {
        OwO.emplace_back(secondTuple[countForSecondTuple]);
        ++countForSecondTuple;
     }

    return OwO;
}

void myMergeSort(std::vector<int>& vect)
{
    std::vector<std::vector<int>> awef {};  //allocating size at una using this will make it extend lmao
    bool isNotFinished = false;

    for (auto cout : vect)
    {
        std::vector<int> awefg {cout};
        awef.emplace_back(awefg);
    }

    int index = 0;
    int inversions = 0;
    while(awef.size() != 1)
    {
       if (index >= awef.size())
       {
           for (auto x : awef)
           {
               for (int k : x)
               {
                std::cout << k << ",";
               }
           }
           std::cout << std::endl;
           index = 0;
       }

       std::vector<int> temp(myMerge(awef, index, index + 1, inversions));
       awef[index] = temp;

       if (index + 1 < awef.size())
       {
          awef.erase(awef.begin() + (index+1));
       }

       ++index;
    }

    vect = awef[0];
    std::cout << "[OwO] The number of inversions is: " << inversions << std::endl;
}

int minSwap(std::vector<uint32_t> arr)
{
    std::vector<uint32_t> sortedArr(arr);
    std::sort(sortedArr.begin(), sortedArr.end());
    uint32_t currentIndex = 0;
    uint32_t numOfSwaps = 0;

    while(!(std::equal(sortedArr.begin(), sortedArr.end(), arr.begin())))
    {
        uint8_t value = arr[currentIndex];
        if (currentIndex != (value - 1))
        {
            uint8_t properIndexOfCurrentValue = value - 1;
            std::swap(arr[currentIndex], arr[properIndexOfCurrentValue]);
            ++numOfSwaps;
        }
        else
        {
            ++currentIndex;
        }
    }

    return numOfSwaps;
}

int main(int argc, char** argv)
{
    // uint64_t awef = 0xABCDEF123567890A;
    // qwer(awef);
    // another kip {4,5};
    // qwer(kip);

    // std::vector<uint8_t> awefs {1,2,3,4};
    // for (auto it = awefs.begin(); it != awefs.end(); ++it)
    // {
    //     int index = it - awefs.begin();
    //     std::cout << index << std::endl;
    // }

    // if(awefs.size() > 5 && awefs[5] == 5)
    // {
    //     std::cout << "[OwO]";
    // }
    // else
    // {
    //     std::cout << "NotOwO";
    // }

    // const Review a {};
    // Review b {};
    // Review c(1,2);

    // std::cout << std::string(c) << std::endl;

    // uint8_t theTest = a.getDataMember1();
    // theTest = 1;


    // std::vector<std::vector<int>> testThis {{1,2,3}, {2,3,4}};

    // std::vector<int> vect {7, 1, 3, 2, 4, 5, 6};
    // for (int x : vect)
    // {
    //     std::cout << x << ",";
    // }
    // std::cout << std::endl;

    // int numOfInv = ::mergeSort(vect, 0, vect.size() -  1);

    // for (int x : vect)
    // {
    //     std::cout << x << ",";
    // }

    // std::cout << std::endl << numOfInv << std::endl;

    std::vector<int> testThis {7, 1, 3, 2 , 4, 5, 6};
    std::vector<uint32_t> test {7, 1, 3, 2 , 4, 5, 6};
    myMergeSort(testThis);
    uint32_t numOfSwaps = minSwap(test);

    for (int x : testThis)
    {
        std::cout << x << ",";
    }

    std::cout << std::endl;
    std::cout << (int)numOfSwaps;
}