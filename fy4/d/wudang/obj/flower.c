#include <armor.h>
inherit HEAD;

void create()
{
	string *names = ({
	        "��軨", "ץ��������", "�������", "���ɹ���",
	});
	
	set_name( names[random(sizeof(names))], ({ "flower" }));
	set_weight(30);
	if( clonep() ){
		set_default_object(__FILE__);
	} else {
		set("unit", "֦");
		set("value", 50);
		set("material", "wood");
		set("armor_prop/armor", 2);
	}
	::init_head();
}
