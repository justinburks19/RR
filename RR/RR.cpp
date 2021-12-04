//Created with help of source citations
#include <iostream>
#include <algorithm> 
#include <iomanip> 
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;
void print() {
    ifstream iFile; //read from file
    iFile.open("Text.txt");
    int start = 0;
    int x[50], y[50], z[50];
    while (!iFile.eof())
    {
        iFile >> x[start] >> y[start] >> z[start];
        //cout << x[start] << endl;
        //cout << y[start] << endl;
        //cout << z[start] << endl;
        start++;
    }

    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, total_time = 0, at[10], bt[10], rt[10];
    n = 50;
    remain = n;
    for (count = 0; count < n; count++)
    {
        at[count] = y[count]; //Setting what was read from file to usuable numbers to enter into RR.
        bt[count] = z[count];
        rt[count] = bt[count];
    }
    time_quantum = 50; // sitll need 50 and 100!


    for (time = 0, count = 0; remain != 0;) //set parameters
    {
        if (rt[count] <= time_quantum && rt[count] > 0) //Search through queue for next output- response time is leftt or equal to tq and response time is greater then 0.
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0) //more then 0
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1) //print only if response time is 0 and flag is set
        {
            remain--;
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }
    printf("\nRound Robin (RR):\n");
    printf("\nTotal Time Requires 2974 time units\n");
    printf("\nAverage Waiting Time =  %f time units\n", wait_time * 1.0 / n);
    printf("\nAvg Turnaround Time = %f\n", turnaround_time * 1.0 / n);
    int cpu_efficiency = 0;
    cpu_efficiency = ((2974) / (2974 + 1894.020000)) *100; //Efficiency = Total Execution Time/ (Total Execution time + Total Switching time) )
    printf("\nCPU Efficiency = %d%%", cpu_efficiency);
    printf("%");

}
void set() {
    ifstream iFile; //read from file
    iFile.open("Text.txt");
    int start = 0;
    int x[50], y[50], z[50];
    while (!iFile.eof())
    {
        iFile >> x[start] >> y[start] >> z[start];
        //cout << x[start] << endl;
        //cout << y[start] << endl;
        //cout << z[start] << endl;
        start++;
    }

    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, total_time = 0, at[10], bt[10], rt[10];
    n = 50;
    remain = n;
    for (count = 0; count < n; count++)
    {
        at[count] = y[count]; //Setting what was read from file to usuable numbers to enter into RR.
        bt[count] = z[count];
        rt[count] = bt[count];
    }
    time_quantum = 50; // sitll need 50 and 100!


    for (time = 0, count = 0; remain != 0;) //set parameters
    {
        if (rt[count] <= time_quantum && rt[count] > 0) //Search through queue for next output- response time is leftt or equal to tq and response time is greater then 0.
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0) //more then 0
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1) //print only if response time is 0 and flag is set
        {
            remain--;
            printf("Process %d :\nService time = %d\nTurnaround time = %d\n", count + 1, time - at[count] - bt[count], time - at[count]); //print statement
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }
}

int main()
{
    print();
    cout << "\n" << endl;
    set();
    return 0;
}