inherit ITEM;

void create()
{
	set_name("�ȷ�����", ({ "staff book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ����Ǿ������˷��ģ������ƺ�д��\n"
			"һЩ�ȷ��Ŀھ���\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name": 	"staff",	
			"exp_required":	100000,				
			"sen_cost":	10,				
			"difficulty":	20,		
			"max_skill":	50		
		]) );
	}
	::init_item();
}
