// recover.c

inherit SSERVER;

int exert(object me, object target, int amount)
{
        if( target != me ) return 
notify_fail("你只能用内功调匀自己的气息。\n");

	if(amount == -1) amount = 20;
	else if(amount < 20 ) 
                return notify_fail("最少用二十内力。\n");

        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");

        me->receive_heal("kee", (10 + (int)me->query_skill("force")/10)*amount/20 );
        me->add("force", -amount);

        message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}
 
