#include <armor.h>
inherit HEAD;

void create()
{
	set_name("���ÿ�", ({ "flower" }));
	set_weight(30);
	if( clonep() ){
		set_default_object(__FILE__);
	} else {
		set("unit", "֦");
		set("long","һ֧���ÿ������Ĳ��á�\n");
		set("value", 50);
		set("material", "wood");
	}
	::init_head();
}

void init() {
	if (!query("in_decay")) {
		set("in_decay",1);
		call_out("badmeal", 180);
	}	
}

void badmeal() {
	set("long", "��ή�˵�һ��С����\n");
	set("name", "�ɿݵ����ÿ�");
	set("value", 0);
}