#include <weapon.h>
inherit FIST;
void create()
{
    set_name("����צ", ({ "claw" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
//	set("long", "����һ�Ծ��������ָ��,�������˳��á�\n");
	set("value", 20000);
		set("level_required",20);
	set("weapon_prop/attack",7);
	set("material", "steel");
    }
    init_fist(15);

    set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
    set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}
