#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("ľ��", ({ "ting","qin" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "wood");
		set("long", "һ����ɫ���㡢Ȼ��ȴ���·��Ƴ���ľ�١�������5��\n");
		set("timbre",5);
		set("wield_msg","$N�ӻ���ȡ��һ��$n������һ����Ȫˮ���������ָ����к������\n");
		set("unwield_msg","$N��$n���������\n");
	}
	::init_staff(5);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_play","play");
}


int do_play(string arg)
{
	object me;
	me = this_player();
	if (!arg || (arg!="qin" && arg!="ľ��" && arg!="��" && arg != "ting"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!me->query("annie/������"))
		return notify_fail("������һƬ�հף���֪���õ�ʲô��\n");
	message_vision("$Nһ��ľ�٣���Ȼ�������������ָ���������������������ˮ��������\n",me);
	me->set_temp("played_qin",1);
	return 1;
}
