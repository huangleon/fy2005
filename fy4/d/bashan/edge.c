#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ָǱ�Ե");
        set("long", @LONG
����ǧ����࣬�������뿪����Ƭ����ͷ��Ŀѣ�İ�ɽ���֡���ǰ��ȥ��һ��
�������ľ�����Ŷ��µ�ɽͷ����������·��ֻ�м�ϥ��ݣ�����һ�ò����ľ��
������һ�ڳ���������ȴ����Щ����������Խ����Ƭ����ƽ����ɽͷ��ǰ���ֵȴ�
��ʲô���������
LONG
        );
	set("exits",([
//  		"down" : __DIR__"maze3/exit",
  		"north" : __DIR__"edge2",
	]) );
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",40);
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
