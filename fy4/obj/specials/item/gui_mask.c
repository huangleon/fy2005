#include <armor.h>
inherit MASK;

void create()
{
	set_name("�������", ({ "gui mask" , "mask"}) );
	set_weight(4);
	if(clonep()) 
	    set_default_object(__FILE__);
	else {
    	set("unit", "��");
    	set("long", "һ����Ŀ�����Ĺ�����ߡ�\n");
    	set("material", "cloth");
    	set("value", 30000);
        set("armor_prop/long", ({"���ϴ���һ����Ŀ�����Ĺ�����ߡ�\n"}) );
    	set("holiday", "���");
    }
    ::init_mask();
}



