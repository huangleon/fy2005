#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("�ݻƵ�Ҷ", ({ "deadleaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",     "һƬ�ݻƵ���Ҷ��˥�ܶ����䡣\n");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",10);
	}
	set_amount(10);
    ::init_throwing(2);
}
