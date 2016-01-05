#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("��������", ({ "drunk monk","monk","drunk" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$Nһ�����ţ��԰��������˲��Ͳ����ˣ�����ôû�뵽��\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N����Сɮ����Сɮ��Ҳ���ƽ��ˣ���\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N������ֵ��������ȣ������Ϲ�����\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,3);
	message_vision("$N������������˹�����\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIG"\n$N�������ʱ�з紵ᦶ����Ƿ綯����ᦶ���\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIG"\n$N˫�ֺ�ʮ����λʩ�����ɷ�ʩ��СɮһЩ��Ǯ��\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIG"\n$N�����촽��Ц�������϶���صİ������㻹���ǲ���\n\n"NOR,this_object());
		break;
	}
}