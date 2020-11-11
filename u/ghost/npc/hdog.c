inherit NPC;

void create()
{
        set_name("狗郎君", ({ "dog" }) );
        set("gender", "男性");
        set("class", "ghost");
        create_family("幽灵山庄", 3, "弟子");
        set("age", 34);
        set("combat_exp", 50000);
        set("long",
		"一条全身漆黑，黑得发亮的大狗。\n"
	);
        set("no_arrest",1);
        set_skill("move", 100);
        set_skill("dodge", 100);
        set_skill("throwing", 100);
        set_skill("feidao", 50);
	map_skill("throwing", "feidao");
        setup();
	carry_object(__DIR__"obj/biao")->wield();
}
