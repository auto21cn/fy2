
inherit ROOM;

void create()
{
	set("short", "原始丛林");
	set("long", @LONG
丛林中一片黑暗，黑暗中充满了各式各样的危险，每一种都可以
至命。若是在丛林中迷失了方向，饥渴就足以至命。
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest7",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest5",
		"west" : __DIR__"forest6",
	]));
	set("outdoors", "ghost");
        set("NONPC",1);
	set("coor/x",-1190);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
