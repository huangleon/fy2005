// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���Ƶ���", ({ "taopao","cloth" }) );
	set_weight(1000);
	set("long", "һ���������Ƶĵ��ۣ����������š�������������С�֡�\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 1000);
	}
	::init_cloth();
}