#include "TeamTasks.h"

const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person) const
{
	return staff.at(person);
}

void TeamTasks::AddNewTask(const std::string& person)
{
	++staff[person][TaskStatus::NEW];
}

std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const std::string& person, int task_count)
{
	TasksInfo updated_tasks, untouched_tasks, new_tasks;

	for (const auto & element : staff[person])
	{
		if (element.second <= 0) continue;

		int statusCount = element.second;
		switch (element.first)
		{
		case TaskStatus::NEW:
			
			if (statusCount <= task_count) {
				updated_tasks[TaskStatus::IN_PROGRESS] += statusCount;
				new_tasks[TaskStatus::IN_PROGRESS] += statusCount;
				task_count -= statusCount;
			}
			else 
			{
				updated_tasks[TaskStatus::IN_PROGRESS] += task_count;
				new_tasks[TaskStatus::IN_PROGRESS] += task_count;
				new_tasks[TaskStatus::NEW] += statusCount - task_count;
				untouched_tasks[TaskStatus::NEW] += statusCount - task_count;
				task_count = 0;
			}
			break;
		case TaskStatus::IN_PROGRESS:
			if (statusCount <= task_count) {
				updated_tasks[TaskStatus::TESTING] += statusCount;
				new_tasks[TaskStatus::TESTING] += statusCount;
				task_count -= statusCount;
			}
			else
			{
				updated_tasks[TaskStatus::TESTING] += task_count;
				new_tasks[TaskStatus::TESTING] += task_count;
				new_tasks[TaskStatus::IN_PROGRESS] += statusCount - task_count;
				untouched_tasks[TaskStatus::IN_PROGRESS] += statusCount - task_count;
				task_count = 0;
			}
			break;
		case TaskStatus::TESTING:
			if (statusCount <= task_count) {
				updated_tasks[TaskStatus::DONE] += statusCount;
				new_tasks[TaskStatus::DONE] += statusCount;
				task_count -= statusCount;
			}
			else
			{
				updated_tasks[TaskStatus::DONE] += task_count;
				new_tasks[TaskStatus::DONE] += task_count;
				new_tasks[TaskStatus::TESTING] += statusCount - task_count;
				untouched_tasks[TaskStatus::TESTING] += statusCount - task_count;
				task_count = 0;
			}
			break;
		case TaskStatus::DONE:
			new_tasks[TaskStatus::DONE] += statusCount;
		default:
			break;
		}
	}

	staff[person] = std::move(new_tasks);

	return std::make_tuple(updated_tasks, untouched_tasks);
}
