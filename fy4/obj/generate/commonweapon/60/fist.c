#include <weapon.h>
inherit FIST;
void create()
{
    set_name("����׷����", ({ "ironfist" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
//	set("long", "����һ�Ծ��������ָ��,�������˳��á�\n");
	set("value", 400000);
		set("level_required",50);
	set("weapon_prop/attack",15);
	set("material", "steel");
    }
    init_fist(30);

    set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
    set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}
