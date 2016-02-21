// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［狗急跳墙］只能对战斗中的对手使用。\n");
	if((int)me->query("kee")*100/(int)me->query("max_kee") > 20)
		return notify_fail("你不到万不得以的时候使不出此招！\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("doggiesteps",1) / 5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N凌空一跳，身形如被逼急的野狗，双脚一前一后，狠命地向$n踢出！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
