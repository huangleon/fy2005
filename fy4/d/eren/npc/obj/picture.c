inherit ITEM;


void create()
{
	set_name("��Ƥֽ" , ({ "paper"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("24dao",1);
		set("unit", "��");
		set("long", "һ�Ų�ͼ��ͼ����һ��С���Ļ���\n");
		set("value", 100);
	}
	::init_item();
}



