// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "人字瀑");
        set("long", @LONG
黄山三名瀑之一，位于紫云，朱砂两峰间的山坳之中，由于倾泄
到半山之时，忽有巨石从山中斜插而出，所以半途一分为二，形成一
个人字，宛若两条飞舞的玉龙，分道扬镳，直落崖下。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"qingluan",
]));
        set("objects", ([
                __DIR__"npc/xiangke" : 3,
       ]) );
	set("resources/water",1);
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-520);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
