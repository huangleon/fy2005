#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����ʯ"NOR);
	set("long", @LONG

	
[1;37m�������������X�Y
�������������U�t�r
[1;36m�������������U���t�r
�������������U�����t�r
[1;34m�������������U��������
�������������^�k�k�k�_
[2;37;0m

��������֪ǰ���£� ����ʯ�������ϣ� 
����֪��������˭�� �������������¡�

LONG
        );
	set("exits",([
		"westup" : __DIR__"74",
	]) );

	set("objects", ([
	__DIR__"npc/ding" : 1,
					]) );

  	set("coor/x",80);
	set("coor/y",40);
	set("coor/z",-20);
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
