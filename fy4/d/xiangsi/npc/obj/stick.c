#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIB"ʮ����ͷ��"NOR, ({ "dragon stick","stick" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������ľ�Ĺ���һֱ���Բ�ȵ�������������������һ�������������Ŀ\n����������צ�������ѵ������ڿն��ϣ����Ƕ�ͷ��������Х��\n");
                set("value", 0);
                set("material", "iron");
				set("no_get",1);
				set("nodrop_weapon",1);
                set("wield_msg", "$N����$n����ΡΡ������������\n");
                set("unwield_msg", "$N̾�˿��������������е�$n��\n");
        }
        ::init_staff(125);
}

int init()
{
//	::init();
	set("weapon_wielded","��");
}