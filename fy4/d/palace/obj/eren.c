
inherit ITEM;

void create()
{
	set_name("��ʯ�߲�ס�Ķ�����", ({ "eren" , "statue"}) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�߱�ʯ�߲�ס�Ķ����񡣸�����ʯ��һ����̵�������������ϸ
�������ƺ��б��˴������������裩���ĺۼ���\n");
		set("value", 1);
	}
}



