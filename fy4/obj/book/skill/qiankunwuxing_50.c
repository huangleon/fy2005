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
		set("long",	"�������ɲ��ͨ��Ө�ף���ħ֮����������������һ��С�֣�
�̵�����Ǭ�����ε��������š�\n");
		set("no_drop", 1);
		set("value", 200);
		set("material", "stone");
		set("skill", ([
			"name": 	"qiankunwuxing",	
			"exp_required":	600000,				
			"sen_cost":	2,				
			"difficulty":	5,		
			"max_skill":	49,		
		]) );
	}
	::init_item();
}
