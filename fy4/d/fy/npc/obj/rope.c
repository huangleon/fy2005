#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name(HIW"�������"NOR, ({ "colorful rope", "rope" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������糤�����ӣ��������ֲ�ͬ��ɫ��˿���������ġ�\n");
		set("unit", "��");
		set("value", 6);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
		set("female_only", 1);
		set("colorfulrope",1);

	}
	::init_head();
}

