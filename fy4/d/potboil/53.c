#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"���⼯"NOR);
	set("long", @LONG
��ɽ�����в��������ħ�����˶��޷��Ը����㣬���Ǳ����˶���������
�ⷷ���̻���������˵����ֻ���������ã�Ȼ���ڵ����޳���ʹ�ô˵ط��۵�
�������º�������Ʒ��
LONG
        );
	set("exits",([
		"west" : __DIR__"43",
		"east" : __DIR__"63",
		"northup" : __DIR__"54",
	]) );

	set("objects", ([
	__DIR__"npc/mu" : 1,
	__DIR__"npc/lu" : 1,
					]) );

  	set("coor/x",50);
	set("coor/y",30);
	set("coor/z",0);
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
