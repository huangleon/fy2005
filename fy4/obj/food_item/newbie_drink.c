// Silencer @ FY4 workgroup. Oct.2004

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���«", ({ "hulu", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "
���������Ǹ֣��ڷ����ﲻ�Բ�����Ȼ������������������еĻָ�����ֹͣ��
���Ե����ʳ����ˮ���˾�Ҫ��ʱ���䡣����һ��ʢ����Ȫˮ�����«�����
������������롡���������ȡ�����������أ�����ˮԴ�ĵط�������
˵���Ƴ���ķ�˿�ջ�������ã���졡�����������¹�����\n");
		set("unit", "��");
		set("value", 0);
		set("no_drop",1);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "��Ȫˮ",
		"remaining": 60,
	]) );
}
