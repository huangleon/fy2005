// movebook.c

inherit ITEM;

void create()
{
	set_name("���ľ�", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�\n"
			"�ᵽһЩ���ľ��Ŀھ���\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"iceheart",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	10		
		]) );
	}
}
