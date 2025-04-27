#include <iostream>
#include <vector>
#include <limits>
#include "Scheduler.h"
#include "UAV.h"
#include "Task.h"

// Function prototypes
void initializeScheduler(Scheduler& scheduler);
void createUAVFleet(Scheduler& scheduler);
void createTasks(Scheduler& scheduler);
double getValidatedInput(const std::string& prompt, double minValue = -std::numeric_limits<double>::max(), double maxValue = std::numeric_limits<double>::max());

int main() {
    try {
        // Initialize the Scheduler
        Scheduler scheduler;
        initializeScheduler(scheduler);
        
        // Create UAV fleet
        createUAVFleet(scheduler);
        
        // Create tasks
        createTasks(scheduler);
        
        // Allocate tasks
        scheduler.allocateTasks();
        
        // Check refuel needs
        scheduler.checkRefuel();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

void initializeScheduler(Scheduler& scheduler) {
    std::cout << "=== Scheduler Initialization ===\n";
    double refuelThreshold = getValidatedInput("Enter refuel threshold (energy units): ", 0.0);
    double refuelX = getValidatedInput("Enter refuel station X position: ");
    double refuelY = getValidatedInput("Enter refuel station Y position: ");
    
    scheduler = Scheduler(refuelThreshold, refuelX, refuelY);
}

void createUAVFleet(Scheduler& scheduler) {
    std::cout << "\n=== UAV Fleet Creation ===\n";
    int numUAVs = static_cast<int>(getValidatedInput("Enter number of UAVs: ", 1));
    
    for (int i = 0; i < numUAVs; ++i) {
        std::cout << "\nUAV #" << (i + 1) << ":\n";
        int id = static_cast<int>(getValidatedInput("  Enter UAV ID: ", 0));
        double weightCap = getValidatedInput("  Enter weight capacity: ", 0.1);
        double energyCap = getValidatedInput("  Enter energy capacity: ", 0.1);
        double startX = getValidatedInput("  Enter starting X position: ");
        double startY = getValidatedInput("  Enter starting Y position: ");
        
        scheduler.uavs.emplace_back(id, weightCap, energyCap, startX, startY);
    }
}

void createTasks(Scheduler& scheduler) {
    std::cout << "\n=== Task Creation ===\n";
    int numTasks = static_cast<int>(getValidatedInput("Enter number of tasks: ", 1));
    
    for (int i = 0; i < numTasks; ++i) {
        std::cout << "\nTask #" << (i + 1) << ":\n";
        int id = static_cast<int>(getValidatedInput("  Enter task ID: ", 0));
        double posX = getValidatedInput("  Enter X position: ");
        double posY = getValidatedInput("  Enter Y position: ");
        double deadline = getValidatedInput("  Enter deadline: ", 0.1);
        double initValue = getValidatedInput("  Enter initial value: ", 0.1);
        double decayRate = getValidatedInput("  Enter decay rate: ", 0.0, 1.0);
        
        scheduler.tasks.emplace_back(id, posX, posY, deadline, initValue, decayRate);
    }
}

double getValidatedInput(const std::string& prompt, double minValue, double maxValue) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= minValue && value <= maxValue) {
                return value;
            }
            std::cout << "Error: Value must be between " << minValue << " and " << maxValue << "\n";
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Please enter a valid number\n";
        }
    }
}





// ---------------------------------->


#include<bits/stdc++.h>
#include "Scheduler.h"
#include "UAV.h"
#include "Task.h"

// Function prototypes
void initializeScheduler(Scheduler &scheduler);
void createUAVFleet(Scheduler &scheduler);
void createTasks(Scheduler &scheduler);
double getValidatedInput(const std::string &prompt, double minValue = -std::numeric_limits<double>::max(), double maxValue = std::numeric_limits<double>::max());

int main()
{
    try
    {
        // Initialize the Scheduler
        // Scheduler scheduler;
        // initializeScheduler(scheduler);

        // Create UAV fleet
        // createUAVFleet(scheduler);

        // Create tasks
        // createTasks(scheduler);

        // Allocate tasks
        // scheduler.allocateTasks();

        // Check refuel needs
        // scheduler.checkRefuel();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void initializeScheduler(Scheduler &scheduler)
{
    std::cout << "=== Scheduler Initialization ===\n";
    double refuelThreshold = getValidatedInput("Enter refuel threshold (energy units): ", 0.0);
    double refuelX = getValidatedInput("Enter refuel station X position: ");
    double refuelY = getValidatedInput("Enter refuel station Y position: ");

    scheduler = Scheduler(refuelThreshold, refuelX, refuelY);
}

void createUAVFleet(Scheduler &scheduler)
{
    std::cout << "\n=== UAV Fleet Creation ===\n";
    int numUAVs = static_cast<int>(getValidatedInput("Enter number of UAVs: ", 1));

    for (int i = 0; i < numUAVs; ++i)
    {
        std::cout << "\nUAV #" << (i + 1) << ":\n";
        int id = static_cast<int>(getValidatedInput("  Enter UAV ID: ", 0));
        double weightCap = getValidatedInput("  Enter weight capacity: ", 0.1);
        double energyCap = getValidatedInput("  Enter energy capacity: ", 0.1);
        double startX = getValidatedInput("  Enter starting X position: ");
        double startY = getValidatedInput("  Enter starting Y position: ");

        scheduler.uavs.emplace_back(id, weightCap, energyCap, startX, startY);
    }
}

void createTasks(Scheduler &scheduler)
{
    std::cout << "\n=== Task Creation ===\n";
    int numTasks = static_cast<int>(getValidatedInput("Enter number of tasks: ", 1));

    for (int i = 0; i < numTasks; ++i)
    {
        std::cout << "\nTask #" << (i + 1) << ":\n";
        int id = static_cast<int>(getValidatedInput("  Enter task ID: ", 0));
        double posX = getValidatedInput("  Enter X position: ");
        double posY = getValidatedInput("  Enter Y position: ");
        double deadline = getValidatedInput("  Enter deadline: ", 0.1);
        double initValue = getValidatedInput("  Enter initial value: ", 0.1);
        double decayRate = getValidatedInput("  Enter decay rate: ", 0.0, 1.0);

        scheduler.tasks.emplace_back(id, posX, posY, deadline, initValue, decayRate);
    }
}

double getValidatedInput(const std::string &prompt, double minValue, double maxValue)
{
    double value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            if (value >= minValue && value <= maxValue)
            {
                return value;
            }
            std::cout << "Error: Value must be between " << minValue << " and " << maxValue << "\n";
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Please enter a valid number\n";
        }
    }
}
