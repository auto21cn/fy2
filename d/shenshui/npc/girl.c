// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("侍女" , ({ "girl", "shi nu" }) );
	set("long", "一位十几岁的丫头。\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 15);
        set("gender", "女性" );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(100));
	setup();
	carry_object("/obj/cloth")->wear();
}
