
inherit ITEM;

void create()
{
	set_name("�׻���", ({ "pearl" , "�׻���"}) );
	set_weight(1);
	set("explosive",2);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������ö��ƣ�һ����ǿ��ը�����׻��顣
�ڶ������������£���ҩ������ô�������\n");
		set("value", 10);
	}
}
