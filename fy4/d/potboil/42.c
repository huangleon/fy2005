#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"Ǭ����"NOR);
	set("long", @LONG
��Ⱥɽ�������������������һ������֪���Ļ����������Ρ�뿪ʢ
��¥�������Իͣ�������ǧ��֮��������Ƹǣ����̺�̺������������
����Ⱦ��Ǻ���ѷɫ��
LONG
        );
	set("exits",([
		"northup" : __DIR__"43",
		"eastup" : __DIR__"52",
		"southdown" : __DIR__"41",
	]) );

	set("objects", ([
	__DIR__"npc/wei" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",-10);
	set("indoors", "potboil");
	setup();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
