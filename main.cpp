#include <iostream>
using namespace std;

int main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];

    // Start of the program
    cout << "\n\t\t\t\t\tDynamic Memory Allocation - Best Fit Algorithm";
    cout << "\nEnter the number of blocks:";
    cin >> nb;
    cout << "Enter the number of processes:";
    cin >> np;

    // Input block sizes
    cout << "\nEnter the size of the blocks:-\n";
    for (i = 1; i <= nb; i++)
    {
        cout << "Block no." << i << ": ";
        cin >> b[i];
    }

    // Input process sizes
    cout << "\nEnter the size of the processes :-\n";
    for (i = 1; i <= np; i++)
    {
        cout << "Process no. " << i << ": ";
        cin >> p[i];
    }

    // Process allocation based on the Best Fit algorithm
    for (i = 1; i <= np; i++)
    {
        lowest = 9999; // Reset lowest for every process
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1) // Check if block is free
            {
                temp = b[j] - p[i];
                if (temp >= 0 && temp < lowest) // Check if the process can fit and is the best fit
                {
                    lowest = temp;
                    parray[i] = j; // Allocate this block
                }
            }
        }

        if (parray[i] != 0)
        {
            fragment[i] = lowest;              // Store the remaining fragment
            barray[parray[i]] = 1;            // Mark block as used
        }
        else
        {
            fragment[i] = -1; // Indicate that the process was not allocated
        }
    }

    // Output the final allocation
    cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
    for (i = 1; i <= np; i++)
    {
        if (parray[i] != 0)
        {
            cout << "\n\t" << i << "\t\t\t" << p[i] << "\t\t\t\t" << parray[i] << "\t\t\t" << b[parray[i]] << "\t\t\t" << fragment[i];
        }
        else
        {
            cout << "\n\t" << i << "\t\t\t" << p[i] << "\t\t\t\tNot Allocated";
        }
    }

    return 0;
}
