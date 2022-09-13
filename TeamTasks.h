#ifndef TEAMTASKS_H
#define TEAMTASKS_H

#include <map>
#include <unordered_map>
#include <string>

enum class TaskStatus
{
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

using TasksInfo = std::map<TaskStatus, int>;
 
class TeamTasks
{
public:
	// Get statistics on task statuses of a specific developer
	const TasksInfo& GetPersonTasksInfo(const std::string& person) const;


	// Add a new task (in NEW status) for a specific developer
	void AddNewTask(const std::string& person);

	// Update statuses for a given number of issues by a specific developer
	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int task_count);

private:
	std::unordered_map<std::string, TasksInfo> staff;
};


#endif // !TEAMTASKS_H


