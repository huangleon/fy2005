#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("�һ�֦", ({ "taozhi", "tao" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����濪���ۺ�ɫ�����֦����\n");
		set("value", 5);
		set("rigidity", 5);
        set("material", "wood");
        set("wield_msg", "$N�ó�һ�����濪���ۺ�ɫ�����$n�������С�\n");
        set("unwield_msg", "$N�������е�$n��\n");
    }
    ::init_staff(5);
}



