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

class boss_twinogron : public CreatureScript {
	public:
		boss_twinogron() : CreatureScript("boss_twinogron") {}

		struct boss_twinogron : public ScriptedAI {
			boss_twinogronAI(Creature* creature) : ScriptedAI(creature) {
				Initialize();
			}
		};
}