//Xxder@fy3
inherit ITEM;
void create()
{
	set_name("����", ({ "kite" }) );
	set_weight(150);
        set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("prep", "on");
		set("long", "һ���������ݣ��ŷ��ݵ����ϰ���һ��СС�����ڡ� \n");
		set("desc_ext","play kite");
		set("value", 4);
	}
}

void init()
{
        add_action("do_play", "play");
}


int do_play(string arg)
{
   object me, ob;    
   if (!arg || (arg != "kite" && arg != "����")) return 0;
   me = this_player();
   ob = this_object();
   if( me->is_fighting() )
      return notify_fail("��ս���зŷ��ݣ���������\n");
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɣ����ܷŷ��ݡ�\n");
   message_vision(me->name()+"�ͳ�һ��" + ob->name() + "����û��Ų�������\n", me);
   environment(me)->kite_notify(ob, 0);
   return 1;
}

