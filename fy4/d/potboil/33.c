#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"���Ͻ�"NOR);
	set("long", @LONG
���°׷��ᣬҹ����ˮ��һ��һ��ĺ��⽥���ؽ����Ŵ��ķ�϶��������
�����Ͻǵ�С��¥�У�����������ϣ��������£����ḧ������ļ�������¥
��ǳǳ�ĳ������޶˾��������˵Ĺ��ġ�
LONG
        );
	set("exits",([
		"north" : __DIR__"34",
		"east" : __DIR__"43",
	]) );

	set("objects", ([
	__DIR__"npc/lan" : 1,
					]) );

  	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
	set("indoors", "potboil");
	setup();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
