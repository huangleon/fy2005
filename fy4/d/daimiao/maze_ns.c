#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","��������");
  set("long",@LONG
���Ǹ����ӵ����硣��Ŀ�����������Ƕ����������ֻ����춥���£��޴�����
������������ӯӯ���档��������������ӳ�����ھ��������ֻʵ�������ӣ�
���Ż�������Χ������Ϥ��������Ӱ��һ˿�־������������ͷ��
LONG
  );
	set("coor/x",99);
	set("coor/y",99);
	set("coor/z",0);
	set("no_fly",1);
		set("item_desc", ([
		"west":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
		"north":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
		"east":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
		"south":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
	]) );
	setup();
}

void init()
{
	if(userp(this_player()))
	{
//	remove_call_out("attack");
	call_out("attack",1,this_player());
	}
}

int attack(object ob)
{
	int i;
	int damage;
	object room;
	if( environment(ob) == this_object())
	{
		if (!room = find_object(__DIR__"dongci"))
			room = load_object(__DIR__"dongci");
		message_vision(HIW"$N���µľ��涸Ȼһ����$N������ֱֱ������ȥ��\n"NOR, ob);
		ob->set_temp("last_damage_from","�ھ�����������̤���������\n");
		damage = ob->query("max_kee") -random(ob->query_kar())+5;
       	ob->receive_wound("kee",damage);
		ob->set("gin",0);
		ob->set("sen",0);
		if (ob->query("kee") > 0)
			ob->set("kee",0);
		ob->move(room);
		return 1;
	}
	else
		return 1;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

