#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIW"�����"NOR, ({ "ice-qin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("material", "wood");
		set("timbre",120);
		set("long",WHT"
ֱ��p˿�����������������ʱ���٣����˰�����������֮���֪Ϊ�Σ�
ʧ���˼䡣������60��\n"NOR);
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

   	if (!arg || arg != "qin" || arg != "ice-qin" ) {
      		tell_object(me, "��Ҫ��ʲô��\n");
      		return 1;
   	}
   	message_vision("$N���ⲦŪ�˼���"+name()+"�������棬���Ʊ��ġ�\n",me);
   	return 1;
}
