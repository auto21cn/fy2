#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清宫厨房");
	set("long", @LONG
一间不大的厨房，却是干干净净。左面靠墙是一个很大
的炉灶，右面墙角摆着几坛好酒。中间的一张大桌上摆着的
饭菜，散发着阵阵香气。两个道士正在忙着做饭。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : "/u/taoguan/da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
                "/u/taoguan/npc/reg_taoist" : 2,
]));
	set("coor/x",-10);
	set("coor/y",2100);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
