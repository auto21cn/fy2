// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "试剑石");
        set("long", @LONG
一块巨大的石头（stone），孤处路中，中间一痕，深几近半，相传这是一
古代剑师试剑之处，铸剑千余，最后终于造出一把可以劈开此石的剑
，名为“苍穹神剑”，可惜剑师因心力憔悴而死。相传黄山剑庐主人
世代相传的便是此剑。
LONG
        );
        set("exits", ([ 
  "north"  : __DIR__"zuishi",
]));
        set("item_desc", ([
                "stone": "一块巨大的石头，中间一痕，裂缝深处似乎有一
东西闪闪发光。你似乎也可以在这里试一试（test）你的武器。\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-550);
	set("coor/y",-530);
	set("coor/z",10);
	setup();
}
void init()
{
add_action("do_test","test");
}
int do_test(string arg)
{
object me,weapon;
if(!arg ) return notify_fail("你要试一试你身上的哪样武器？\n");
me=this_player();
if(!(weapon = present(arg,me))) return notify_fail("你身上似乎没有这样东西！\n");
if(!weapon->query("weapon_prop")) return notify_fail(weapon->name()+"似乎并不是一种武器！\n");
if(!weapon->query("equipped")) return notify_fail("你并没有将"+weapon->name()+"握在手中。\n");
message_vision("$N用尽全力，将手中的"+weapon->name()+"猛力向巨石挥去。。。。\n",me);
weapon->unequip();
weapon->set("weapon_prop",0);
weapon->save();
me->reset_action();
message_vision("只听见”铛“的一声，$N手中的"+weapon->name()+"应声而断！\n",me);
weapon->set("name","断掉的" + weapon->query("name"));
weapon->set("value",0);
if(random(500))
tell_object(this_object(),"大石上的裂痕似乎又深了一些！\n");
else
{
tell_object(this_object(),"一块黑黝黝的东西从石缝中掉了出来！\n");
weapon = new(__DIR__"obj/banzhi");
weapon->move(this_object());
}
me->start_busy(2);
return 1;
}
