inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIC"�޵б���"NOR, ({ "wudi book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
		set("long",
            "һ������ɵ�С�ᣬ�������ʲݵ�д�š��޵б���֮����ƪ����\n");
        set("value", 7000);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_sell", 1);
		set("material", "silk");
		set("skill", ([
            "name":         "longlife-force",    
			"exp_required":		1000000,		
			"sen_cost":		10,	
			"difficulty":		20,	
			"max_skill":		50		
			]) );
	}
	::init_item();
}
