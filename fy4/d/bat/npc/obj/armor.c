#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name( HIY"��˿���"NOR, ({ "armor" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "leather");
		set("value", 1000);
		set("armor_prop/armor", 20);
		set("strength",30);
		set("long","����һ���ƽ�ǽ����·��µ���ף������ķų����˵Ľ�ɫ��â��
һ�������������䡣\n");
	}
	::init_cloth();
}
