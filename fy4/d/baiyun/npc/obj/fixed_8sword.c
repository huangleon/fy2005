#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	int i;
    set_name(HIC"�콣"NOR, ({ "sky sword","sword" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", "��Զ��ʱ��������ʯ����ľ���֮����Ϊ������������֮����\n�������������ֵ�����֮����\n");
                set("value", 0);
                set("rigidity",5000);   
                set("material", "steel");

			set("weapon_material",1);
			set("desc_ext","��������(90)");
			set("material_level",90);


        	set("material", "steel");
	}
    ::init_sword(10);
}
