
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
    set_name(HIG"���������"NOR, ({ "greenpin"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ĳ�������롣���Ÿ߹�������˼\n");
		set("unit", "��");
		set("value", 500000);
		set("armor_prop/armor", 15);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
        }
        ::init_head();
}

