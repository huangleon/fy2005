#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"��ѩ��"NOR);
	set("long", @LONG
����ħ�̵��Ĵ���˾��ԭ�������˳�������Ū��֮�������м�����׵�
��񱣬�����������������ջ���ڴ˴���ǧ�겻��֮��ѩ�����¾ӣ��˺�ÿһ
λ��˾�ɾ���ס�ڴˣ��ྡ�Ա��и�����ѩ���ߵĹŷ硣
LONG
        );
	set("exits",([
		"eastdown" : __DIR__"65",
	]) );

	set("objects", ([	// * WATER RESOURCE HERE.
	__DIR__"npc/qu" : 1,
					]) );

  	set("coor/x",50);
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
