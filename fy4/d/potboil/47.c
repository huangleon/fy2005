#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"������"NOR);
	set("long", @LONG


���������q����ߣߦ䩤�r 
������������=���n��=���� �ڣ��� 
�������q�T�ϨT�T�T�T�ϨT�r 
��������*��*��*��*��*��*�� 
����������*��*��*��*��* �� 
��������*��*��*��*��*��*�� 
�������t�T�T�T�T�T�T�T�T�s

�������ڵ�ʲô��������������
����������˯һ����

LONG
        );
	set("exits",([
  		"eastdown" : __DIR__"57",
	]) );

	set("objects", ([
	__DIR__"npc/hu" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",70);
	set("coor/z",20);
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
