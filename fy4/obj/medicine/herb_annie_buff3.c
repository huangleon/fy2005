// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("��¶ˮ",({"bailu"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ������͸����¶�飬��˵���ڰ�¶�����ռ����á�\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",60000);
	}
	set_amount(1);
}
