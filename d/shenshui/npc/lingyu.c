// XXDER

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("方灵玉" , ({ "lingyu", "girl" }) );
	set("long", "窗边床上端坐着一个女孩，美绝人寰的脸上没有一丝表情，一袭黑纱衬
托着如玉的脸庞，你不由得觉得一阵心痛，好没来由。\n\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 11);
        set("gender", "女性" );
        set("per", 50);
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object(__DIR__"obj/blackcloth")->wear();
}
