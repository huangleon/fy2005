
#include <armor.h>
inherit HEAD;

void create() {
	set_name("��ձñ", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ����ձñ������ͷ�Ͼ����˸�Сɡ��\n");
		set("value", 8);
		set("material", "cloth");
	}
	::init_head();
}
