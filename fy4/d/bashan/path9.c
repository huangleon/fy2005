#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽС��");
        set("long", @LONG
ǰ���ǲݴԺ���ľ�������Ƿǳ�ïʢ����ͩľ��С·���Գ����˸�ɫ˵����
���ֵ����޵Ļ��ݡ�������յ���ͩ���£���᫲�ƽ����С·ӳ��һ��ɭɭȻ��
�о�����ͩ��֦Ҷ��ïʢ����ȫ�ڱ�����ͷ������գ�ʹ·������һƬŨ�صĺڰ�
�У����ԲԲ��С������Ȼ�ڵ��ϳ�Ƭ�ĳ��֣���Ѹ�ٵ���ʧ������֦Ҷ�ķ�϶
��©�µĹ��ߡ�������һƬï�ܵ���ľ��������ľ������뿪����Σ���ķ������
��ɽ��
LONG
        );
	set("exits",([
  		"south" : __DIR__"path8",
  		"north" : "/d/xiangsi/shuangtian",
	]) );
	set("item_desc", ([
		"north": "������һƬï�ܵ����֡�\n",
		"����": "�������ƺ���ʲô�����ŵ���̹⣮����\n",
		"flower": "�������ƺ���ʲô�����ŵ���̹⣮����\n",
		"grass": "�������ƺ���ʲô�����ŵ���̹⣮����\n",
		"��": "�������ƺ���ʲô�����ŵ���̹⣮����\n",
		"��": "�������ƺ���ʲô�����ŵ���̹⣮����\n",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-110);
	set("coor/y",250);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	if (userp(me))
	{
		if (!room=find_object(__DIR__"hall"))
			room=load_object(__DIR__"hall");
		if (!room->query("done"))
		{
			room->set("interrupted",1);
			room->do_ics(me,1);
			return notify_fail(" ");
		}
	}

	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
