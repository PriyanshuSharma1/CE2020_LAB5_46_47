/*
Authors names: Priyanshu Sharma, Soniya Sharma
Date created : November 21, 2022
Sorting randomly generated array using merge sort and quick sort
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "sorting.cpp"
using namespace std; //declaring std on global namespace
int main()
{
    double t1, t2;

    fstream fout;

    // creates a new file.
    fout.open("random.csv", ios::out | ios::app);

    fout << "Random"
         << " ,"
         << "Insertionsort_time"
         << " ,"
         << "Ouicksort_time " << endl;
    for (length = 10000; length <= max_length;)
    {
        int *listForInsert = new int[length];
        int *listForQuick = new int[length];
        srand(time(0));
        for (int i = 0; i < length; i++)
        {

            listForInsert[i] = rand() % length;
            listForQuick[i] = rand() % length;
        }
        cout << "\nLength\t: " << length << '\n';
        auto starttime = chrono::system_clock::now();
        insertionSort(listForInsert, length);
        auto endtime = chrono::system_clock::now();

        chrono::duration<double> timetaken_insertion = endtime - starttime;
        time_t end_insertion = chrono::system_clock::to_time_t(endtime);
        time_t start_insertion = chrono::system_clock::to_time_t(starttime);

        cout << "ArraySize_insertion : " << length << endl;
        cout << "TimeTaken_insertion:" << timetaken_insertion.count() << endl;
        cout << "Insertion Sort starts at " << ctime(&start_insertion)
             << "Insertion Sort ends at " << ctime(&end_insertion)
             << endl;

        auto startquick = std::chrono::system_clock::now();
        quickSort(listForQuick, 0, length - 1);

        auto endquick = std::chrono::system_clock::now();
        chrono::duration<double> timetaken_quick = endquick - startquick;
        time_t end_quick = chrono::system_clock::to_time_t(endquick);
        time_t start_quick = chrono::system_clock::to_time_t(startquick);

        cout << "ArraySize_quick : " << length << endl;
        cout << "TimeTaken_quick:" << timetaken_quick.count() << endl;
        cout << "Quick Sort starts at " << ctime(&start_quick)
             << "Quick Sort ends at " << ctime(&end_quick)
             << endl;

        fout << length << " ," << timetaken_insertion.count() << " ," << timetaken_quick.count() << endl;

        length = length + 10000;
        delete[] listForInsert;
        delete[] listForQuick;
    }
    return 0;
}