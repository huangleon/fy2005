
inherit ITEM;

void create()
{
	set_name("������", ({ "bomb" , "������"}) );
	set_weight(5000);
	set("explosive",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ǿ��ը���Ļ�����\n");
		set("value", 1000);
	}
}



