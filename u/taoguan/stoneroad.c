// Room: /d/temple/road1.c

inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
һ��������ʯ���С��, ����ߴ������, ż�����뻺��Ʈ�䡣
�����ϲ�������̦, ��������Щ���ӵ�ʯ���ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"da_dian",
  "northwest" : __DIR__"stoneroad2",
]));

        set("coor/x",-30);
	set("coor/y",2120);
	set("coor/z",80);
	setup();
}

int valid_leave(object me, string dir)
{
     if (!wizardp(this_player()) && (dir=="south" || dir=="northwest"))
          {
           if( random((int)this_player()->query("kar")) < 3 )
              {
               message_vision("$Nһ�Ų�����̦��, ��С�Ļ���һ��, �Ľų����ˤ�ڵ���������\n\n\n", this_player());
               this_player()->unconcious();
               return 0;
              }
           else return 1;
          }
     else return 1;
} 
         