
inherit ITEM;

void create()
{
	set_name("������", ({ "tooth" , "budda-tooth"}) );
	set_weight(1);
	set("nature", "fake");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����ɮ������Ϊ����Ҫ�ڽ���һ�������ӡ�\n");
		set("value", 1);
	}
}



