// force_book.c
inherit ITEM;
void create()
{
	set_name("ȭ�����", ({ "quanbook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
			set("unit", "��");
			set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩ������ȭ�ŷ�����û��ȡ�˸���ô����������֡�\n");
			set("value", 200);
			set("material", "paper");
			set("skill", ([
				"name": 	"unarmed",
				"sen_cost":	5,
				"difficulty":	10,
				"max_skill":	20
			]) );
	}
	::init_item();
}


