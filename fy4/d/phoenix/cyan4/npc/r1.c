#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("�������ı���", ({ "drunk guest","guest","drunk" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N˵�����ƣ��������Ҿƣ�����\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$Nҡ�����Դ�����Ϊʲô����������Ҫ������ȥ�����𶯣�����\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N����Ϊʲôɱ�ң��Ұ��㰡������\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,1);
	message_vision("�������ı��Ͷ�����������˹�����\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIR"\n�������ı��ʹ��˸����ã����۵����ң������һ��ܺȣ��ã�����\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIR"\n�������ı�������һ�ò���������ڳݲ����Ц�����ϣ���������ȶ��ˣ���·���������ˡ�\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIR"\n�������ı������۷�ֱ������ײײ����ǰ��ȥ��\n\n"NOR,this_object());
		break;
	}
}