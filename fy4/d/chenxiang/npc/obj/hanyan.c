
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("���˺���ǹ", ({ "hanyan" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���̹���ȭͷ��С�ĳ��˺���ǹ��\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	::init_dagger(5);
}
