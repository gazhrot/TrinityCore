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


class boss_thebutcher : public CreatureScript {
	public:
		boss_thebutcher() : CreatureScript("boss_thebutcher") {}

		struct boss_thebutcher : public ScriptedAI {
			boss_thebutcherAI(Creature* creature) : ScriptedAI(creature) {
				Initialize();
			}
		};
}