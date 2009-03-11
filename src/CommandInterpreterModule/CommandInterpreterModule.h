#ifndef COMMANDINTERPRETERMODULE_H_
#define COMMANDINTERPRETERMODULE_H_

#include <string>
#include <map>
#include <vector>
#include "CommandServer.h"


class CommandInterpreterModule: public CommandServer {
private:
	class CommandData;
	typedef std::map<std::string, CommandData *> CommandMap;
	typedef enum {
		CMD_HELP, CMD_EXIT
	} CommandInterpreterCommand;

	static CommandInterpreterModule *ciInstance;
	bool running;
	CommandMap registeredCommands;
protected:
	CommandInterpreterModule();
	CommandInterpreterModule(const CommandInterpreterModule&);
	CommandInterpreterModule& operator=(const CommandInterpreterModule&);
	int extractCommandAndParameters(std::string inputLine, std::string &command, std::vector<int> &args);
public:
	static CommandInterpreterModule* getInstance();
	static void destroy();
	void executeCommand(int cmdID, std::vector<int> arguments); //CommandServer
	void registerCommands(); //CommandServer
	virtual ~CommandInterpreterModule();
	void registerCommand(std::string commandString, int cmdID, CommandServer * const cmdServer);
	void start();
};

class CommandInterpreterModule::CommandData {
private:
	CommandServer* const m_cmdServer;
	int m_cmdID;
public:
	CommandData(int cmdID, CommandServer * const cmdServer) : m_cmdServer(cmdServer), m_cmdID(cmdID) {};
	int getCmdID() {
		return m_cmdID;
	}
	CommandServer* const getCmdServer() {
		return m_cmdServer;
	}
};

#endif /*COMMANDINTERPRETERMODULE_H_*/
