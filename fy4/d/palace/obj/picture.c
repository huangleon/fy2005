// movebook.c

inherit ITEM;

void create()
{
	set_name("���ƹŻ�", ({ "picture"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"���Ŷ��Ѿ������˲��ƹŻ���������һЩС��\n"
			"�ڳ�һЩ�������²�����̬��\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"zuixian-steps",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	10		
		]) );
	}
}
