#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
        set("long", @LONG
�ڶ�ľ�ŵ���һ�ߣ���ϥ�ĻĲ����ܱ�����ɽͷ���ݻ�����̽�֯��ʱ����ɫ
�ʡ��ݴ�������ԼԼ��һ��խС�����ƣ��������˲ȵ����ĺۼ�����·���ű�����
���ȥ������Խ����ǳ��
LONG
        );
	set("exits",([
  		"northdown" : __DIR__"hole2",
  		"southup" : __DIR__"edge2",
	]) );
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",100);
	set("coor/z",190);
	set("outdoors", "bashan");
	setup();
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
