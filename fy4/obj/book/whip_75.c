inherit ITEM;

void create()
{
	set_name("�޷�����", ({ "whip book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ����Ǿ������˷��ģ������ƺ�д��\n"
			"һЩ�޷��Ŀھ���\n");
		set("value", 0);
		set("material", "paper");
		set("no_transfer",1);
		set("skill", ([
			"name": 	"whip",	
			"exp_required":	100000,				
			"sen_cost":	5,				
			"difficulty":	10,		
			"max_skill":	74,
			"literate":	"whip",		
			"liter_level":	65,	
		]) );
	}
	::init_item();
}
