#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ����");
        set("long", @LONG
�ڶ�ľ�ŵ���һ�ߣ���ϥ�ĻĲ����ܱ�����ɽͷ���ݻ�����̽�֯��ʱ����ɫ
�ʡ��ݴ�������ԼԼ��һ��խС�����ƣ��������˲ȵ����ĺۼ�����·���ű�����
���ȥ������Խ����ǳ��
LONG
        );
	set("exits",([
  		"northdown" : __DIR__"hole1",
  		"south" : __DIR__"edge",
	]) );
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",200);
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
