#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	string *num = ({"��","��","��","��"});
	set_name( num[random(4)]+"�۹�" , ({ "oldguy" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N�޺޵������Ϸ��ܾۣ������۾ƣ�����\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N��޵������ۺ��ۣ����ռ�˰���Ҳ�Ͱ��ˣ�Ϊʲô��Ҫɱ�ң�����\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$NŭĿԲ�ɣ�ƴ�����һ˿�������㣺���㱻�紵�ɣ����һ�ߺ��ǣ�����ף�������ţ�\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,2);
	message_vision("$N������������˹�����\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIW"\n$N����ͨ�죬�����価�Ǿ�ζ��\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIW"\n$N�˾����������ۣ�ȫ������������һ�ų�ζѬ�˵ľ���������\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIW"\n$N�����������û�뵽�����С���������Ѿ�������ô���ˣ����´����ϰ���\n\n"NOR,this_object());
		break;
	}
}