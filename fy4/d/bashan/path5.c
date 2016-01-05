#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽС��");
        set("long", @LONG
ǰ���ǲݴԺ���ľ�������Ƿǳ�ïʢ����ͩľ��С·���Գ����˸�ɫ˵����
���ֵ����޵Ļ���������յ���ͩ���£���᫲�ƽ����С·ӳ��һ��ɭɭȻ�ĸ�
������ͩ��֦Ҷ��ïʢ����ȫ�ڱ�����ͷ������գ�ʹ·������һƬŨ�صĺڰ���
���ԲԲ��С������Ȼ�ڵ��ϳ�Ƭ�ĳ��֣���Ѹ�ٵ���ʧ������֦Ҷ�ķ�϶��©
�µĹ��ߡ�
LONG
        );
	set("exits",([
  		"east" : __DIR__"path4",
  		"west" : __DIR__"path6",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-90);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

int init()
{
	object room;
	if (!query("wall"))
	{
		set("wall",1);
		new(__DIR__"npc/wall")->move(this_object());
	}
}

int valid_leave(object me, string dir)
{
	object room;
	if (userp(me))
	{
		if (!query("one"))
			set("one",me);
		else if (query("one") != me)
		{
			if (!room=find_object(__DIR__"hall"))
				room=load_object(__DIR__"hall");
			if (!room->query("done"))
			{
				room->set("interrupted",1);
				room->do_ics(me,2);
				return notify_fail(" ");
			}
		}
	}

	if (present("wall of blossoms",this_object()) && dir == "west")
		return notify_fail("�������ĵ�·��һ�»�ǽ�赲ס�ˡ�\n");
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
