#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name("����", ({ "wolf leg"}) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "����һ����������ϳ������Ĵ��ȣ��ƺ����Ե�����ʹ��\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��֪��ʲô�ط�����һ��Ѫ���ܵ�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n����\n");
	}
    ::init_hammer(20);
}
