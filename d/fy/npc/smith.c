inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
        set_name("张铁匠", ({ "zhang" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long","张铁匠一身打铁功夫名不虚传，他打出的铁器经久耐用．\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_ding", "ding");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "张铁匠粗声粗气地说道：这位" + RANK_D->query_respect(ob)
                                + "，要什么？\n");
                        break;
                case 1:
                        say( "张铁匠满脸汗水说道：这位" + RANK_D->query_respect(ob)
                                + "，我太忙了，帮不了你。\n");
                        break;
        }
}

int do_ding(string arg)
{
	string ctype, cname, ccolor, cid,material;
	object ob, me, gold, ob2;
	string id,newfile,filename,timestamp;
        me = this_player();
	id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s %s",ctype,ccolor,cname,cid,material ) != 5)
        return notify_fail("指令格式：ding <type> <color> <name> <English name> <material>\n");
	if(me->is_busy())
	return notify_fail("你上一个动作还没有完成。\n");
	if((int)me->query("created_item") >= (int)me->query("age")/11)
	return notify_fail("你现在只能拥有"+chinese_number((int)me->query("age")/11)+
"件自造物品。\n");
	if((int)me->query("created_item") >= 3)
	return notify_fail("你已经拥有太多自造物品了。\n");
	gold = present("gold_money", this_player());
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < 10)
        return notify_fail("你身上没有那麽多金子。\n");
	if(!objectp(ob2=present(material,me)))
	return notify_fail("你身上并没有"+material+"。\n");
	if(!(int)ob2->query("for_create_weapon"))
	return notify_fail(ob2->name()+"并不可以用来打造兵器。\n");
	if( !check_legal_name(cname))
	return notify_fail("");
        if( !check_legal_id(cid))
        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("不知你要什么颜色．\n");
        ccolor = replace_string(ccolor, "$BLK$", "BLK");
        ccolor = replace_string(ccolor, "$RED$", "RED");
        ccolor = replace_string(ccolor, "$GRN$", "GRN");
        ccolor = replace_string(ccolor, "$YEL$", "YEL");
        ccolor = replace_string(ccolor, "$BLU$", "BLU");
        ccolor = replace_string(ccolor, "$MAG$", "MAG");
        ccolor = replace_string(ccolor, "$CYN$", "CYN");
        ccolor = replace_string(ccolor, "$WHT$", "WHT");
        ccolor = replace_string(ccolor, "$HIR$", "HIR");
        ccolor = replace_string(ccolor, "$HIG$", "HIG");
        ccolor = replace_string(ccolor, "$HIY$", "HIY");
        ccolor = replace_string(ccolor, "$HIB$", "HIB");
        ccolor = replace_string(ccolor, "$HIM$", "HIM");
        ccolor = replace_string(ccolor, "$HIC$", "HIC");
        ccolor = replace_string(ccolor, "$HIW$", "HIW");
        ccolor = replace_string(ccolor, "$NOR$", "NOR");
	seteuid(ROOT_UID);
	switch( ctype ) {
                case "axe":
                        newfile = read_file("/obj/weapons/axe.o");
                        break;
                case "blade":
                        newfile = read_file("/obj/weapons/blade.o");
                        break;
                case "dagger":
                        newfile = read_file("/obj/weapons/dagger.o");
                        break;
                case "fork":
                        newfile = read_file("/obj/weapons/fork.o");
                        break;
                case "hammer":
                        newfile = read_file("/obj/weapons/hammer.o");
                        break;
                case "staff":
                        newfile = read_file("/obj/weapons/staff.o");
                        break;
                case "sword":
                        newfile = read_file("/obj/weapons/sword.o");
                        break;
                case "whip":
                        newfile = read_file("/obj/weapons/whip.o");
                        break;
                case "spear":
                        newfile = read_file("/obj/weapons/spear.o");
                        break;
                case "banzhi":
                        newfile = read_file("/obj/weapons/banzhi.o");
                        break;
		default:
			return notify_fail("这里不会做你要的东西．\n");
	}
        timestamp = sprintf("%c%c%c%c%c%c%c",
	'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20),
	'a'+random(20),'a'+random(20));
	newfile = replace_string( newfile, "订作的", cname);
        newfile = replace_string( newfile, "order", cid);
        newfile = replace_string( newfile, "fengyun", id);
        newfile = replace_string( newfile, "COR", ccolor);
        newfile = replace_string( newfile, "STAMP", timestamp);
	filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +timestamp + ".c";
	if( !write_file2(filename, newfile,1))
		return 0;
	ob = new(filename);
	if(ob2->query("equipped")) {ob2->unequip(); me->reset_action();}
	ob2->move(environment(me));
	ob->set("weight",ob2->query_weight());
	ob->set("rigidity",ob2->query("rigidity"));
	ob->set("weapon_prop/damage",ob2->query("weapon_prop/damage"));
	ob->set("max_enchant",ob2->query("max_enchant"));
	ob->set("base_damage",ob2->query("weapon_prop/damage"));
	ob->save();
	ob->restore();
	if(ob->move(me)){
	gold->add_amount(-10);
	me->add("created_item",1);
        me->start_busy(1);
        write("你将身上的"+ob2->name()+"交给"+name()+"，打造成一"+ob->query("unit")+
	ob->name()+"\n");
        destruct(ob2);
        seteuid(getuid());
	return 1;
	}
	return 0;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("对不起，中文名字必须是一到二十个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("对不起，英文名字必须是三到二十个字。\n");
                return 0;
        }

	return 1;
}
