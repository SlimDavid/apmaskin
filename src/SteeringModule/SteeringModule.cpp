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

//Assumes that the input value is between -63 and +64
void SteeringModule::setSpeed(int8_t desiredSpeed) {

	int8_t engineSpeedLeft = 0;
	int8_t engineSpeedRight = 0;

	if (desiredSpeed < 0) {
		engineSpeedLeft = -desiredSpeed;
		engineSpeedRight = desiredSpeed;
		engineSpeedRight = (engineSpeedRight | 0x80);
		cout << "engineSpeedRight = " << static_cast<int>(engineSpeedRight) << endl
			 << "engineSpeedLeft = "  << static_cast<int>(engineSpeedLeft) << endl;

	}
	else if (desiredSpeed > 0) {
		engineSpeedRight = 0x00;
	}
}
