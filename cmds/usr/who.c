#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

	string str;
	str = WHO_D->local_whos(arg);
        me->start_more(str);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w]

这个指令可以列出所有在线上的玩家及其等级。

-l 选项列出本站玩家的讯息。
-i 只列出玩家的英文代号。
-w 只列出线上所有的管理人员。

相关指令： finger
HELP
    );
    return 1;
}

