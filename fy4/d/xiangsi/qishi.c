// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ʯ��Ӱ");
	set("long", @LONG
���ŵ�·������Ƭ�̣����Ȼ���������ľ�ɫ��������д���ͬ����Ŀ
��ȥ����ǰ�ĵ�·�������ۣ����²�ƽ�������ǻ������ԣ��ƹ��ƻ�����̬��
Ȥ�����������ʯ������Ѥ�Ĺ���͸��ʯ����խ��бӳ�ڵ��棬��֯��һƬ
��������ϡ��Ӱ��
LONG
	);
	set("objects", ([
		__DIR__"obj/rock" : 1,
	]));
	set("exits",([
  		"south" : __DIR__"lvzhu",
		"north" : "/d/eastcoast/palace_path2",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",-10);
	setup();
}

void init()
{	
	object ob;

	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object here = this_object();
	object * inv,robber;
	int i,value=0;
	if( !ob || environment(ob) != here ) return;
	inv = all_inventory(ob);
	for (i=0;i<sizeof(inv) ;i++ )
		value += inv[i]->query("value");
	if (value >= 20000 && value < 100000)		// ������	20K Exp
		robber=new(__DIR__"npc/bandit");
	else if (value >= 100000 && value < 250000)	// ����		1M Exp
		robber=new(__DIR__"npc/fonyan");
	else if (value >= 250000)					// ����¥	7M Exp
		robber=new(__DIR__"npc/fonmanlou");

	if (robber)
	{
		message_vision(CYN"\nһ���ɽʯ��ͻȻת��һ����Ӱ����ס���ȥ·��\n\n"NOR,ob);

		robber->move(here);
		robber->rob(ob);
	}

}

