#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("���", ({ "qin","���" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 20000);
		set("material", "wood");
		set("timbre",40);
		set("long","����һ�ѽ�������Ů��ϲ�õ����٣���������������峺��������40��\n");
		set("wield_msg","$N�ӻ���ȡ��һ��$n������һ����Ȫˮ���������ָ����к������\n");
		set("unwield_msg","$N��$n���������\n");
	}
	::init_staff(1);
}


void init()
{
   	if (environment()==this_player())
   		add_action("do_play","play");
}

int do_play(string arg)
{
   	object me;
   	me = this_player();

   	if (!arg || arg != "qin") {
      		tell_object(me, "��Ҫ��ʲô��\n");
      		return 1;
   	}
   	message_vision("$N���ⲦŪ�˼���"+name()+"�����������������䲻������ȴҲ������Ȥ����\n",me);
   	return 1;
}
