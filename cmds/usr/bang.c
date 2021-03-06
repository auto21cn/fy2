#define SCORE_COST 10000
#define GOLD_COST 2000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name,title;	
	string *dir;
	int i;
	seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %s",e_name, c_name, title) != 3)
        return notify_fail("指令格式：　bang xuelianjiao 雪莲教 教主\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("你的评价点不够"+chinese_number(SCORE_COST)+
        "点。\n");
        gold = present("gold_money",me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"两金子。\n");	
	if(!check_legal_name(c_name) || !check_legal_name(title))
	return 1;
	c_name += "　";
	e_name += "_";
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
	return notify_fail("你想创立的帮派中文或英文名字已经被别人占用了！\n");	
	if(
	!BR_D->touch_file(DATA_DIR+"guild/"+e_name) ||
	!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("游戏系统出现问题！请通知管理人员！\n");
	me->delete("family");
	me->create_family(c_name,1,title);
	me->set("class",e_name);
	me->add("score",-SCORE_COST);
	gold->add_amount(-GOLD_COST);
 	message("system",
	"\n\n\n
			『"+c_name+"』"+"在江湖中成立了！\n\n\n",
			users() );
    return 1;
}
 
int help(object me)
{
    write(@HELP
让你在风云中成立自己的帮派！

指令格式: 
bang xuelianjiao 雪莲教 教主

此指令让你创立一个新的帮，派，或教。 
并封你为雪莲教教主。

又例：

bang bluedress 青衣楼 总管
创立青衣楼并封你为青衣楼总管。
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
                write("对不起，中文名字必须是三到十五个中文字。\n");
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

