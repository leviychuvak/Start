#include "TeamTasks.h"

const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person) const
{
	return staff.at(person);
}

void TeamTasks::AddNewTask(const std::string& person)
{
	++staff[person][TaskStatus::NEW];
}

TaskStatus getNextStatus(TaskStatus ts) {
	return static_cast<TaskStatus>(static_cast<int>(ts) + 1);
}

void lessThanCounter(const int statusCount, int & taskCount, TasksInfo & updatedT, TasksInfo& newT, TaskStatus ts) {
	updatedT[getNextStatus(ts)] += statusCount;
	newT[getNextStatus(ts)] += statusCount;
	taskCount -= statusCount;
}
void moreThanCounter(const int statusCount, int& taskCount, TasksInfo& updatedT, TasksInfo& newT, TasksInfo& untouchedT, TaskStatus ts) {
	updatedT[getNextStatus(ts)] += taskCount;
	newT[getNextStatus(ts)] += taskCount;
	newT[ts] += statusCount - taskCount;
	untouchedT[ts] += statusCount - taskCount;
	taskCount = 0;
}

std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const std::string& person, int task_count)
{
	auto& currentPerson = staff[person];
	TasksInfo updated_tasks, untouched_tasks, new_tasks;

	for (const auto& [taskStatus, statusCount] : currentPerson)
	{
		if (statusCount <= 0) continue;

		switch (taskStatus)
		{
		case TaskStatus::NEW:
		case TaskStatus::IN_PROGRESS:
		case TaskStatus::TESTING:
			if (statusCount <= task_count) {
				lessThanCounter(statusCount, task_count, updated_tasks, new_tasks, taskStatus);
			}
			else 
			{
				moreThanCounter(statusCount, task_count, updated_tasks, new_tasks, untouched_tasks, taskStatus);
			}
			break;
		case TaskStatus::DONE:
			new_tasks[TaskStatus::DONE] += statusCount;
		default:
			break;
		}
	}

	currentPerson = std::move(new_tasks);

	return std::make_tuple(updated_tasks, untouched_tasks);
}
