
#include <ansi.h>
inherit ITEM;

void create() {
	set_name("����", ({ "iron pestle","pestle" }) );	
	set_weight(80000);
	set("long", " һ���޴������,��Ϊ�����Զ,��������,�����⼣�߰�,�ഫ����۾����걾Ϊ���ֹ� 
̫�ӣ���������Ԫ����Ϊ�����㻯������ĥ���룬������Ȼ�ɣ������У����������� 
��������������ƣ���ǧ�����������޵ڶ����ܽ�������ĥ�������䣩���룮 \n");
	set("unit", "��" );
	set("value", 100);
	set("no_get",1);
    if( clonep() )
       set_default_object(__FILE__);

}

void init()
{
	add_action("do_grind","grind");
}



int do_grind(string arg)
{
	object player,needle;
	int i, max_sen, max_gin;
	player = this_player();
	max_sen = player->query("max_sen");
	max_gin = player->query("max_gin");
	if (arg != "����" && arg != "pestle" && arg != "iron pestle")
	{
		return 0;
	}

	tell_object(player,"��Ȼ�Ѿ�˵�����޵ڶ����ˣ����ֺα�����������֮���أ�\n");
	return 1;

	if (player->query("marks/�䵱_ִ��"))
	{
		message_vision(" $N�������Ƶ��˵࣬̾�˿����� �૵�������ĥ���룬������Ȼ�ɣ��������������ж������������ء�������  \n",player);
		return 1;
	}
	if(player->is_busy()) return notify_fail("��Ķ�����û����ɣ�����ĥ�롣\n");
	
	if (player->query("sen") <= max_sen /10 || player->query("gin") <= max_gin /10)
	{
		return notify_fail("������̫���ˣ�����ĥ�롣\n");
	}
	i = player->query_temp("totalgrindtimes") + 1;
	player->set_temp("totalgrindtimes",i);
	player->add("gin",-(max_gin/20));
	player->add("sen",-(max_sen/20));
	message_vision("$N���ĵذ������ڽ�ȪϪʯ��һ��һ��ĥ�ţ�ĥ�ţ����� \n",player);
	tell_object(player,"���ƿ���ȥ�ƺ�����ϸ�˵㣮���� \n");
	player->start_busy(2);
	if (i <= 500)
	{
		return 1;
	}
	if (random(500))
	{
		return 1;
	}else
	{
		message_vision("$Nĥ��ĥ�����������ڱ�$Nĥ�������룡�� \n",player);
		player->set("marks/�䵱_ִ��",1);       	
		needle = new(__DIR__"needle");
		needle->move(player);
		player->delete_temp("totalgrindtimes");
		destruct(this_object());
		return 1;
	}
}
