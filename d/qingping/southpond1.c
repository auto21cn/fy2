//XXDER
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�԰����Ժǽ��һ�����䣬���ǳ�����������ط����ߴ��Ժǽ
��ס������һ�У�����ȴ���Կ����԰��Ķ�����һ��ʯ���̳ɵ�С·ֱ
ͨ��Ժ�ſڣ�С·���������˻��ݣ��ɼ����ﳣ�������ϡ�
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "north" : __DIR__"backdoor",
   "west" : __DIR__"southpond",
   ]));

   set("objects", ([
      __DIR__"npc/afu": 1,
   ]) );
   set("outdoors", "qingping");
   set("coor/x",200);
	set("coor/y",1990);
	set("coor/z",0);
	setup();
   replace_program(ROOM);

}
