
inherit ITEM;

void create()
{
	set_name("���ӹ�ĸ��", ({ "ghostmother" , "mother"}) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ϸ�۲�ʯ���㷢��һ�����ھ��ӹ�ĸ���ϵ�Ӥ�����У�����һ��
��Լ�ߴ�Ķ̽�����ͷָ�����ɽ�ߡ�\n");
		set("value", 1);
	}
}


