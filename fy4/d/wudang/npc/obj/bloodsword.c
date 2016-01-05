// sword.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR"Ѫ��"NOR, ({ "blood sword","sword" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�Ѽ�խ������Ѫ�ۺ���ĳ�����\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N�ӽ����г��һ�����������$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
    ::init_sword(23);
}
