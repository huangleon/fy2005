// force_book.c
inherit ITEM;
void create()
{
	set_name("ռ������", ({ "bubook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
			set("unit", "��");
			set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩռ�����Եķ�����\n");
			set("value", 200);
			set("material", "paper");
			set("skill", ([
				"name": 	"foreknowledge",
				"sen_cost":	5,
				"difficulty":	10,
				"max_skill":	20
			]) );
	}
	::init_item();
}


