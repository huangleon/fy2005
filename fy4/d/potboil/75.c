#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"��Ȫ��"NOR);
	set("long", @LONG

   ��           ��
            ��

                             ����
      ��      ��     ��     ������  
   ��     ��     ��    ��  �������� ��
      ��    ���𡨡�     ������������
  ��         /��\/��\   ��    ��  ��
        �n�T�̡̡̡̨T�n�T�n�T�n�T�n�T�n

LONG
        );
	set("exits",([
		"southup" : __DIR__"74",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",70);
	set("coor/y",50);
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
