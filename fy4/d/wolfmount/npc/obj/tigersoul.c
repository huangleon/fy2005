#include <weapon.h>
#include <ansi.h>
inherit HAMMER;	
void create()
{
        set_name(HIB"ս��֮��"NOR, ({ "tiger soul","soul" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǵ�������ȵ�ս�������������İ���֮�ǣ�����֮����\n");
        	set("rigidity", 5000);

                set("value", 1);

                set("material", "iron");
				set("desc_ext","��������(120)");
				set("weapon_material",1);
				set("material_level",120);

        }

        ::init_hammer(20);
}
