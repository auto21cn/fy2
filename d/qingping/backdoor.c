inherit ROOM;
void create()
{
        set("short", "后门");
        set("long", @LONG
花园的边脚有一个小木门，木门正对着一座小拱桥，一条铺满鹅卵石的
小路蜿蜒地从木门前穿过，消失在花丛中。因为这里平时少有人行走，地上
的石缝中不知何时长出些不知名的花草，虽是无名野花，却也开的芬芳艳丽。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "westup" : __DIR__"bridge",
   "northwest" : __DIR__"northpond.c",	
   "south" : __DIR__"southpond1.c",	
   ]));

   set("objects", ([
      __DIR__"obj/cao": 1,
   ]) );

   set("outdoors","qingping");
   set("coor/x",200);
	set("coor/y",2000);
	set("coor/z",0);
	setup();
	
}

void reset()
{
   object *inv;
   object item1, cao;
   ::reset();

   cao = present("cao", this_object());
   inv = all_inventory(cao);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(cao);
   }
}

