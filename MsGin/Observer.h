#pragma once

namespace dae
{
	enum class Events;
	class Subject;
	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void Notify(Events event, Subject* subject) = 0;

	};
}