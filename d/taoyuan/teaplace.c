inherit ROOM;
void create()
{
        set("short", "С��ջ");
        set("long", @LONG
Ҳ��֪��ʲôʱ�������СС�Ĳ�ջ���Ѿ�������ˣ�����������
ʵ�ڲ��ֻ࣬�д����Ǵӵ����չ���ʱ������������Ե�����һЩ����
ջȴҲά������
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"road1",
   ]));

   set("objects", ([
      __DIR__"npc/waiter" :1,
      __DIR__"npc/laodie" :1,
      __DIR__"npc/singgirl" :1,
   ]) );

   set("coor/x",190);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
   replace_program(ROOM);

}