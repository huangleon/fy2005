// movebook.c

inherit ITEM;

void create()
{
        string *name= ({"������", "�������", "����", "���", "������"});
        set_name( name[random(5)] , ({ "buddbook", "book" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"buddhism",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	15		
		]) );
	}
}
