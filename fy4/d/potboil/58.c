#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"������"NOR);
	set("long", @LONG
�����´��ڰ�ɽ���ȵľ�ͷ����ɽ��������ɪ���������һ�����š�ÿ��
һ��������ڣ������µķ����Ǳ�ú�����䣬������ҹ�غ�Х�ţ��ƺ�Ҫ��
ȥ��������ϲд��һ˿ů�⡣
LONG
        );
	set("exits",([
//  		"north" : __DIR__"57",
  		"southdown" : __DIR__"57",
//  		"west" : __DIR__"57",
//  		"east" : __DIR__"57",
	]) );

	set("objects", ([
	__DIR__"npc/ye" : 1,
					]) );

	set("coor/x",50);
	set("coor/y",80);
	set("coor/z",20);
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
