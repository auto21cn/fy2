// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("风四娘", ({ "feng siniang", "feng"}) );
        set("gender", "女性" );
        set("age",32);
        set("long", "她喜欢各种各样的刺激，喜欢骑最快的马，爬最高的山，吃最辣的菜，
喝最烈的酒，玩最利的刀，杀最狠的人。\n");
        set("combat_exp", random(100000)+200000);
        set("attitude", "aggrensive");
	set_skill("move",70);
	set_skill("unarmed",250);
	set_skill("force",20);
	set_skill("dodge",200);
	set_skill("liuquan-steps",40);
        set("chat_chance", 5);
        set("chat_msg", ({
"风四娘眨着眼笑道：失敬失敬，抱歉抱歉，我本来还以为你是他的老妈呢！\n",
        }) );
        set("max_force",500);
	set("force_factor",20);
	setup();
	carry_object("/obj/cloth")->wear();
}

