#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create() {
	set_name("���꽣", ({"xiaohun sword", "xiaohun" }));
    	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("long", "�����꣬�˶ϳ����˱��롣\n");
		set("value", 0);
		set("block_rate",5);
		set("block_level",0);
	}
	::init_shield();
}


