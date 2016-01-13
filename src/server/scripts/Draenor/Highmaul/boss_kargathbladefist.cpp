/*
 * Copyright (C) 2016 Gazhrot
 *
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Texts {
    SAY_AGGRO       = 0,
    SAY_EARTHQUAKE  = 1,
    SAY_OVERRUN     = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4
};

enum Spells {
    SPELL_EARTHQUAKE        = 156975,
    SPELL_SUNDER_ARMOR      = 156964,
    SPELL_CHAIN_LIGHTNING   = 157001,
    SPELL_OVERRUN           = 157039,
    SPELL_ENRAGE            = 156975,
    SPELL_MARK_DEATH        = 156921,
    SPELL_AURA_DEATH        = 156964
};

enum Events {
    EVENT_ENRAGE    = 1,
    EVENT_ARMOR     = 2,
    EVENT_CHAIN     = 3,
    EVENT_QUAKE     = 4,
    EVENT_OVERRUN   = 5
};

class boss_kargathbladefist : public CreatureScript {
    public: 
        boss_kargathbladefist() : CreatureScript("boss_kargathbladefist") {}
    
        struct boss_kargathbladefistAI : public ScriptedAI {
            boss_kargathbladefistAI(Creature* creature) : ScriptedAI(creature) {
                Initialize();
            }

            void Initialize() {
                _inEnrage = false;
            }

            void Reset() override {
                _events.Reset();
                _events.ScheduleEvent(EVENT_ENRAGE, 0);
                _events.ScheduleEvent(EVENT_ARMOR, urand(5000, 13000));
                _events.ScheduleEvent(EVENT_CHAIN, urand(10000, 30000));
                _events.ScheduleEvent(EVENT_QUAKE, urand(25000, 35000));
                _events.ScheduleEvent(EVENT_OVERRUN, urand(30000, 45000));
                Initialize();
            }

            void KilledUnits(Unit* victim) override {
                victim->CastSpell(victim, SPELL_MARK_DEATH, 0);

                if (urand(0, 4))
                    return;
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* killer) override {
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* who) override {
                Talk(SAY_AGGRO);
            }

            void MoveInLineOfSight(Unit* who) override {
                if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsValidAttackTarget(who))
                    if (who->HasAura(SPELL_MARK_DEATH))
                        who->CastSpell(who, SPELL_AURA_DEATH, 1);   
            }

            void UpdateAI(uint32 diff) override {
                if (!UpdateVictim())
                    return;
                
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent()) {
                    switch (eventId) {
                        case EVENT_ENRAGE:
                            if (!HealtAbovePct(20)) {
                                DoCast(me, SPELL_ENRAGE);
                                _events.ScheduleEvent(EVENT_ENRAGE, 6000);
                                _inEnrage = true;
                            }
                            break;
                        case EVENT_OVERRUN:
                            Talk(SAY_OVERRUN);
                            DoCastVictim(SPELL_OVERRUN);
                            _events.ScheduleEvent(EVENT_OVERRUN, urand(25000, 40000));
                            break;
                        case EVENT_QUAKE:
                            if (urand(0, 1))
                                return;
                            Talk(SAY_EARTHQUAKE);
                            DoCast(me, SPELL_EARTHQUAKE);
                            _events.ScheduleEvent(EVENT_QUAKE, urand(30000, 55000));
                            break;
                        case EVENT_CHAIN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            _events.ScheduleEvent(EVENT_CHAIN, urand(7000, 27000));
                            break;
                        case EVENT_ARMOR:
                            DoCastVictim(SPELL_SUNDER_ARMOR);
                            _events.ScheduleEvent(EVENT_ARMOR, urand(10000, 25000));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                bool _inEnrage;
        };

        CreatureAI* GetAI(Creature* creature) const override {
            return new boss_kargathbladefistAI(creature);
        }
};

void addSC_boss_kargathbladefist() {
    new boss_kargathbladefist();
}