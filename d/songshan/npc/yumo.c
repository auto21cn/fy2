// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("白玉魔", ({ "master yumo", "master"}) );
        set("nickname", HIW "神钩" NOR);
        set("gender", "男性" );
        set("age", 64);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("pursuer", 1);
        set("long",
"
现任天下第一大帮的帮主的师叔，曾经因奸淫过度被前老帮主任慈逐出丐帮。
\n"
	);
        create_family("丐帮", 6, "师叔");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "staff.tianxiawugou" :)
        }) );
        set("combat_exp", 2000000);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",150);
	set_skill("doggiesteps",80);
	set_skill("dragonstrike",80);
	set_skill("huntunforce",120);
	set_skill("staff",150);
	set_skill("dagou-stick",160);
	set_skill("begging",120);
	set_skill("stealing",150);
	set_skill("betting",100);
	set_skill("inquiry",120);
        map_skill("dodge", "doggiesteps");
	map_skill("force", "huntunforce");
	map_skill("unarmed", "dragonstrike");
	map_skill("staff","dagou-stick");
	map_skill("parry","dagou-stick");
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/staff")->wield();


}

void attempt_apprentice(object me)
{
	if((int)me->query("score")<= -1)
	{
	command("say 看在你我气味相投的份上，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("grin");
        command("say 你我好象不是一路人吗！\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "beggar");
}
void re_rank(object student)
{
	int exp;
	exp = (int) student->query("combat_exp");
	if( exp <= 32000 ) {
		student->set("title","丐帮堂外弟子");
		return ;	
	} else if ( exp <= 64000 ) {
		student->set("title","丐帮一袋弟子");
		return ;
        } else if ( exp <= 128000 ) {
                student->set("title","丐帮两袋弟子");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","丐帮三袋弟子");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","丐帮四袋弟子");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","丐帮五袋弟子");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","丐帮六袋弟子");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","丐帮七袋弟子");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","丐帮八袋弟子");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","丐帮九袋弟子");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","丐帮长老");
                return ;
        } else 
                student->set("title","丐帮副帮主");
                return ;

}
