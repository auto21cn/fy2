// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_qin();
void create()
{
        set_name("����", ({ "yunliu" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "�����˹��������������������ֱ���ʦ\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����������һ�ۣ�����ȫ�����¿���һ������
����ǧ��������������ģ���
����˵�Ϸ��Ĵ�ç������һ���ˣ����ȥ����Ϊʦ����\n",
        }) );
        set("inquiry", ([
                "����" : "����˵Ҫ������ˣ�����ᵯ�٣���\n",
                "yiren" : "����˵Ҫ������ˣ�����ᵯ�٣���\n",
		"����" : (: give_qin :),
		"tanqin" : (: give_qin :),
	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}

int give_qin()
{
        object obj;
if( !query("given"))
        {
command("say ��ѹ�������ȥ���ɣ���\n");
obj = new(__DIR__"obj/qin");
obj->move(this_player());
set("given",1);
        }
else
command("say �ҵĹ����������ˣ�\n");
        return 1;
}

void reset()
{
delete("given");
}
