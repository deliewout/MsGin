#pragma once
#include <Command.h>
class MuteCommand : public Command
{
public:
	MuteCommand()=default;
	~MuteCommand() = default;
	MuteCommand(const MuteCommand& other) = delete;
	MuteCommand(MuteCommand&& other) = delete;
	MuteCommand& operator=(const MuteCommand& other) = delete;
	MuteCommand& operator=(MuteCommand&& other) = delete;

	virtual void Execute() override;
};

