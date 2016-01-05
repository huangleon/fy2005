#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(HIG"������"NOR, ({ "zheshan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱���µ�ߡ�ȣ������ϻ��Ű���ѩ��ͼ��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$nչ�����������������¡�\n");
		set("unwield_msg", "$N�����е�$n�����������С�\n");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
	}
	::init_dagger(1);
}


void init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
	object me=this_player();
	mapping buff;
	if (!arg || present(arg,me) != this_object())
		return 0;
	if (me->query_weapon() != this_object())
		return 0;
	if( ANNIE_D->check_buff(me,"fastrecover")) 
		return notify_fail("����������ʩչ���Ƶ�������\n");
	buff =
	([
		"caster":me,
		"who":me,
		"type":"fastrecover",
		"att":"bless",
		"buff1":"annie/fast_heal",
		"buff1_c":15,
		"name":"�����ȡ�������ת",
		"time":300,
		"buff_msg":"$Nչ��"HIG"������"NOR"��һ�󵭵�������������ɢ��������\n",
	]);


	ANNIE_D->buffup(buff);

	me->perform_busy(2);
	return 1;
}




