#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"��ħ��"NOR);
	set("long", @LONG

Զɽ��Ϧ�����ɴ��̱�Ϊ��ң�Ȫˮ�������Ҳ�������ˡ������Ϣȴ
���ҷ�����Ϊ�ʻ��Ϳ���ɽ���ϣ���ɫ�ͷ׵��ʻ������ĵ�ӵ����һ�����ڣ�
��������͡���̧��ͷ������ߵ�ɽ����ȴ��Ȼ������Ѫ��Ĵ��֣�

[1;31m�������������������ء�������ħ����������[2;37;0m


LONG
        );
	set("exits",([
		"northup" : __DIR__"42",
		"southdown" : "/d/bashan/jadegate",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",40);
	set("coor/y",10);
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
