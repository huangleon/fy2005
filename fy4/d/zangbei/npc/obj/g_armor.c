#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("���Ӽ�", ({ "chainarmor"}) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "gold");
		set("long", "һ�����ִ�ɵ����Ӽס�\n");
		set("value", 100);
		set("armor_prop/armor", 15);
	}
	::init_cloth();
}
