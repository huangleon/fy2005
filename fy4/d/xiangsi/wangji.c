// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�����ܲ�");
        set("long", @LONG
��֧·���·��ȣ�ֻ��һ��ټ��ɽ�����������������������ɼ���������
���֣�ԭ���˴�������¹�����ݣ������زأ����߽����У�ֻ���������۴�
���������ڱ��ϣ�����ɫ������ӳ������������������һ��������ͦ������
����������վ��һ������֮�£����������е��鼮��
LONG
        );
	set("objects", ([
		__DIR__"npc/wuge" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"nanzoulang",
	]) );

	set("item_desc", ([
		"���": (: look_stone :),
	]) );

	set("indoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
}

int init()
{
//	add_action("do_patch","patch");		disabled upon further investigation.
	add_action("do_patch","repair");
}

void reset()
{
	::reset();
	if (!random(20))
		present("xue wuge")->set("bladebook",1);
	if (!random(20))
		present("xue wuge")->set("spellsbook",1);
	present("xue wuge")->set("starrain",1);
}

string look_stone()
{
	object me = this_player();
	if (random(me->query_temp("annie/xiangsi_bookcase"))<30 || query("no_book"))
	{
		tell_object(me,"һ��������������������еĳ�����ҳҲ�Ѿ�����Ʊߡ�\n");
		me->add_temp("annie/xiangsi_bookcase",1);
		me->set_temp("annie/xiangsi_bookcase2",0);
		return " ";
	}
	tell_object(me,"һ��������������������еĳ�����ҳҲ�Ѿ�����Ʊߡ�\n"BLK"��һ���������䲻������ڽ��䣬�и�СС������¶������ţ����������þ��꣬�����޲����Ѿ�ҡҡ��׹��\n"NOR);
	me->set_temp("annie/xiangsi_bookcase",0);
	me->set_temp("annie/xiangsi_bookcase2",1);
	return " ";
}

int do_patch(string arg)
{
	object me = this_player(),patch;
	if (!me->query_temp("annie/xiangsi_bookcase2"))
		return 0;
	patch=present(arg,me);
	if (!patch)
		return 0;
	if (query("no_book"))
		return 0;
	if (crypt(""+patch->query_weight(),"VUL0P7ezMvL7o") != "VUL0P7ezMvL7o")
		return 0;
	tell_object(me,"��������ӣ���"+patch->name(1)+"���������\n");
	set("no_book",1);
	destruct(patch);
	if (random(3) > 0)
	{
		tell_object(me,"����֮�����ĵ����ϵĳ���ֱ�����ӣ�����Ŀ����Լ��ĳ�Ʒ��\n");
		return 1;
	}
	tell_object(me,"������䣬һ�����Ƶ�С��ӹ��������£�������Ļ��С�\n");
	patch=new(__DIR__"obj/paper");
	patch->move(me);
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


