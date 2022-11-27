#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile;
    // here we are declaring the object that will represent text file, in this case it is named as infile

    infile.open("71input1.txt");
    // we associate the object called infile with the relevant text file
    // note: the .open and .is_open function that is found later in the code is different

    if (infile.is_open())
    {
        // this function is used to read values within the text file
        int tmp;

        for (int i = 0; i < 4; i++)
        {
            infile >> tmp;
            std::cout << tmp << std::endl;
        }
        // a for loop is required for this to run as the file only reads one value at a time with the int tmp function

        infile.close();
        // we must remember to close the file when we are done
    }

    else
    {
        std::cout << "error opening file" << std::endl;
    }
}
