
inherit ITEM;

void create()
{
	set_name("�й�����", ({ "judge" , "�й�����"}) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���й��������ֱֳʣ������ս���׿���ڵ��ԣ�����֮��
бб��ָ�����һ��ɽ�ߡ�\n");
		set("value", 1);
	}
}


