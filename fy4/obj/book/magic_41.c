// force_book.c

inherit ITEM;

void create()
{
	set_name("����", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
		"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩ������������ʲ��ġ�\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name":	"magic",		
			"exp_required":	8000,			
			"sen_cost":	10,
			"difficulty":	20,	
			"max_skill":	40
		]) );
	}
	::init_item();
}
