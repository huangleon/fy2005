// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
��լ������ţ����ϲ豭��С��ͭ������ ���⣬�Ŷ��Ҷ�д�š������ھ֡�
�ĸ�������֣�������顰�ܺš�����С�֡����Ŵ����ų��ʣ������Ű�����
װ�����ĺ��ӣ����������ͦ���Գ�һ��Ӣ��֮����
LONG
        );
	set("exits",([
  		"north" : __DIR__"fuweibiaoju1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}