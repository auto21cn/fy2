// chuenyu.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("刘老农", ({ "liu" }) );
        set("gender", "男性" );
        set("age", 57);
        set("str", 27);
        set("max_kee", 2000);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
刘老农今年快六十了。但手脚还算灵活。
LONG
);
        set("attitude", "peaceful");

        set("combat_exp", 10000);
        set("bellicosity", 0);
        set("marks/老刘本人", 1);
        set_skill("sword", 150);
        set_skill("unarmed", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("bai-quan", 70);
        set_skill("six-chaos-sword",150);
        set_skill("chaos-steps", 120);
        map_skill("unarmed","bai-quan");
        map_skill("dodge", "pyrobat-steps");
        map_skill("sword","six-chaos-sword");
        setup();

        add_money("coin", 50); 
        carry_object("/obj/cloth")->wear();
	if( random(5) == 1 )
        carry_object(__DIR__"obj/parrybook");

}
int accept_fight(object me)
{
        command("say 老头子哪里是您的对手？");
        return 0;
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}
void greeting(object ob)
{
        object book;
        object sword;
	int bonus;
        if((int) ob->query("marks/murder") == 0)
        {
        if( (int) ob->query("marks/老刘") == 0 ) 
        say( "刘老农说道：“这位"+ RANK_D->query_respect(ob) 
+"，可否见到小女娟儿？” \n");
        else
        {
        say( "刘老农说道：“这位"+ RANK_D->query_respect(ob) 
+"，多谢答救小女娟儿。” \n");
        say( "刘老农说道：“这口剑，这本密笈赠于"+ RANK_D->query_respect(ob) 
+"。” \n");
        say( "刘老农说道：“这处非久留之地，我等去也。” \n");
        say( "刘老农领着娟儿匆匆离去。” \n");

         ob->set("marks/老刘", 0);
	
// Let's give out some bouns for this done!
        if(!ob->query("m_success/小娟"))
        {
                ob->set("m_success/小娟",1);
                ob->add("score",1000);

        }
	bonus = random(10);
	ob->add("combat_exp", bonus);
	bonus += random(10)+2;
	ob->add("potential", bonus);
        sword = new(__DIR__"obj/hengbing");
        book = new(__DIR__"obj/parrybook");
        sword->move(ob);
        book->move(ob); 
        destruct(this_object());
        }
        }
        else
                call_out("killhim",1,ob);
}

killhim(object ob)
{
        ob->set("marks/murder", 0);
        ob->set("marks/老刘", 0);
        set("title", "悲愤欲绝");
        
say("刘老农悲愤欲绝的骂道：你．．你．．你们居然杀了我女儿，纳命来！\n");  

                set("chat_msg_combat", ({
"刘老农悲愤欲绝的骂道：你．．你．．你们居然杀了我女儿，纳命来！",
                (: random_move :),
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
"刘老农悲愤欲绝的骂道：你．．你．．你们居然杀了我女儿，纳命来！",
                (: random_move :),
        }) );
        set_temp("apply/force",4000);
        set_temp("apply/max_force", 2200);
        set_temp("apply/force_factor", 30);
        set_temp("apply/combat_exp", 1000000);
        set_temp("apply/damage", 250);
        carry_object(__DIR__"obj/hengbing")->wield();
        kill_ob(ob);
        ob->kill_ob(this_object());

}
 
