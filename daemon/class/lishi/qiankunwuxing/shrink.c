// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;
        if(!me->is_fighting())
        return notify_fail("乾坤无形只可以在战斗中施展！\n");
        if( !target ) target = offensive_target(me);
        if((int)me->query_skill("magic") < 60 )
                return notify_fail("你的法术不够高！\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("你要对谁施展这个法术？\n");

        if((int)me->query("atman") < 150 )
                return notify_fail("你的灵力不够！\n");

        if((int)me->query("gin") < 50 )
                return notify_fail("你的精神没有办法有效集中！\n");

        me->add("atman", -150);
        me->receive_damage("gin", 50);

        if( random(me->query("max_atman")) < 30 ) {
                write("你失败了！\n");
                return 1;
        }
	lvl = (int)me->query_skill("magic") /3;
	msg = CYN "\n\n$N对$n施展出［乾坤无形］中的<乾坤消>！\n\n" ;
        ap = me->query_skill("magic");
        ap = ( ap * ap /100 * ap/30 ) * (int)me->query("gin") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
        msg +="$n的全身一阵抽搐，身形似乎矮小了几分！！\n\n";
                seteuid(ROOT_UID);
		target->add_temp("apply/attack",-lvl);
		target->add_temp("apply/defense",-lvl);
                target->start_call_out( (: call_other, __FILE__, "remove_enlarge"
,target, lvl :),
                random(lvl/2)+lvl/2);
        } else
                msg += "但是$N并没有成功。\n\n";
        if(me == target) 
        {
        msg = replace_string(msg, "$n","$N");
        message_vision(msg+NOR,me);
        }
        else
        message_vision(msg+NOR, me, target);
        me->start_busy(1);

	return 1;
}

void remove_enlarge(object target, int lvl)
{
                target->add_temp("apply/attack",lvl);
                target->add_temp("apply/defense",lvl);
	message_vision("$N的全身骨结一阵暴响，身形突然高大了几分！！\n",target);
}
