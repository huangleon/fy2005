#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIC"������ڤ��"NOR, ({ "ghoststaff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ƽ�ǽ���ʯ��ʯ�ı��ȣ����Ͽ���������δ������ħ����\n");
                set("value", 10);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ���ƽ�ǽ���ʯ��ʯ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
		set("weapon_prop/astral_vision", 1);
        }
        init_staff(2);
}
