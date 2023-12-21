#include <iostream>
#include <vector>
#include <algorithm>
 
struct Job {
    int processingTime[2];
    int index;
};
 
bool compareJobs(const Job& jobA, const Job& jobB) {
    if (jobA.processingTime[0] <= jobA.processingTime[1]) {
        if (jobB.processingTime[0] <= jobB.processingTime[1]) {
            return jobA.processingTime[0] < jobB.processingTime[0];
        }
        return true;
    }
    else {
        if (jobB.processingTime[0] <= jobB.processingTime[1]) {
            return false;
        }
        return jobB.processingTime[1] < jobA.processingTime[1];
    }
}
 
int main() {
    int n;
    std::cout << "Enter the number of jobs: ";
    std::cin >> n;
 
    std::vector<Job> jobs(n);
    std::cout << "Enter the processing times:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> jobs[i].processingTime[0] >> jobs[i].processingTime[1];
        jobs[i].index = i + 1;
    }
 
    std::sort(jobs.begin(), jobs.end(), compareJobs);
 
    std::cout << "Optimal schedule: ";
    for (const auto& job : jobs) {
        std::cout << job.index << " ";
    }
    std::cout << std::endl;
 
    return 0;
}