// annie 07.2003
// dancing_faery@hotmail.com

// love me? give me rebirthflower :>...

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����ͤ");
        set("long", @LONG
�������������������̡�����ͤб����ʯ�Ʒ����һ�������ϣ�ͤ�Ӳ�
��ͤ��Ҳ�Ѿ���Щ���࣬ȴ��ռ����һɽ���¿�������ĵ��ơ�վ��ͤ�м�
Ŀ��ȥ������ɽ����������������۵ף���Զ����һƬֱ��Զ���ãã���Ρ�
�ݴ��ڷ�����ˬ���������ʱ���ܿ���������Զ�����ε�һ��С����
LONG
        );
	set("objects", ([
		__DIR__"obj/corner" : 1,
		__DIR__"npc/seablue" : 1,
	]));

	set("item_desc", ([
		"����": "��Ŀ�����£������±��Ͼ����ż�Ƭ��Ҷ��һ��������\n",
		"cliff": "��Ŀ�����£������±��Ͼ����ż�Ƭ��Ҷ��һ��������\n",
		"flower": "һ�����޵���ɫС����������ط��ŵ���Ѫ�⣨pick��\n",
		"��": "һ�����޵���ɫС����������ط��ŵ���Ѫ�⣨pick��\n",
		"����": "һ�����޵���ɫС����������ط��ŵ���Ѫ�⣨pick��\n",
	]) );

	set("exits",([
  		"west" : __DIR__"haoyue",
	]) );

	set("outdoors", "xiangsi");

	set("flower",1);

	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

void init()
{
	add_action("do_pick", "pick");
}


int do_pick(string arg)
{
   
   	object me, tea;
	int i;

   	me = this_player();
	i = me->query_skill("move",1);
      
	if(!arg || (arg != "flower" && arg != "��" && arg!= "����" && arg!= "С��" && arg!="������"))
	{
		write("��Ҫժʲô��\n");
		return 1;
	}
	if (!query("flower"))
	{
		write("�㶨��һ��������ֻ����Ҷ��ҡ�����ﻹ�л��ڣ�\n");
		return 1;
	}

	if (me->query("agi") < 36) {
		message_vision(CYN"$N�ճյĿ��ŷ���ҡҷ�Ļ��䣬��ɫ��Ȼ��\n"NOR,me);
		write("���������ȥժ���Ƕ仨ֻ��ˤ��ʬ���޴棬�������˰ɡ�\n");
		write("��������Ҫ36��ʵ���ٶȲ��п��ܳɹ���\n");	// 170 move + 2 ability if you don't distribute and w/o master
		return 1;	
	}
	
	if (i<201 && !me->query_temp("annie/pick_soulflower"))	// ֻҪ��research������Զ��һ��Σ�յ����񣮣���
	{
		me->set_temp("annie/pick_soulflower",1);
		message_vision(CYN"$N�ճյĿ��ŷ���ҡҷ�Ļ��䣬��ɫ���硣\n"NOR,me);
		write("�����������ȥժ�±��ϵĻ���Ȼ��ЩΣ�ա�\n");
		write("���Ƿ��������һ�У�ȥժ���Ƕ仨��\n");
		return 1;
	}
	if (i>200)
	{
		add("flower",-1);
		tea = new(__DIR__"obj/rebirthflower");
		tea->move(me);
		message_vision(CYN"\n$N����һ�ڳ�����Ծ������ͤ�⣬�������С����ȥ��
ɲ�Ǽ�$N��׹�����ߣ�����˫ָһ����������������С�

$N��һ���������ڿ��е�������һ�׳��������ͤ����
һ����䣬$N�Ѿ��������ŵĴ�ͤ���ݽ������ȵ��������ڵ��ϣ�ָ���̼��Ž��޵�"HIB"������"NOR CYN"��\n\n"NOR,me);
		return 1;
	}
	me->set_temp("annie/pick_soulflower",0);
	if (i <= 120)
	{
		message_vision(CYN"\n$N̾��һ��������һ�ڳ�����Ծ������ͤ�⣬�������С����ȥ��
ɲ�Ǽ�$N��׹�����ߣ�����˫ָһ����ȴû�ме�������

$N����һ�����Ѿ�������������ȥ��ֻ��һ���Ƴ��Ĳҽд���������\n\n"NOR,me);
		me->add_temp("block_msg/all",1);
		me->move("/obj/void");	// ������ʬ�嶼û����...
		me->set_temp("last_damage_from","Ϊժ"HIB"������"HIY"��������׹����ȥ��ʬ���޴档");
		// �ţ�ͨ��һ��....
		me->add_temp("block_msg/all",-1);
		me->die();
		return 1;
	}
	message_vision(CYN"\n$N̾��һ��������һ�ڳ�����Ծ������ͤ�⣬�������С����ȥ��
ɲ�Ǽ�$N��׹�����ߣ�����˫ָһ����������������С�\n\n"NOR,me);

	add("flower",-1);	// �����Ƿ�ɹ������Ѿ�û���ˡ�

	if ( random(i-120) > 8 )	// 200lv��90%����,170lv��84%,150lv��73%���ᣬ��dummies
	{
		message_vision(CYN"$N����չ����ֱ�ϳ壬������һ����������֮ʱץסͤ����\n"NOR,me);
		tea = new(__DIR__"obj/rebirthflower");
		tea->move(me);
		message_vision(CYN"$N�Ǳ������Ĵ�ͤ�����˽�����С�ĵ��պ�"HIB"������"NOR CYN"��Ĩ��һ���亹��\n"NOR,me);
		return 1;
	}
	else
	{
		message_vision(CYN"��Ҫ��һ������ȴ����$N�������᲻������\n"NOR,me);
		message_vision(CYN"ֻ��һ���ҽУ�$N��������ֱֱ׹ȥ������\n\n"NOR,me);
		me->add_temp("block_msg/all",1);
		me->move("/obj/void");
		me->set_temp("last_damage_from","Ϊժ"HIB"������"HIY"��������׹����ȥ��ʬ���޴档");
		me->add_temp("block_msg/all",-1);
		me->die();
		return 1;
	}
    return 1;
}

void reset()
{
	::reset();
	if (NATURE_D->get_season() < 3)	// ���Ķ���
		set("flower",1);
}


