#include <weapon.h>
inherit FIST;
void create()
{
    set_name("����", ({ "ironfist" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
		set("level_required",10);
	set("unit", "��");
//	set("long", "����һ�Ծ��������ָ��,�������˳��á�\n");
	set("value", 2000);
	set("weapon_prop/attack",5);
	set("material", "steel");
    }
    init_fist(10);

    set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
    set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}
