/*
 * Copyright (C) 2016 Gazhrot
 *
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Texts {

};

enum Spells {

};

enum Events {

};

class boss_brackenspore : public CreatureScript {
	public:
		boss_brackenspore() : CreatureScript("boss_brackenspore") {}

		struct boss_brackenspore : public ScriptedAI {
			boss_brackensporeAI(Creature* creature) : ScriptedAI(creature) {
				Initialize();
			}
		};
}