inherit ITEM;

void create()
{
	set_name("Сֽ����", ({ "paper" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��Сֽ����������д���������ɲ�������֣�\n���꾫���ϡ�\n������������������ ��");
		set("no_split",1);
		set("unit", "��");
	}
	::init_item();
}


// ���p��dancing_faery@hotmail.com

