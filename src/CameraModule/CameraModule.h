#ifndef CAMERAMODULE_H_
#define CAMERAMODULE_H_

#include "Event.h"
#include "EventListener.h"
#include "EventGenerator.h"
#include "CommandServer.h"

#include <list>
#include "BoundedBuffer.h"

using namespace std;

class CameraModule : public EventGenerator, CommandServer {
private:
	list<EventListener*> positionErrorListeners;
	list<EventListener*> intersectionFoundListeners;
	list<EventListener*> numberFoundListeners;
	BoundedBuffer<Event>* sendQueue;
public:
	typedef enum {
		CMD_SNAPSHOT,
		CMD_CALIBRATE
	} CameraCommand;

	CameraModule();
	void startSendEvents(BoundedBuffer<Event>& eventQueue);							//EventGenerator
	void stopSendEvents() {};												//EventGenerator
	void executeCommand(int cmdID, std::vector<int> arguments); 			//CommandServer
	void registerCommands();											//CommandServer
};

#endif /* CAMERAMODULE_H_ */
