// dog.c

inherit NPC;

void create()
{
	set_name("С����", ({ "rabbit" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("long", "С���ð��ְ���ֻ������������\n");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 50);
	set("chat_msg", ({
		(: random_move :),
	}));
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}