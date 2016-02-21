// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "慈光阁");
        set("long", @LONG
已是桃花峰顶，看下面的温泉犹如颗颗明珠，嵌映群峰，前面就
是青鸾桥，游人到此一般都要稍做歇息，于是便有了这座慈光阁。
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"wenquan",
  "south"  : __DIR__"taoyuan",
  "westdown" : __DIR__"qingluan",
]));
        set("objects", ([
                __DIR__"npc/feng" : 1,
		__DIR__"npc/jin" : 1,
       ]) );

        set("outdoors", "huangshan");
	set("coor/x",-530);
	set("coor/y",-510);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
