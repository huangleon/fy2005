// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
	set_name(HIW "���ǧ�꺮��"NOR, ({ "old iron" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��Ӳ��������ʯ�쿨ס���������Ľ��⡣\n");
		set("value", 1);
		set("rigidity",2000);	
		set("material", "steel");
			set("weapon_material",1);
			set("material_level",40);
			set("desc_ext","��������(40)");
			set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
			set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	}
	::init_dagger(20);
}
