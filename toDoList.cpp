// toDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// rethinking my current aproch i see that this is not object oriented at its just one big function that could be far more readable if refactored
// things that can be devided up, the 1 2 and 3 actions should be void functions
// loop in main to just initiate new actions???

vector <string> tasks(0);// should be 0 but increased for testing as my for loop wasnt working line 25

void printMenu()
{
    cout << "1. view your tasks" << endl;
    cout << "2. add a task" << endl;
    cout << "3. delete a task" << endl;
    cout << "4. close app" << endl;
}

void viewTasks()
{
    int i;
    cout << "tasks left: " << tasks.size() << endl;
    for (i = 0; i < tasks.size(); i++)
    {
        cout << i+1 << ". " << tasks.at(i) << endl;
    }
    cout << endl;
}

void addTask()
{
    string newTask;
    cout << "write your new task: ";
    getline(cin, newTask);
    cout << endl;
    tasks.push_back(newTask);
}

void deleteTask() // i think the switch was a good idea but it neeeds exact values and i cant do that for greater than 1, so probably going to need if else if? :(
{
    int numOfTasks = tasks.size();
    int selectedTask;
    if (numOfTasks == 0)
        {
            cout << "you have no tasks" << endl;
        }else if (numOfTasks == 1)
        {
            cout << "want to delete the only task? 1 for yes, 2 for no: ";
            cin >> selectedTask;
            if (selectedTask == 1)
            {
                tasks.clear();
            }
            else { cout << "left single task alone" << endl << endl; }

        } else 
        {
            cout << "select 1- " << numOfTasks << " for which task you want deleted: ";
            cin >> selectedTask;
            cout << endl << selectedTask << endl;
            tasks.erase(tasks.begin() + (selectedTask - 1));
        }
    /*
    int numSelected;
    cout << "which task would you like to delete? 1-" << tasks.size() << ": ";
    cin >> numSelected;
    cout << "you picked: " << numSelected << endl;*/
    
    
}

int main()
{
    int choice = 0;
    while (choice != 4)
    {
        printMenu();
        cout << "choose between 1-4: ";
        cin >> choice;
        cout << endl;
        cin.ignore(); //clear line ig

        switch (choice)
        {
            case 1:
                viewTasks();
                //cout << endl;
                break;
            case 2:
                addTask();
                break;
            case 3:
                deleteTask();
                break;

            default: cout << "could not read your choice" << endl; // not intended number goes ok but any letter breaks it idk why
        }
    }
    

    return 0;
}