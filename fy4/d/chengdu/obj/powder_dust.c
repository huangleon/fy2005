#include <ansi.h>
//#include <weapon.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("�����Ļ�ҩ��", ({ "powder dust" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"��ƺ�û�г��ȼ�յĻ�ҩ������"
);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 70);
		set("base_value", 0);
		set("volumn",1);
	}
	set_amount(1);
}
