inherit ITEM;

void create()
{
	set_name("�Ʒ�����", ({ "unarmed book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ����Ǿ������˷��ģ������ƺ�д��\n"
			"һЩ�Ʒ�ʲ��Ŀھ���\n");
		set("value", 0);
		set("material", "paper");
		set("no_transfer",1);
		set("skill", ([
			"name": 	"unarmed",	
			"exp_required":	100000,				
			"sen_cost":	5,				
			"difficulty":	10,		
			"max_skill":	74,
			"literate":	"unarmed",		
			"liter_level":	65,
		]) );
	}
	::init_item();
}
