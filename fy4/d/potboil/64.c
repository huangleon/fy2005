#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"������"NOR);
	set("long", @LONG
���������ڰ�ɽ�����Զ������������쪣�����Ϯ�ˣ�����ɽ���ϵı���
����㵹�����£��������֣�£������������խ����ڣ�ʱʱ����Զɽ��Х��
�����˼���������
LONG
        );
	set("exits",([
		"north" : __DIR__"65",
		"south" : __DIR__"63",
		"eastdown" : __DIR__"74",
	]) );

	set("objects", ([
	__DIR__"npc/shi" : 1,
					]) );

  	set("coor/x",60);
	set("coor/y",40);
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
