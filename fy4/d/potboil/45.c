#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�Ϸ�ͥ"NOR);
	set("long", @LONG
�Ϸ�����������ָ���ء�����ʮ�ݼ����أ�����ɽ���ǣ�һ�����ɱ���
�������Ϸ磺�Ϸ�ͥ����¥ʮ������̨�Ų㣬������������̳��ϻ����ڵľ�
��֮�ء�
LONG
        );
	set("exits",([
		"northdown" : __DIR__"46",


	]) );

	set("objects", ([
	__DIR__"npc/bu" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",50);
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
