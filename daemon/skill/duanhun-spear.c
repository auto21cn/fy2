//TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使一招「周身皆梦」，手中$w一抖，化出无数枪头，直刺$n的$l",
                "dodge":                620,
		"parry":		500,
		"force" :		100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出断魂枪中的「执梦为真」，手中$w晃动，虚点数枪，突然自影中发出一枪，刺向$n的$l",
                "dodge":                620,
		"parry":		600,
                "force":               200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「诸皆成梦」，向前猛窜，手中$w反背一枪，直扎$n的$l",
                "dodge":                630,
		"parry":		400,
                "force":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一式「梦中知梦」，手中$w枪头乱抖，铺天盖地杀来，枪枪不离$n的$l",
                "force":                90,
                "dodge":                230,
                "parry":                400,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w虚点，蓦地进步跟身，一招「观物达观」刺向$n的$l",
                "dodge":                200,
		"parry":		300,
                "force":               300,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w一递，枪身竟如残月般弯转，，一招「一念回光」反手对准$n$l一枪刺去",
                "dodge":                260,
		"parry":		330,
                "force":               100,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练断魂枪。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把枪才能练枪法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="spear" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习断魂枪。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍断魂枪。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/duanhun-spear/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出一招「过眼烟云」，手中的$v荡开了$N的$w。\n",
        "$n使出「梦中说梦」，将$N的$w封于丈外。\n",
        "$n使出一招「踏遍天涯」，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「久历歧途」，向$N拿$w的手腕刺去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招「荆榛丛中」封住了$N的攻势。\n",
        "$n反手一招「云浮华相」，整个人消失在一团剑光之中。\n",
        "$n使出一招「光万境闲」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招「天涯空驰」，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return -10;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 20;
}

