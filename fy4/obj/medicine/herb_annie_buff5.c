// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("˫����ʯ",({"nishi"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","һ�����ű�ͮ˫ɫ�İ�͸��Сʯ�������Ƕ�ü��⾭����ҫ�µĲ��\n");
	    set("unit","��");
	    set("base_unit","��");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",360000);
	}
	set_amount(1);
}
