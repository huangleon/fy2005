
inherit ITEM;

void create()
{
	set_name("�׻���", ({ "pearl" , "�׻���"}) );
	set_weight(1);
	set("explosive",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������ö��ƣ�һ����ǿ��ը�����׻��顣
��������¶��ʱ�䳤�ˣ���ҩ�������ƺ�������ࡣ
����Ҳը����ʲô�����ˡ�\n");
		set("value", 10);
	}
}
