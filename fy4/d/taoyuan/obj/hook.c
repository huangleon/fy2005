inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("С����", ({ "hook" , "gou zi", "С����"}) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ��СС�Ĺ��ӣ�������������������Ĺ��ӣ�Ҳ���������
������һ������ˡ�������壩 \n");
        set("value", 10);
    }
    ::init_item();
}

void init()
{
   if(this_player()==environment())
   add_action("do_make", "make");
}

int do_make(string arg)
{
   int i,yxan=0,bamboo1=0;
   object fpole, me, xan, bamboo, *inv;

   me = this_player();
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
      if(inv[i]->query("name") == "����") {yxan=1; xan = inv[i];}
      if(inv[i]->query("name") == "ϸ���") {bamboo1=1; bamboo = inv[i];}
   }
   if ( yxan && bamboo1)
   {
      destruct(xan);
      destruct(bamboo);
      fpole = new(__DIR__"fpole");
      fpole->move(me);
      message_vision("$N�����ɵ�˫�������һ�����µ�С��ˡ�\n", me);
      destruct(this_object());
   }
   else
      message_vision("$N��Ū����������ߡ�\n", me);
   return 1;
}




