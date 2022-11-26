#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
int length = 1000;
const int max_length = 500000;

void insertionSort(int list[], int ArraySize)
{

    int i, key, j;
    for (i = 1; i < ArraySize; i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}
// define qiucksort function

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
        int *list = new int[length];

        for (int i = 0; i < length; i++)
        {
            srand(time(NULL));
            list[i] = rand() % 1000;
        }
        cout << "\nLength\t: " << length << '\n';

        auto starttime = chrono::system_clock::now();
        insertionSort(list, length);
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
        // quick sort function call
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
    }
    return 0;
}