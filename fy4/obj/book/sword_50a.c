
inherit ITEM;
void create()
{
	set_name("���ʮ��ʽ", ({ "qing feng book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
		set("long",
			"���ǻ�ɽ����ʧ���Ծõ�һ�����ס�\n");
		set("value", 0);
		set("material", "wood");
		set("skill", ([
			"name": 		"sword",	
			"exp_required":	1000,		
			"sen_cost":		3,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
	::init_item();
}
