inherit ITEM;

void create()
{
	set_name("������", ({ "guyupai" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������Ͽ̵�����������������\n");
		set("value", 10000);
		set("no_drop",1);
		set("material", "stone");
		set("skill", ([
			"name": 	"force",	
			"exp_required":	20000,				
			"sen_cost":	10,				
			"difficulty":	10,		
			"max_skill":	119,
			"literate" :    "force",
			"liter_level":  100,		
		]) );
	}
}
