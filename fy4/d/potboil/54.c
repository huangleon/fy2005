#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"�ū\̨"NOR);
	set("long", @LONG
��ɽΪ�ū\����ˮΪɺ�����ū\̨���ɽ������һ�н��������ͬ��
��ѡ�ĵ��ֹ��������ݻ����չ���������¥���ܣ����������ݶ�������������
�����Ϻ��������̡�
LONG
        );
	set("exits",([
		"southdown" : __DIR__"53",
	]) );

	set("objects", ([
	__DIR__"npc/qian" : 1,
					]) );

  	set("coor/x",50);
	set("coor/y",40);
	set("coor/z",10);
	set("outdoors", "potboil");
	setup();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
