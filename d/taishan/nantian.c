inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ǵ���������ؾ��������ţ���ǰһ��Ħ���Ρ��ׯ�أ�����
����������ʯ�̣����������������񹤣��ĸ���ľ�������䱥�����꣬
ȴ��ɫ���ģ��ٷ�Զ��������������������һ��Х�������������
ǧ�����䡣�ɴ����ϣ��㵽��̩ɽ�ĺ�ɽ����ʯ����������̩ɽɽ��
��ϼԪ�������˼乩��֮���ڣ�����������������µĹ��·塣
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"shiba",
  "west" : __DIR__"yueguan",
  "north" : __DIR__"houshi",
  "east" : __DIR__"bixia",
]));

        set("item_desc", ([
                "ʯ��": "		
		��		��
		��		��
		��		��
		��		��
		��		��
		��		��
		ǧ		��
		��		��
		��		ʤ
		��		��
		 ��		 ��			
"        ]) );
        set("objects", ([
        __DIR__"npc/pettrainer" : 1,
                        ]) );
        set("outdoors", "taishan");
	set("coor/x",-480);
	set("coor/y",-310);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}