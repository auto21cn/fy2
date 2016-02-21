// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
string *directions= ({"����","����","����","�Ϸ�"});
void echoforest(object me);
void create()
{
        set("short", "������");
        set("long", @LONG
������ȥ������ãã�����ޱ߼ʡ�Ũ�ܵ���֦��һ���ʵ�ĵ�̺�̸���
������ء�������ϴ�׳����֦������������չ��������һ����Ϊ�⻬����
���Ǳ����ʰѹ��ĺۼ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"center3",

]));
        set("outdoors", "manglin");
	set("current_dir",0);
        set("coor/x",50);
	set("coor/y",-400);
	set("coor/z",40);
	setup();
}

void init()
{
add_action("do_swing","swing");
add_action("do_turn","turn");
add_action("do_look","look");
}
int do_look(string arg)
{
	if( arg == "vine" 
		|| arg == "��֦" )
	{
	write("����һ����׳�⻬����֦�����ڶ�����"+directions[query("current_dir")]+"��\n");
	return 1;
	}
	return 0;
}
int do_swing(string arg)
{
	object me;
	int c_dir;
	me = this_player();
        if( arg == "vine"
                || arg == "��֦" )
        {
	echoforest(me);
	c_dir = query("current_dir");
	message_vision("\n\n$Nץ����֦��������"+
	directions[c_dir] +
	"��ȥ��	
���Ŷ��ߵĺ���������$N�������е���
������������ŶŶŶŶŶŶ����������������\n\n",me);
	if(c_dir == 2 )
		me->move(__DIR__"edge3");
	else
		me->move(__DIR__"top"+sprintf("%d",c_dir+1));
	return 1;
	}
	else return 0;

}
int do_turn(string arg)
{
	object me;
	int c_dir;
	me = this_player();
        if( arg == "vine"
                || arg == "��֦" )
        {
	c_dir = (int) query("current_dir");
	c_dir = (c_dir + 1 ) %4 ;
	set("current_dir",c_dir);
	message_vision("$N�����⶯��֦��ʹ��������"+directions[c_dir]+"��\n",me);
        return 1;
        }
        return 0;

}
void echoforest(object me)
{
int i;
object room;
string *names = ({"center1","center2","center3", "center4",
		"dummy1","dummy2","dummy3","dummy4",
		"groupe1","groupe2","groupe3","groupe4",
                "groupw1","groupw2","groupw3","groupw4",
                "groupn1","groupn2","groupn3","groupn4",
                "groups1","groups2","groups3","groups4",
		"top1","top2","top4" });
for(i=0;i<sizeof(names);i++)
{
if( room = find_object(__DIR__+names[i]))
tell_object(room,HIW "\n\nԶ������һ�����У���������������ŶŶŶŶŶŶ������������������\n\n" NOR);
}
}
void reset()
{

::reset();

	set("current_dir" , random(4));
}