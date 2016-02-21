// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","月观峰");
  set("long",@LONG
峰上一小阁楼，阁楼虽小，但建在这高山之上，也是不易，日观
峰的红日，月观峰的金月都是极好看的景致，每当清风之也，月高悬
其上，美不胜收，如恰逢秋高气爽之时，持螯赏月，乘风而舞，兴之
所致，实在无可比拟。
LONG
  );
  set("exits",([
	"east" : __DIR__"nantian",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",-490);
	set("coor/y",-310);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
