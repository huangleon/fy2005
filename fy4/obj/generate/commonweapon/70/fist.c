#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
    set_name(HIY"��ɳӥ��"NOR, ({ "claw" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "��");
//	set("long", "����һ�Ծ��������ָ��,�������˳��á�\n");
	set("value", 500000);
		set("level_required",70);
	set("weapon_prop/attack",17);
	set("material", "steel");
    }
    init_fist(35);

    set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
    set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");


}
