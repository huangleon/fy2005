#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(HIR"���괮"NOR, ({ "redlace"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����괮,��ϳ��˵����顣\n");
		set("unit", "��");
		set("value", 500000);
		set("wear_msg", "$N����ذ�һ��$n���ڲ����ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����������\n");
		set("female_only", 1);
        }
        ::init_neck();
}

