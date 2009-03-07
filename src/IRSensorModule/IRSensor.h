/*
 * IRSensor.h
 *
 *  Created on: 2009-mar-03
 *      Author: bege
 */

#ifndef IRSENSOR_H_
#define IRSENSOR_H_

#include "IEventGenerator.h"
#include "ICommandServer.h"
#include <list>

class IRSensor: /*public IEventGenerator,*/ public ICommandServer {
public:
	IRSensor();
	virtual void executeCommand(int cmdID, std::list<int> arguments);
	virtual void registerCommands();

	virtual ~IRSensor();

private:
	typedef enum {
		CMD_IRPING
	} IRSensorCommand;

	int irping(std::list<int> arguments);
};

#endif /* IRSENSOR_H_ */