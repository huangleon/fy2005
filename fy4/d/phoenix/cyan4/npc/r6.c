#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("��֪С��", ({ "kid" }) );
	set("no_attack",1);
	set("value",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N��޵�������ְ֣��л���������ң�\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N��е����׹��׹�����������������ˣ�\n\n"HIW"ֻ���þ���է�죬һ��ѩ������������������������߰��֮�ԣ�\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$Nҡͷ����ɱ���ǲ�������������������˲���һ���˵�����\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,6);
	message_vision("$N��ǰ�ƺ�ӵ�س��˹�����\n",this_object());

}