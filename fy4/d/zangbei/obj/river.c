inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("ɣ�Ѻ�", ({ "ɣ�Ѻ�" , "��", "river"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "ɣ�Ѻ�ˮ��ƽ��������ף�ż���������Ծ��ˮ�档\n");
		set("value", 1);
		set("prep","in");
	}
	::init_item();
}

int is_container() { return 1; }


