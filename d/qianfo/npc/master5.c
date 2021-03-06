// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("任慈", ({ "master renci", "master"}) );
        set("nickname", HIR "前任帮主" NOR);
        set("gender", "男性" );
        set("age", 64);
	set("per", 25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 30);
        set("long",
"
任慈是丐帮的前任帮主，只因近来身体多病才让位于南宫
\n"
	);
        create_family("丐帮", 6, "弟子");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 4000000);
        set_skill("move", 150);
        set_skill("parry",150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("literate", 80);
	set_skill("unarmed",150);
        set_skill("begging",150);
        set_skill("inquiry",150);
	set_skill("doggiesteps",150);
	set_skill("dragonstrike",150);
	set_skill("huntunforce",150);
	set_skill("staff",150);
	set_skill("dagou-stick",150);
        set("inquiry", ([
                "南宫灵" : (: kill_him :),
                "master nangong" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/9bagcloth")->wear();

}

void attempt_apprentice(object me)
{
	if((int)me->query_temp("killed_master_nangong"))
	{
	command("say 看在你为武林除一大害的份上，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("sigh");
        command("say 我已经不再是帮主了，你还是去找南宫吧！\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "beggar");
}
int kill_him()
{
	command("say 南宫对我甚为孝顺，每天清粥一碗，从未间断！\n");
	return 1;
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

