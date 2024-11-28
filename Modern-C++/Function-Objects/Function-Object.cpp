#include <bits/stdc++.h>

using namespace std;

class Compare
{
    public:

    bool operator() (pair <int , int>& task1 , pair <int , int>& task2)
    {
        if(task1.second > task2.second)
        {
            return false;
        }
        else if(task1.second < task2.second)
        {
            return true;
        }
        else
        {
            if(task1.first > task2.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

class TaskManager
{
    private:

    stack <int> tasks;

    queue <int> orders;

    priority_queue < pair <int , int> , vector< pair<int , int> > , Compare > priorityTasks;

    public:

    void addTask(int taskId)
    {
        tasks.push(taskId);
    }

    void removeMostRecentTask()
    {
        tasks.pop();
    }

    void currentTask()
    {
        int currentTaskId = tasks.top();
        cout << "The current task id is: " << currentTaskId << endl;
    }

    void addOrder(int id)
    {
        orders.push(id);
    }

    void currentOrder()
    {
        cout << "The current order id is: " << orders.front() << endl;
    }

    void removeNextOrder()
    {
        orders.pop();
    }

    void addPriorityTask( const pair <int , int>& priorityTask)
    {
        priorityTasks.push(priorityTask);
    }

    void retrieveHighestPriorityTask()
    {
        cout << "The current highest priority task is: (taskId: " << priorityTasks.top().first << " , priority: " << priorityTasks.top().second << ")" << endl;
    }

    void removeHighestPriorityTask()
    {
        priorityTasks.pop();
    }
};

int main()
{
    TaskManager taskManager;

    taskManager.addPriorityTask( {1 , 10} );
    taskManager.addPriorityTask( {2 , 1} );
    taskManager.addPriorityTask( {3 , 11} );
    taskManager.addPriorityTask( {4 , 9} );
    taskManager.addPriorityTask( {5 , 12} );
    taskManager.addPriorityTask( {6 , 7} );

    taskManager.retrieveHighestPriorityTask();

    taskManager.removeHighestPriorityTask();

    taskManager.retrieveHighestPriorityTask();

    return 0;
}