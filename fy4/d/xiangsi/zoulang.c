// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();
string look_stone2();

void create()
{
	set("short", "��ľ����");
        set("long", @LONG
���ȷɼ���ɽ��֮�䣬��ԭ��������ʮ�ɵļ���ɽͷ����һ�����ٰ�
�ɽ��ȣ��·����ն����������������ϣ���������ľ��������ů��չü����
֮�⣬ֻ�����ҿտգ��ƺ���ӿ���ڡ��������ϸ����������΢����ɽ��
���ȶ�����ֻ�����ĳ����������ɰ
LONG
        );
	set("objects", ([
//		__DIR__"obj/rock4" : 1,
	]));
	set("exits",([
  		"east" : __DIR__"haoyue",
  		"south" : __DIR__"hanquan",
	]) );
	set("item_desc", ([
		"����": (: look_stone :),
		"�׹�": (: look_stone2 :),
	]) );

	set("indoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

string look_stone()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 2)
		return "�ľ�̼ܵ����ȣ�����ȥ������ů��\n";
	tell_object(me,"���ȵĽ���������һ��СС��צӡ������ɢɢ�Ļ��м���СС�İ׹ǡ�\n");
	me->set_temp("annie/xiangsi_master",3);
	return " ";
}

string look_stone2()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 3)
		return "��Ҫ��ʲ�᣿\n";
	tell_object(me,"��������İ׹�ͷ��\n");
	return " ";
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


