
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"���촵Ѫ"NOR, ({ "soulcrasher" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѽ�������һ������ɫѪ�۵ĳ�����\n");
		set("value", 400);
		set("material", "steel");
		set("rigidity", 20000);
		set("wield_msg", "$N����ɫ�����г��һ����һ������ɫѪ�۵�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�����������ɫ���ʡ�\n");
	}
	::init_sword(11);
}
