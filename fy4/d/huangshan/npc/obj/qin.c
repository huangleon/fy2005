#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("��ľ��", ({ "muqin" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɫ���㣬�����ڰ������������١�������40��\n");
                set("value", 10);
                set("material", "iron");
                set("wield_msg","$N�ӻ���ȡ��һ��$n������һ����Ȫˮ���������ָ����к������\n");
		set("unwield_msg","$N��$n���������\n");
		set("timbre",40);
        }

        ::init_hammer(20);
}
