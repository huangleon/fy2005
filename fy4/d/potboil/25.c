#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"����ջ"NOR);
	set("long", @LONG
ħ�̸���ʱ�ڵĵ�������в�һ��Ȼʼ���������·���˾�����賤�ϻ���
�໥�ƺ⣻����ջͥԺ�����ļ����ұ�����˾֮�д�˾�ԡ���˾�ܡ���˾����
��˾���ڶ���ס����
LONG
        );
	set("exits",([
  		"westup" : __DIR__"15",
		"eastdown" : __DIR__"35",
		"southup" : __DIR__"24",
	]) );

	set("objects", ([
	__DIR__"npc/jiang" : 1,
					]) );

  	set("coor/x",20);
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
