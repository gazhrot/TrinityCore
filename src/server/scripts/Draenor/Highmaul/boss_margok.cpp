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

class boss_margok : public CreatureScript {
	public:
		boss_margok() : CreatureScript("boss_margok") {}

		struct boss_margok : public ScriptedAI {
			boss_margokAI(Creature* creature) : ScriptedAI(creature) {
				Initialize();
			}
		};
}