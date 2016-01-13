/*
 * Copyright (C) 2016 Gazhrot
 *
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "highmaul.h"

class instance_highmaul : public InstanceMapScript {
	public :
		instance_highmaul() : InstanceMapScript("instance_highmaul", 1228) {}

	struct instance_highmaul_InstanceMapScript : public InstanceScript {
		instance_highmaul_InstanceMapScript(Map * map) : InstanceScript(map) {
			SetHeaders(DataHeader);
			setBossNumber(EncounterCount);
		}

		void OnCreatureCreate(Creature * creature) override {
			switch (creature->getEntry()) {
				case BOSS_BRACKENSPORE:
				case BOSS_KARGATHBLADEFIST:
				case BOSS_KORAGH:
				case BOSS_MARGOK:
				case BOSS_TECTUS:
				case BOSS_THEBUTCHER:
				case BOSS_TWINOGRONPOL:
				case BOSS_TWINOGRONPHEMOS:
				case BOSS_VULGOR:
					break;
				default:
					break;
			}
		}

		bool SetBossState(uint32 type, EncounterState state) override {
			if (!InstanceScript::SetBossState(type, state))
				return false;
			if (state != DONE)
				return true;
			switch (type) {
				case DATA_BRACKENSPORE:
				case DATA_KARGATHBLADEFIST:
				case DATA_KORAGH:
				case DATA_MARGOK:
				case DATA_TECTUS:
				case DATA_THEBUTCHER:
				case DATA_TWINOGRONPOL:
				case DATA_TWINOGRONPHEMOS:
				case DATA_VULGOR:
					break;
				default:
					return true;
			}

			return true;
		}
	};

	InstanceScript* GetInstanceScript(InstanceMap* map) const override {
		return new instance_highmaul_InstanceMapScript(map);
	}
};

void addSC_instance_highmaul() {
	new instance_highmaul();
}