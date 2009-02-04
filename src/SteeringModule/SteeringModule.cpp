/*
 * SteeringModule.cpp
 *
 *  Created on: 2009-feb-04
 *      Author: pero
 */

#include "SteeringModule.h"
#include "CommandInterpreterModule.h"
#include <iostream>


using namespace std;

SteeringModule::SteeringModule() {
	// TODO Auto-generated constructor stub

}

SteeringModule::~SteeringModule() {
	// TODO Auto-generated destructor stub
}


void SteeringModule::addEventListener(enum IEvent::EventType type, IEventListener* listener) {
}


void SteeringModule::removeEventListener(enum IEvent::EventType type, IEventListener* listener) {
}

void SteeringModule::executeCommand(int cmdID, std::list<int> arguments) {

	if (cmdID == CMD_INCREASE_LEFT) {
	cout << "Vill k�ra v�nster" << endl;
	}
	else if (cmdID == CMD_INCREASE_RIGHT){
		cout << "Vill k�ra h�ger " << endl;
	}
	else {
		cout << "Ok�nt styrkommando " << endl;
	}

}


void SteeringModule::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("increaseleft", CMD_INCREASE_LEFT, this);
	ci->registerCommand("increaseright", CMD_INCREASE_RIGHT, this);
}
