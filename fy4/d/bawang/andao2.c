#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
����һ�����������Ƕ���ɽ�ϵ�ǿ���ǰѲƱ��Ӷ��������������Ľݾ�������
��Ȼ�ܾ��Ѿ�û�������ˣ�������ʪ�Ŀ���������ָ���ĳ������̼����㼸��
���۾�����������������ͷ��һ���ƺ������ƶ���ľǽ��
LONG);

	set("type","street");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("exits",([
		"northdown":__DIR__"andao1",
		"eastup":__DIR__"juyiting",
	]) );

	setup();
	create_door("eastup", "wall","ľǽ", "westdown", DOOR_CLOSED);
}
