#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIW "�����"NOR, ({ "cang qiong" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��û�н�ͷ�ĳ���\n");
		set("value", 1);
		set("rigidity",2000);	
		set("material", "steel");

			set("weapon_material",1);
			set("material_level",110);
			set("desc_ext","��������(110)");
    }
	::init_sword(10);
}

