#include <armor.h>
inherit HEAD;

void create() {
	set_name("�߹�", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ������ƽ�߹ڣ�����ȥ�����ޱȣ���ʵֻ������ͨ�Ĳ����Ƴɡ�\n");
		set("value", 800);
		set("material", "cloth");
	}
	::init_head();
}
