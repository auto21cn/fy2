//TIE@FY3
inherit SKILL;
mapping *action = ({
	([	"action":		"$N使一招「拖泥带水伤人易」，手中$w连连向下斜劈，飞沙走石，迷住$n的二目，趁势一刀削向$n的$l！",
		"dodge":		-870,
		"parry":		-700,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N身形急转，刀随人动，$w随著一招「玉洁金坚律己难」，刀风滚滚向$n的$l砍去！",
                "dodge":                -670,
                "parry":                -600,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N身行跃起，抡动手中$w，一招「曾经人海竟飞腾」，凌空劈向$n的$l",
                "dodge":                -570,
                "parry":                -500,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w舞动，刀光缭绕，一招「笔绕春虹梦有形」，从四面八方齐向往$n杀去！",
                "dodge":                -470,
                "parry":                -400,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w化作片片刀光，一招「心地长飘六月雪」，飘飘荡荡向$n落去",
                "dodge":                -370,
                "parry":                -200,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N单掌拍出，掌风烈烈，热浪袭人，手中$w泛出五彩光华，一招「火内方开五色莲」直劈$n$l",
                "dodge":                -270,
                "parry":                -100,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N使一招「疑能生苦苦生疑」，手中$w盘转而进，刀光霍霍斩向$n的$l",
                "dodge":                -170,
		"damage_type":	"割伤"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能练刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 8;}

string *parry_msg = ({
        "$n使出一招「舍身不难难舍念」，手中的$v快似闪电般格开了$N的$w。\n",
	"$n手中$v泛出道道弧光，冷气森森，一招「炯炯孤光冷逾冰」，从侧面划向$N之必救。\n",
	"$n身形转动，手中的$v光华闪闪，一招「素心依旧伴青灯」，反削$N的$w。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「泥牛入海随波散」，手中的$v浑然波出，$N的攻势随波而散。\n",
"$n站定身形，手中$v刀光暴长，一招「在冶良金色愈光」，封住$N的招式。\n",
"$n手中的$v拆招化式，游刃有余。\n",
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
	return 100;
}
int practice_bonus()
{
	return 50;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/lianxin-blade/" + action;
}

