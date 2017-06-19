#include <iostream>
#include <map>
#include <vector>
#include <string>


void printArray(char *arr, int size )
{
    for( int i=0; i < size; i++ )
    {
        std::cout<<arr[i];
    }
    std::cout<<std::endl;
}

void permuteUtil(char * letters, int *counts, int lettersCount, char *permutation, int level);

void permuteString(std::vector<char> inputs)
{
    std::map<char,int> charToCount;
    std::vector<char> charset;
    std::vector<int> occCount;

    for(int i=0;i<inputs.size();++i)
    {
        charToCount[inputs[i]]++;
        
    }

    for( std::map<char,int>::iterator itr = charToCount.begin(); itr!= charToCount.end(); ++itr )
    {
        charset.push_back(itr->first);
        occCount.push_back(itr->second);
    }
    int inputSize = inputs.size();
    char *permutation = new char[ inputSize ];

    permuteUtil( &charset[0], &occCount[0],inputSize, permutation, 0 );

}

void permuteUtil(char * letters, int *counts, int lettersCount, char *permutation, int level)
{

    if( level == lettersCount )
    {
        printArray( permutation, lettersCount );
        return ;
    }

    for( int i=0; i < lettersCount; i++ )
    {
        if( counts[i] == 0 )
            continue;

        permutation[level] = letters[i];
        counts[i]--;
        permuteUtil( letters, counts, lettersCount, permutation, level+1);
        counts[i]++;
    }

    return ;

}

int main()
{
    std::vector<char> letters;
    letters.push_back('A');
    letters.push_back('A');
    letters.push_back('B');
    letters.push_back('C');

    permuteString(letters);
}
