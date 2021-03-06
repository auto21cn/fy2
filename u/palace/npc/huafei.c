

inherit NPC;
void create()
{
        set_name("花飞", ({ "huafei" }) );
        set("gender", "男性" );
        set("age", 18);
        set("per", 58);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300);
        create_family("帝王谷", 2, "弟子");

        set("max_force", 100);
        set("force", 50);
        set("force_factor", 5);
        set("attitude", "aggrensive");

        set("long","此人满身锦衣，身亮欣长，苍白而清俊的面容上，带著一份孤傲冷
削之色，仿佛未将任何人看在眼里。
\n");
        set("combat_exp", 200000);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 90);
        set_skill("zuixian-steps", 70);
	set_skill("thunderwhip",10);
	set_skill("iceheart",10);
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");
        set("chat_chance", 20);
        set("chat_msg", ({
		"花飞冷冷的盯了你一眼\n",
        }) );
	setup();
	carry_object(__DIR__"obj/zhanpao3")->wear();
        add_money( "silver" , 50);
}
