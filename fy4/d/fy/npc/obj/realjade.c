// movebook.c

inherit ITEM;

void create()
{
	set_name("��ɲ��", ({ "luosha" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("for_bandit",1);
		set("long",
			"�������ɲ���Ͽ̵�����Ǭ�����Ρ�\n");
		set("value", 0);
		set("material", "stone");
		set("skill", ([
			"name": 	"qiankunwuxing",	
			"exp_required":	1000000,				
			"sen_cost":	10,				
			"difficulty":	20,		
			"max_skill":	99		
		]) );
	}
	::init_item();
}
