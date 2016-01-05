#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	int i;
	i=3000+random(7000);
	set_name("���µ�"+CHINESE_D->chinese_number(i), ({ "super highhand","highhand","hh" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N���ֵص�Բ˫Ŀ������ô���ܣ���ɱ�Ϸ�$N��Ī������Ǵ�˵�е����µ�"+CHINESE_D->chinese_number(i-1)+"��\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$Nҧ�������ɣ����ɺޣ��ϣ����Ϸ�ģ������µ�һ�����ᣮ������\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N˵�����������ŵ����ﵱ�˰壬�������֣���������ԩ����\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,4);
	message_vision("$N������������˹�����\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIY"\n$N���´�����һ�ۣ��ٺ���Ц����Ҳ������˶��ѡ�\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIY"\n$N������һ�ۣ�С�ӣ���ƾ��Ҳ����ס�ң�\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIY"\n$N��Ц�����Ϸ���$N����֪С�������������\n\n"NOR,this_object());
		break;
	}
}