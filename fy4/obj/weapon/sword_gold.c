#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIY"��"NOR, ({ "goldsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ɽ�,Īа�������Ϲ������\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N�ӱ������г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ı����ʡ�\n");
	}
	::init_sword(70);
}

