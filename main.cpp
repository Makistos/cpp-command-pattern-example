#include <iostream>
#include "main.h"

void CommandAdd::execute() {
	std::cout << "Added " << name_ << std::endl;
}

void CommandRemove::execute() {
	std::cout << "Removed " << id_ << std::endl;
}

void GUI::run(int idx) {
	commands.at(idx)->execute();
}

void GUI::add_command(unsigned idx, const std::shared_ptr<Command> cmd) {
	commands[idx] = cmd;
}

int main(void){
	bool quit = false;
	GUI gui;
	std::string name;
	std::string id;

	while(!quit) {
		std::string input;
		std::cout << "1 Add" << std::endl;
		std::cout << "2 Remove" << std::endl;
		std::cout << "Choice: ";
		getline(std::cin, input);

		switch (std::stoi(input)) {
		case 1: {
				std::cout << "Name: ";
				getline(std::cin, name);
				gui.add_command(0,
						std::make_shared<CommandAdd>(CommandAdd{name}));
			}
			break;
		case 2: {
				std::cout << "ID: ";
				getline(std::cin, id);
				gui.add_command(1,
						std::make_shared<CommandRemove>(CommandRemove{std::stoi(id)}));
			}
			break;
		default:
			quit = true;
			break;
		}
		gui.run(std::stoi(input)-1);
	}
}
