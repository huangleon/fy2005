#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( "��ͷ��", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������Ĵ󽣡�\n");
		set("value", 1);
		set("material", "steel");
		set("rigidity", 2);
		set("wield_msg", "$N�ӽ����г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(10);
}

