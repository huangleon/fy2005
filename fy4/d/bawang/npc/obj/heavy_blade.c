#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIR"�Ż��󿳵�"NOR, ({ "nine-ring blade","blade" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("long", "����һ�������񱳴󿳵��������Ͼſף�ÿ�״�һ����������Լ������
ʮ���ء�\n");
		set("wield_msg", "�������ʡ�һ�죬$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n���ڱ���\n");
	}
	::init_blade(15);
}
