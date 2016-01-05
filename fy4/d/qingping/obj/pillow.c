inherit ITEM;
void create()
{
   set_name("�����", ({ "bamboo pillow", "�����", "pillow" }) );
   set_weight(500);
   set_max_encumbrance(100);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "��");
      set("long", "���Ǹ����������ɵ�С��ͷ�����׳�����ˡ�\n");
      set("value", 100);
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
   if (!arg || (arg != "bamboo pillow" && arg != "�����" && arg != "pillow"))
      return 0; 
   if(ob->query_temp("marks/opened"))
      return 0;
   message_vision("$NС������ذ�����˴Ӳ���򿪡�\n",me);
   set("long", "�������ɵ�С��ͷ�����˴Ӳ�����ˡ�\n");
   item = new(__DIR__"paper1");
   item->move(ob);   
   ob->set_temp("marks/opened", 1);
   return 1;
   
}
