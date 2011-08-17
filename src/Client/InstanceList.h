#ifndef INSTANCELIST_H
#define INSTANCELIST_H

#include <list>
#include "PseuWoW.h"

class InstanceList;

class InstanceList
{
	public:
		static InstanceList *get(void);
		
		void push(PseuInstanceRunnable *instance) { _list.push_back(instance); };
		void quitproc(void);
		void abortproc(void);
		
	private:
		std::list<PseuInstanceRunnable*> _list;
};

#endif