#include <iostream>
#include <vector>
#include <array>
#include <string>

constexpr int ALPHABET_SIZE = 26;
constexpr int STRING_SIZE = 3;
typedef std::array<std::vector<std::string>, ALPHABET_SIZE> BucketArray;
typedef std::vector<std::string> StringArray;

BucketArray MakeBuckets(StringArray stringArray, int round)
{
    BucketArray buckets;

    for (const auto &string : stringArray)
    {
        char letter = string.at(round);
        int index = letter - 'a';
        buckets.at(index).push_back(string);
    }

    return buckets;
}

// void DoBucketRounds(StringArray stringArray, int round, StringArray &input)
// {
//     if (round <= 0)
//     {
//         int indexCounter = 0;

//         for (const auto &string : stringArray)
//         {
//             input.at(indexCounter) = string;
//             indexCounter++;
//         }

//         return;
//     }

//     BucketArray topLevelBuckets = MakeBuckets(stringArray, round);

//     for (const auto &bucketStringArray : topLevelBuckets)
//     {
//         DoBucketRounds(bucketStringArray, round - 1, input);
//     }
// }

int main(int argc, char const *argv[])
{
    StringArray input = {"hel", "wha", "eee", "wya", "abc", "bac", "wow", "ate", "now", "zzz"};

    int indexCounter = 0;
    BucketArray topLevelBuckets = MakeBuckets(input, 0);

    for (const auto &b1 : topLevelBuckets)
    {
        BucketArray midLevelBuckets = MakeBuckets(b1, 1);

        for (const auto &b2 : midLevelBuckets)
        {
            BucketArray bottomLevelBuckets = MakeBuckets(b2, 2);

            for (const auto &stringArray : bottomLevelBuckets)
            {
                for (const auto &string : stringArray)
                {
                    input.at(indexCounter) = string;
                    indexCounter++;
                }
            }
        }
    }

    for (const auto &s : input)
    {
        std::cout << s << " ";
    }

    std::cout << std::endl;

    return 0;
}
