#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(CYN"÷֦"NOR, ({ "plum branch","branch" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ϸ��÷֦��֦�ϵ���ǳ��ɫ�Ļ��ࡣ\n");
                set("value", 0);
                set("material", "wood");
				set("nodrop_weapon",1);
        }
        ::init_staff(1);
}
