
//  meat.c
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("����", ({ "fried meat", "meat" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ŀ���\n");
                set("unit", "��");
                set("value", 3);
                set("food_remaining", 4);
                set("food_supply", 4);
                set("material", "bone");
                set("decayed",0);
        }
        ::init_item();
}
void eat_decayed(object me)
{
   int waittime;
   waittime=5-me->query_con()/10;
   if (waittime<1) waittime=1;
   me->start_busy(waittime);
   message_vision("$N��Ȼ���ö����ﹾཹ��ֱ�죬���˿�ɾ��ط��Ͷ�������...\n�أ��ó���\n", me);
   return;
}
int do_eat(string arg)
{
   int foo;
   foo=::do_eat(arg);
   if (!foo) return foo;
   if (query("decayed")<1)
       message_vision("$N����" + name() + "�ǳ��óԣ���������һ����\n", this_player());
   else
   {
     message_vision("$N����" + name() + "ζ���ֵֹġ�\n", this_player());
     call_out("eat_decayed",this_player()->query_con()/5+1,this_player());
   }
  return 1;
}
