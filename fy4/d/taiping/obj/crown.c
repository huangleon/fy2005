#include <armor.h>
inherit HEAD;
#include <ansi.h>

void create() {
	set_name(HIW"�Ͻ�����"NOR, ({ "crown" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ���ǳ�������Ͻ����ڡ�");
		set("value", 800);
		set("material", "cloth");
	}
	::init_head();
}
