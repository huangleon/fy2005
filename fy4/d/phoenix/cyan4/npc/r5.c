#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("��Ⱥ��ӵ����", ({ "drunk" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N�������ż��Ц�����ߣ��ߣ������ȥ���Ź��ٺ�һ����\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N�ֹ�����Ҳ��֪�������ǻ������ǰ�����\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N���˸����õ���������Ϧ�����ӣ�\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,5);
	message_vision("$N����ת�����˹�����\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIG"\n$N��Ц���ã��þƣ�\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIG"\n$N���볪�����廨����ǧ���ã��������������ƣ�\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIG"\n$N˻����������裺�һ����������������ۻ�֦����Ǯ��������������Ǯ��������\n\n"NOR,this_object());
		break;
	}
}