// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

inherit ITEM;

void create()
{
	set_name("��ֽ", ({ "su paper", "paper" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��͢���ϱ���������ֽ�š�\n");
		set("value", 200);
		set("no_split",1);
		set("unit", "��");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);
	}
	::init_item();
}


// by hippo 2009.11

