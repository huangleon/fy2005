#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("��ڵ�С��", ({ "black blade", "blade" }) );
	set_weight(15000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("value", 0);
	    set("material", "steel");

			set("weapon_material",1);
			set("material_level",80);
			set("desc_ext","��������(80)");

	    set("long", "һ����״�����صĵ���������ڣ�������ڡ�\n");
	    set("wield_msg", "$N����ڵĵ����г��һ��$n\n");
	    set("unequip_msg", "$N�������е�$n��\n");
	}
	::init_blade(10);
}
