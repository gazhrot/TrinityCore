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

class boss_tectus : public CreatureScript {
	public:
		boss_tectus() : CreatureScript("boss_tectus") {}

		struct boss_tectus : public ScriptedAI {
			boss_tectusAI(Creature* creature) : ScriptedAI(creature) {
				Initialize();
			}
		};
}