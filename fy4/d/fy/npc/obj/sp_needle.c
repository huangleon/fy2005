// annie

#include <weapon.h>
inherit DAGGER;
void create()
{
    set_name("��ɫ��ϸ��", ({ "needle", "long needle"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ��ϸ�������룬������ţ���ľˮ����������ӬͷС��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N�ӻ�������һ֧$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���뻳�С�\n");
		set("no_give",1);
	}
	::init_dagger(10);
}
