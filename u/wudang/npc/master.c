// taolord.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("石雁", ({ "master shi", "master", "shi" }) );
        set("nickname", "五行真人");
        set("gender", "男性");
        set("age", 62);
        set("long",
"石雁乃当代武当掌门，他的太极心法和三才剑法已炼到了极高的境界。\n"
                "他尤其精通太极五行，五行身法已是当世无双，所以人称［五行真人］。\n");
        set("combat_exp", 200000);
        set("score", 20000);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);

        set("atman", 400);
        set("max_atman", 400);

        set("mana", 200);
        set("max_mana", 200);

        set("inquiry", ([
                "太极心法": 
"太极心法乃道家入门的基本心法，能够调和体内的阴阳二气。\n但是只要持之以恒，并不输给任何其他内功。\n",
                "武当派": 
"我武当派自张真人开山立派至今，世世代代皆以行侠仗义为己任。\n",
		"七星法" :
"七星法名为七星却只有两诀：捍星诀（hanxing）和击星诀（jixing）。\n",
		"qixing" :
"七星法名为七星却只有两诀：捍星诀（hanxing）和击星诀（jixing）。\n",
        ]) );

        set("apprentice_available", 10);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),

        }) );

        create_family("武当派", 57, "掌门人");

        set_skill("literate", 90);
	set_skill("qiankunstrike",150);
        set_skill("force", 150);
        set_skill("move", 100);
        set_skill("unarmed", 70);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("dodge", 90);
        set_skill("changelaw", 90);
        set_skill("three-sword", 90);
	set_skill("taijiforce", 120);
	set_skill("taiji", 90);
	set_skill("five-steps", 150);
	set_skill("spells",100);
	set_skill("qixing",100);
	map_skill("spells","qixing");
        map_skill("parry", "three-sword");
        map_skill("sword", "three-sword");
        map_skill("literate", "changelaw");
        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji");

        setup();

	carry_object(__DIR__"obj/msword")->wield();
        carry_object(__DIR__"obj/mcloth")->wear();
        carry_object(__DIR__"obj/mhat")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 贫道今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("marks/武当弃徒") )
                command("say " + ob->query("name") + "！你还有脸回来见我？");
        else {
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        add("apprentice_availavble", -1);
}

int accept_object(object who, object ob)
{
	object 		book;

        if((string)ob->name() != "顾云飞的秘函") return 0;
	command("say 多谢这位" + RANK_D->query_respect(who));
	command("say 这本书你留作记念吧。");
	book = new(__DIR__"obj/wubook");
	book->move(this_object());
	command("give book to " + who->query("id"));
        return 1;
}


void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","武当派道士");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","武当派小真人");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","武当派真人");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","武当派小天师");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","武当派天师");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","武当派大天师");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","武当派副掌门");
                return ;
        } else
                student->set("title","武当派掌门");
                return ;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if(ob) 
        ob->set_temp("killed_master_shi",1);
        ::die();
}

