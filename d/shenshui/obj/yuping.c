//XXDER
inherit ITEM;
void create()
{
   set_name("白玉瓶", ({ "yu ping", "bottle", "玉瓶" }) );
   set_weight(500);
   set_max_encumbrance(100);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "个");
      set("long", "一个用蓝田玉做成的小瓶子，瓶口是密封的。\n");
      set("value", 50000);
   }
}

int is_container() { return 1; }

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   object me, item, ob;

   me = this_player();
   ob = this_object();
   if (!arg || (arg != "yu ping" && arg != "白玉瓶"))
      return 0; 
   if(ob->query_temp("marks/opened"))
      return 0;
   message_vision("$N小心翼翼地打开白玉瓶。\n",me);
   set("long", "一个用蓝田玉做成的小瓶子。\n");
   item = new(__DIR__"medicine");
   item->move(ob);   
   ob->set_temp("marks/opened", 1);
   return 1;
   
}
