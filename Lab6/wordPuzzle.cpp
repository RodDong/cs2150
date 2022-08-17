#include "hashTable.h"
#include "timer.h"
#include <iostream>
#include <fstream>

using namespace std;

char grid[500][500];

bool checkprime(unsigned int p)
{
    if (p <= 1) // 0 and 1 are not primes; the are both special cases
        return false;
    if (p == 2) // 2 is prime
        return true;
    if (p % 2 == 0) // even numbers other than 2 are not prime
        return false;
    for (int i = 3; i * i <= p; i += 2) // only go up to the sqrt of p
        if (p % i == 0)
            return false;
    return true;
}

int getNextPrime(unsigned int n)
{
    while (!checkprime(++n))
        ;
    return n; // all your primes are belong to us
}

string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols)
{
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear();      // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++)
    {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0)
        {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir)
        { // assumes grid[0][0] is in the upper-left
        case 0:
            r--;
            break; // north
        case 1:
            r--;
            c++;
            break; // north-east
        case 2:
            c++;
            break; // east
        case 3:
            r++;
            c++;
            break; // south-east
        case 4:
            r++;
            break; // south
        case 5:
            r++;
            c--;
            break; // south-west
        case 6:
            c--;
            break; // west
        case 7:
            r--;
            c--;
            break; // north-west
        }
    }

    return output;
}

bool readInGrid(string filename, int &rows, int &cols)
{
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open())
    {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        // cout << endl;
    }
    return true;
}

bool readInWords(string filename, hashTable &table)
{
    string line;
    string word;
    ifstream file(filename);
    if (!file.is_open())
        return false;
    while (getline(file, line))
    {
        word = line;
        table.insert(word);
    }
    file.close();
    return true;
}

int main(int argc, char *argv[])
{
    string dict = argv[1];
    string grid = argv[2];
    hashTable hash(getNextPrime(20000));
    readInWords(argv[1], hash);
    int rows, cols;

    // attempt to read in the file
    bool result = readInGrid(argv[2], rows, cols);
    // if there is an error, report it
    if (!result)
    {
        cout << "Error reading in file!" << endl;
        return 1;
    }
    string directions[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    int count = 0;
    timer t;
    t.start();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int m = 0; m < 8; m++)
            {
                for (int n = 3; n < 30; n++)
                {
                    string check = getWordInGrid(i, j, m, n, rows, cols);
                    if (hash.check(check))
                    {
                        count += 1;
                        cout << directions[m]
                             << " (" << i << ", " << j << "): " << check << endl;
                    }
                    if (getWordInGrid(i, j, m, n+1, rows, cols) == check)
                        break;
                }
            }
        }
    }
    t.stop();
    cout << count << " words found" << endl;
    //cout << "Found all words in " << t << " seconds" << endl;
    // cout<<int(t.getTime()*1000);
    // cout<<hash.minlength()<<endl;
    // cout<<hash.maxlength()<<endl;
    // cout<<hash.maxHash()<<endl;
    // cout<<hash.minHash()<<endl;
    // cout<<"total length: "<<hash.length()<<endl;
    return 0;

    // for(int i = 0; i<hash.elementCount; i++){
    //     int size  = hash.v[i].size();
    //     for(int j = 0; j<hash.v[i].size(); j++){
    //         auto s= hash.v[i].begin();
    //         advance(s, j);
    //         cout<<*s<<endl;
    //     }
    // }
    // cout<<hash.v.size()<<endl;
}
