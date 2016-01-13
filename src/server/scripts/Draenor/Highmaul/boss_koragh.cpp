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

class boss_koragh : public CreatureScript {
	public:
		boss_koragh() : CreatureScript("boss_koragh") {}

		struct boss_koragh : public ScriptedAI {
			boss_koraghAI(Creature* creature) : ScriptedAI(creature) {
				Initialize();
			}
		};
}