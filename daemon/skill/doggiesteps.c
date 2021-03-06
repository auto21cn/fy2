// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，轻轻一纵，一招「野狗扑食」，举重若轻的避开这一击。\n",
        "$n身随意转，一式「野狗斜纵」，倏地往一旁挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，使出「野狗打滚」，$N这一招扑了个空。\n",
        "却见$n足不点地，一招「野狗上蹿」，往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，使出「野狗下跳」，有惊无险地避开了$N这一招。\n",
        "$n身形往上一拔，一招「野狗左摇」，一个转折落在数尺之外。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力太差了，不能练野狗步法。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 9;}

int learn_bonus()
{
	return 50;
}
int practice_bonus()
{
	return 50;
}
int black_white_ness()
{
	return 50;
}

string perform_action_file(string action)
{
        return CLASS_D("beggar") + "/doggiesteps/" + action;
}

