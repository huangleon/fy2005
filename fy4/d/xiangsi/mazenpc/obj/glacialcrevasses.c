#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"����"NOR, ({ "glacial crevasses","crevasses"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("lore",1);
		set("long", "һ��ͨ���ף����ּ����������䵶��\n");
		set("material", "ice");
		set("ice_blade",1);
		set("level_required",60);
		set("value",50);
	}
	::init_blade(85);
}

