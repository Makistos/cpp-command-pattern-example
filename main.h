#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <array>
#include <memory>

class Command {
	public:
		Command() {}
		virtual void execute() = 0;
		~Command() {}

};

class CommandAdd : public Command {
	public:
		CommandAdd() = delete;
		CommandAdd(std::string name) :
			name_{name} {}
		virtual void execute() override;
	private:
		std::string& name_;
};

class CommandRemove : public Command {
	public:
		CommandRemove() = delete;
		CommandRemove(int id) :
			id_{id} {}
		virtual void execute() override;
	private:
		int id_;
};

class GUI {
	public:
		void run(int idx);
		void add_command(unsigned idx, const Command& cmd);
	private:
		std::array<std::shared_ptr<Command>, 2> commands;
};

#endif
