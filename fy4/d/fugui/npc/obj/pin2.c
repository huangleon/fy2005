
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
    set_name(HIB"����˫����"NOR, ({ "lovepin"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ı���˫���Σ��˶���֮��ƾ�������\n");
		set("unit", "��");
		set("value", 500000);
		set("armor_prop/armor", 1);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����������\n");
		set("female_only", 1);
        }
        ::init_head();
}

