inherit ITEM;
void create()
{
	set_name("������",({ "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ����ᣬ����д����������ڣ������񹦡�\n");
		
        set("material", "cloth");
		set("skill", ([
			"name": 		"jiayiforce",	
			"exp_required":		50000,		
			"sen_cost":		60,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
    ::init_item();
}

