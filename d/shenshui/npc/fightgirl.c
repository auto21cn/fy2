inherit NPC;
void create()
{
        string *order = ({"张", "王", "李", "赵"});
        string *orderr = ({"雯", "柳儿", "雪儿", "媛媛", "小燕" });
        set_name( order[random(4)] + orderr[random(5)], ({ "girl", "gong nu" }));
	set("long", "一位负责寻视白水宫的宫女。\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 15);
        set("gender", "女性" );
        set("title", "神水宫弟子");
	set("combat_exp", 5000+random(10000));
        set_skill("unarmed", 50);
        set_skill("throwing", 85);
        set_skill("force", 50);
        set_skill("parry", 67);
        set_skill("dodge", 69);
        set_skill("literate", 50);
        set_skill("perception", 68);

        set_skill("nine-moon-steps", 68);
        set_skill("nine-moon-claw", 35+random(30));
        set_skill("nine-moon-force", 60);
        set_skill("nine-moon-sword", 70);

        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver", 3);
}

void init()
{
        object me;
        me = this_player();
        if(userp(me) && me->query("gender") == "男性" && !me->query_temp("marks/guest") && !me->query("marks/白家人"))
        call_out("chase_him", 1,me );


}

int chase_him(object me)
{
        message_vision("$N向$n喝道：大胆狂徒，竟敢擅闯神水宫！\n",this_object(),me);
        set_leader(me);
        kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}

