#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(WHT"����"NOR, ({ "glacier"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("lore",1);
		set("no_get",1);
		set("long", "����һ�������Ӵ�ı�����\n");
		set("material", "ice");
		set("ice_blade",2);
	}
	::init_blade(50);
}

