
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("���ʳ���", ({ "black blade","blade" }) );
	set_weight(1000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "����һ��������һ��ȱ�ڵ�������\n");
	    set("value", 100);
		set("rigidity", 15000);
	    set("material", "steel");
	}
	::init_blade(20);
}

